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

#include "transaction/LockManagerThread.hpp"

#include "transaction/LockManager.hpp"

namespace quickstep {

namespace transaction {

LockManagerThread::LockManagerThread(ThreadSafeQueue<LockRequest> *incoming_requests,
                                     ThreadSafeQueue<LockRequest> *permitted_requests)
  : lock_manager_(std::make_unique<LockManager>())
  , incoming_requests_(incoming_requests)
  , permitted_requests_(permitted_requests)
  , inner_pending_requests_() {
}

void LockManagerThread::run() {
  constexpr std::uint64_t max_try_incoming = 100000;
  constexpr std::uint64_t max_try_inner = 60000;
  while (true) {
    for (std::uint64_t tries = 0; tries < max_try_incoming; ++tries) {
      if (!incoming_requests_->empty()) {
        LockRequest request = incoming_requests_->popOne();
        if (request.getRequestType() == RequestType::kRELEASE_LOCKS) {
          bool result
               = lock_manager_->releaseAllLocks(request.getTransactionId());
          if (!result) {
            FATAL_ERROR("It should not arrive at this point!!");
          }
        } else {
          bool result = lock_manager_->acquireLock(request.getTransactionId(),
                                                   request.getResourceId(),
                                                   request.getAccessMode());
          if (!result) {
            std::cout << "Transaction "
                + std::to_string(request.getTransactionId())
                + " waiting " + request.getResourceId().toString() + "\n";
            inner_pending_requests_.push(request);
          } else {
            std::cout << "Transaction "
                + std::to_string(request.getTransactionId())
                + " acquired " + request.getResourceId().toString() + "\n";
            permitted_requests_->push(request);
          }
        }
      }
    }
    for (std::uint64_t tries = 0; tries < max_try_inner; ++tries) {
      if (!inner_pending_requests_.empty()) {
        LockRequest request = inner_pending_requests_.front();

        bool result = lock_manager_->acquireLock(request.getTransactionId(),
                                                 request.getResourceId(),
                                                 request.getAccessMode());
        if (result) {
          inner_pending_requests_.pop();
          permitted_requests_->push(request);
        }
      }
    }
    std::cout << "LMT: Killing victims\n";
    lock_manager_->killVictims();
  }
}

}  // namespace transaction

}  // namespace quickstep
