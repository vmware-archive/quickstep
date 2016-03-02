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

#ifndef QUICKSTEP_TRANSACTION_LOCK_MANAGER_THREAD_HPP_
#define QUICKSTEP_TRANSACTION_LOCK_MANAGER_THREAD_HPP_

#include <queue>

#include "threading/Thread.hpp"
#include "transaction/LockManager.hpp"
#include "transaction/LockRequest.hpp"
#include "utility/ThreadSafeQueue.hpp"

namespace quickstep {

namespace transaction {

/** \addtogroup Transaction
 *  @{
 */

/**
 * @brief Class for the thread runs on LockManager.
 */
class LockManagerThread : public Thread {
 public:
  /**
   * @brief Constructor for LockManagerThread. Initial point
   *        for Transaction module.
   *
   * @param incoming_requests Pointer to queue for incoming lock requests.
   * @param permitted_requests Pointer to the queue for outputting permitted
   *        lock requests.
   */
  LockManagerThread(ThreadSafeQueue<LockRequest> *incoming_requests,
                    ThreadSafeQueue<LockRequest> *permitted_requests);

  /**
   * @brief Main logic loop for LockManagerThread.
   */
  void run() override;

 private:
  // Owner pointer to lock mananager.
  std::unique_ptr<LockManager> lock_manager_;

  // Pointer to incoming buffer.
  ThreadSafeQueue<LockRequest> *incoming_requests_;

  // Pointer to output buffer.
  ThreadSafeQueue<LockRequest> *permitted_requests_;

  // Buffer for the requests popped from incoming but cannot
  // grant the lock for them.
  std::queue<LockRequest> inner_pending_requests_;
};

/** @} */

}  // namespace transaction

}  // namespace quickstep
#endif
