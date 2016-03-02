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

#ifndef QUICKSTEP_TRANSACTION_LOCK_MANAGER_HPP_
#define QUICKSTEP_TRANSACTION_LOCK_MANAGER_HPP_

#include <vector>

#include "threading/Mutex.hpp"
#include "transaction/AccessMode.hpp"
#include "transaction/DeadLockDetector.hpp"
#include "transaction/DeadLockThread.hpp"
#include "transaction/LockTable.hpp"
#include "transaction/ResourceId.hpp"
#include "transaction/Transaction.hpp"
#include "transaction/TransactionTable.hpp"

namespace quickstep {

namespace transaction {

/** \addtogroup Transaction
 *  @{
 **/

/**
 * @brief Class for centralized location of acquisition and releasing
 *        of resource locks.
 **/
class LockManager {
 public:
  LockManager();

  /**
   * @brief Destructor for Lock Manager. It handles the thread
   *        joins that it owns. 
   **/
  ~LockManager();

  /**
   * @brief Acquires the lock on resource with specified access mode.
   *
   * @param tid Id of the transaction which the resource lock is acquired for.
   * @param rid Id of the resource on which the resource lock is acquired.
   * @param access_mode Permissible access mode on resource.
   **/
  bool acquireLock(TransactionId tid,
                   const ResourceId &rid,
                   AccessMode access_mode);

  /**
   * @brief Releases all locks hold by the transaction.
   *
   * @param tid Id of the transaction whose locks will be released.
   **/
  bool releaseAllLocks(TransactionId tid);

  /**
   * @brief Release the locks acquired by the transactions contained
   *        in victim buffer to break the deadlock.
   **/
  void killVictims();

 private:
  bool acquireLockInternal(TransactionId tid,
                           const ResourceId &rid,
                           AccessMode access_mode);

  std::unique_ptr<LockTable> lock_table_;
  std::unique_ptr<TransactionTable> transaction_table_;
  std::unique_ptr<DeadLockThread> deadlock_detector_thread_;
  std::unique_ptr<DeadLockDetectorStatus> detector_status_;
  std::unique_ptr<std::vector<TransactionId>> victim_result_;
};

/** @} */

}  // namespace transaction

}  // namespace quickstep
#endif
