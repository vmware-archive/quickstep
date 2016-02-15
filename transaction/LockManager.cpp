#include "transaction/LockManager.hpp"

#include <stack>
#include <utility>


namespace quickstep {

LockManager::LockManager()
  : lock_table_(std::make_unique<LockTable>())
  , transaction_table_(std::make_unique<TransactionTable>())
  , deadlock_detector_thread_(nullptr)
  , detector_status_(std::make_unique<DeadLockDetectorStatus>(DeadLockDetectorStatus::kNOT_READY))
  , victim_result_(std::make_unique<std::vector<TransactionId>>()) {
  deadlock_detector_thread_ = std::make_unique<DeadLockThread>(lock_table_.get(),
							       detector_status_.get(),
							       victim_result_.get());
  deadlock_detector_thread_->start();
}

LockManager::~LockManager() {
  deadlock_detector_thread_->join();
}


bool LockManager::acquireLock(TransactionId tid,
			      const ResourceId &rid,
			      AccessMode access_mode) {
  //std::cout << "LM a\n";
  lock_table_->latchExclusive();
  //std::cout << "LM b\n";
  
  std::stack<std::pair<ResourceId, AccessMode>> stack;
  ResourceId current_rid = rid;
  AccessMode current_access_mode = access_mode;
  stack.push(std::make_pair(current_rid, current_access_mode));

  //std::cout << "LM c\n";
  while (current_rid.hasParent()) {
    //std::cout << current_rid.toString() + "\n";
    current_rid = current_rid.getParentResourceId();
    current_access_mode =
      (current_access_mode.isShareLock() ||
       current_access_mode.isIntentionShareLock())
      ? AccessMode::AccessModeType::kIS_LOCK
      : AccessMode::AccessModeType::kIX_LOCK;
    
    stack.push(std::make_pair(current_rid, current_access_mode));
  }
  //std::cout << "LM d\n";
  while (!stack.empty()) {
    std::pair<ResourceId, AccessMode> pair_to_pick = stack.top();
    ResourceId rid_to_pick = pair_to_pick.first;
    AccessMode access_mode_to_pick = pair_to_pick.second;
    //std::cout << "LM c\n";
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

bool LockManager::releaseAllLocks(TransactionId tid) {
  std::vector<ResourceId> related_rids = transaction_table_->getResourceIdList(tid);
  TransactionTableResult transaction_deleted = transaction_table_->deleteTransaction(tid);
  if (transaction_deleted == TransactionTableResult::kTRANSACTION_DELETE_ERROR) {
    FATAL_ERROR("In LockManager.releaseAllLocks, transaction could not be deleted!");
  }

  lock_table_->latchExclusive();
  
  for (std::vector<ResourceId>::const_iterator it = related_rids.begin();
       it != related_rids.end();
       ++it) {
    LockTableResult lock_deleted = lock_table_->deleteLock(tid, *it);
    std::cout << "Transaction " + std::to_string(tid)
      + " released lock:" + it->toString() + "\n";
    if (lock_deleted == LockTableResult::kDEL_ERROR) {
      FATAL_ERROR("In LockManager.releaseAllLock "
		  "lock could not be deleted from LockTable");
    }
  }

  lock_table_->unlatchExclusive();
  return true;
}

// If not blocked return true
// if block return false
bool LockManager::acquireLockInternal(TransactionId tid,
				      const ResourceId &rid,
				      AccessMode access_mode) {
  LockTableResult l_result = lock_table_->putLock(tid, rid, access_mode);
  if (l_result == LockTableResult::kPUT_ERROR) {
    FATAL_ERROR("Unexpected result in LockManager.acquireLockInternal");
  }
  
  if (l_result == LockTableResult::kALREADY_IN_OWNED) {
    return true;
  }
  else if (l_result == LockTableResult::kPLACED_IN_OWNED) {
    TransactionTableResult t_result = transaction_table_->putOwnEntry(tid, rid, access_mode);
    if (t_result != TransactionTableResult::kPLACED_IN_OWNED) {
      FATAL_ERROR("Unexpected result in LockManager.acquireLockInternal: "
		  "Mismatch of table results No1.");
    }
    return true;
  }
  else if (l_result == LockTableResult::kALREADY_IN_PENDING) {
    return false;
  }
  else if (l_result == LockTableResult::kPLACED_IN_PENDING) {
    TransactionTableResult t_result =
      transaction_table_->putPendingEntry(tid, rid, access_mode);
    if (t_result != TransactionTableResult::kPLACED_IN_PENDING) {
      FATAL_ERROR("Unexpected result in LockManager.acquireLockInternal: "
		  "Mismatch of table results No2.");
    }
    return false;
  }
  return false;
}

void LockManager::killVictims() {
  //TODO(Hakan): Find a method to latch this function (it cannot because it calls releaseLocks)
  
  if (*detector_status_ == DeadLockDetectorStatus::kDONE) {
    for (std::vector<TransactionId>::const_iterator iter = victim_result_->begin();
	 iter != victim_result_->end();
	 ++iter) {
      TransactionId tid = *iter;
      releaseAllLocks(tid);
      std::cout << "Killed transaction " + std::to_string(tid) + "\n";
    }
  }

  victim_result_->clear();
  *detector_status_ = DeadLockDetectorStatus::kNOT_READY;
  
}

}

