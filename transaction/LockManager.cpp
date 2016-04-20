/**
 *   Copyright 2016, Quickstep Research Group, Computer Sciences Department,
 *     University of Wisconsin—Madison.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 **/

#include "transaction/LockManager.hpp"

#include <stack>
#include <utility>
#include <vector>

#include "threading/Mutex.hpp"
#include "threading/Thread.hpp"
#include "transaction/AccessMode.hpp"
#include "transaction/DeadLockDetector.hpp"
#include "transaction/LockRequest.hpp"
#include "transaction/LockTable.hpp"
#include "transaction/ResourceId.hpp"
#include "transaction/Transaction.hpp"
#include "transaction/TransactionTable.hpp"

#include "glog/logging.h"

namespace quickstep {
namespace transaction {

LockManager::LockManager(ThreadSafeQueue<LockRequest> *incoming_requests,
                         ThreadSafeQueue<LockRequest> *permitted_requests)
    : lock_table_(std::make_unique<LockTable>()),
      transaction_table_(std::make_unique<TransactionTable>()),
      detector_status_(DeadLockDetectorStatus::kNotReady),
      victim_result_(),
      deadlock_detector_(std::make_unique<DeadLockDetector>(lock_table_.get(),
                                                            &detector_status_,
                                                            &victim_result_)),
      incoming_requests_(*incoming_requests),
      permitted_requests_(*permitted_requests),
      inner_pending_requests_() {
}

LockManager::~LockManager() {
  deadlock_detector_->join();
}

void LockManager::run() {
  deadlock_detector_->start();

  constexpr std::uint64_t max_try_incoming = 10000;
  constexpr std::uint64_t max_try_inner = 6000;

  while (true) {
    for (std::uint64_t tries = 0; tries < max_try_incoming; ++tries) {
      if (!incoming_requests_.empty()) {
        LockRequest request = incoming_requests_.popOne();
        if (request.getRequestType() == RequestType::kReleaseLocks) {
          bool result = releaseAllLocks(request.getTransactionId());
          if (!result) {
            LOG(FATAL) << "Unexpected condition occured.";
          }
        } else {
          bool result = acquireLock(request.getTransactionId(),
                                    request.getResourceId(),
                                    request.getAccessMode());
          if (!result) {
            LOG(INFO) << "Transaction "
                         + std::to_string(request.getTransactionId())
                         + " is waiting " + request.getResourceId().toString();

            inner_pending_requests_.push(request);
          } else {
            LOG(INFO) << "Transaction "
                         + std::to_string(request.getTransactionId())
                         + " acquired " + request.getResourceId().toString();

            permitted_requests_.push(request);
          }
        }
      }
    }
    for (std::uint64_t tries = 0; tries < max_try_inner; ++tries) {
      if (!inner_pending_requests_.empty()) {
        LockRequest request = inner_pending_requests_.front();

        bool result = acquireLock(request.getTransactionId(),
                                  request.getResourceId(),
                                  request.getAccessMode());
        if (result) {
          inner_pending_requests_.pop();
          permitted_requests_.push(request);
        }
      }
    }

    killVictims();
  }
}

bool LockManager::acquireLock(const transaction_id tid,
                              const ResourceId &rid,
                              const AccessMode access_mode) {
  std::stack<std::pair<ResourceId, AccessMode>> stack;
  ResourceId current_rid = rid;
  AccessMode current_access_mode = access_mode;
  stack.push(std::make_pair(current_rid, current_access_mode));

  while (current_rid.hasParent()) {
    current_rid = current_rid.getParentResourceId();
    current_access_mode =
      (current_access_mode.isShareLock() ||
       current_access_mode.isIntentionShareLock())
      ? AccessMode(AccessModeType::kIsLock)
      : AccessMode(AccessModeType::kIxLock);

    stack.push(std::make_pair(current_rid, current_access_mode));
  }

  lock_table_->latchExclusive();

  while (!stack.empty()) {
    std::pair<ResourceId, AccessMode> pair_to_pick = stack.top();
    ResourceId rid_to_pick = pair_to_pick.first;
    AccessMode access_mode_to_pick = pair_to_pick.second;

    bool result = acquireLockInternal(tid,
                                      rid_to_pick,
                                      access_mode_to_pick);
    if (!result) {
      lock_table_->unlatchExclusive();
      return false;
    }
    stack.pop();
  }
  lock_table_->unlatchExclusive();
  return true;
}

bool LockManager::releaseAllLocks(const transaction_id tid) {
  std::vector<ResourceId> related_rids
      = transaction_table_->getResourceIdList(tid);
  TransactionTableResult transaction_deleted
      = transaction_table_->deleteTransaction(tid);
  if (transaction_deleted
          == TransactionTableResult::kTransactionDeleteError) {
    FATAL_ERROR("In LockManager.releaseAllLocks"
                " transaction could not be deleted!");
  }

  lock_table_->latchExclusive();

  for (std::vector<ResourceId>::const_iterator it = related_rids.begin();
       it != related_rids.end();
       ++it) {
    LockTableResult lock_deleted = lock_table_->deleteLock(tid, *it);

    std::cout << "Transaction " + std::to_string(tid)
      + " released lock:" + it->toString() + "\n";

    if (lock_deleted == LockTableResult::kDelError) {
      FATAL_ERROR("In LockManager.releaseAllLock "
                  "lock could not be deleted from LockTable");
    }
  }

  lock_table_->unlatchExclusive();
  return true;
}

// If not blocked return true
// if block return false
bool LockManager::acquireLockInternal(const transaction_id tid,
                                      const ResourceId &rid,
                                      const AccessMode access_mode) {
  LockTableResult l_result = lock_table_->putLock(tid, rid, access_mode);
  if (l_result == LockTableResult::kPutError) {
    LOG(FATAL) << "Unexpected result in LockManager.acquireLockInternal";
  }

  if (l_result == LockTableResult::kAlreadyInOwned) {
    return true;
  } else if (l_result == LockTableResult::kPlacedInOwned) {
    TransactionTableResult t_result
        = transaction_table_->putOwnEntry(tid, rid, access_mode);
    if (t_result != TransactionTableResult::kPlacedInOwned) {
      LOG(FATAL) << "Unexpected result in LockManager.acquireLockInternal: "
                    "Mismatch of table results (No.1).";
    }
    return true;
  } else if (l_result == LockTableResult::kAlreadyInPending) {
    return false;
  } else if (l_result == LockTableResult::kPlacedInPending) {
    TransactionTableResult t_result =
      transaction_table_->putPendingEntry(tid, rid, access_mode);
    if (t_result != TransactionTableResult::kPlacedInPending) {
      LOG(FATAL) << "Unexpected result in LockManager.acquireLockInternal: "
                    "Mismatch of table results (No.2).";
    }
    return false;
  }
  return false;
}

void LockManager::killVictims() {
  // TODO(Hakan): Find a method to latch this function
  //              (it cannot because it calls releaseLocks)
  if (detector_status_.load() == DeadLockDetectorStatus::kDone) {
    for (std::vector<transaction_id>::const_iterator iter
             = victim_result_.begin();
         iter != victim_result_.end();
         ++iter) {
      transaction_id tid = *iter;
      releaseAllLocks(tid);
      // TODO(Hakan): Find a way to kill transaction, so that requests with this
      //              tid should be ignored.
      LOG(INFO) << "Killed transaction " + std::to_string(tid);
    }
  }

  victim_result_.clear();
  detector_status_.store(DeadLockDetectorStatus::kNotReady);
}

}  // namespace transaction
}  // namespace quickstep
