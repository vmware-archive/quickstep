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

#include "transaction/DeadLockThread.hpp"

#include <vector>

namespace quickstep {

namespace transaction {

DeadLockThread::DeadLockThread(LockTable *lock_table,
                               DeadLockDetectorStatus *detector_status,
                               std::vector<TransactionId> *victim_result)
  : lock_table_(lock_table)
  , detector_status_(detector_status)
  , victim_result_(victim_result)
  , dead_lock_detector_(nullptr) {
}

// Infinite loop for thread logic:
// 1-) Reinitiate DeadLockDetector.
// 2-) Run deadlock detection alogrithm on lock table.
// 3-) Pass results to the victim result buffer.
// 4-) Signal status with kDONE.
// 5-) Sleep for 5 seconds.
// 6-) Do not go to the beginning of the loop if status
//     is still kDONE.
void DeadLockThread::run() {
  while (true) {
    dead_lock_detector_.release();
    dead_lock_detector_ = std::make_unique<DeadLockDetector>(lock_table_);

    std::cout << "DeadLockDetector detection starts.\n";

    std::vector<TransactionId> victims = dead_lock_detector_->getAllVictims();

    std::cout << "Victim size: " + std::to_string(victims.size()) + "\n";

    *victim_result_ = std::move(victims);
    *detector_status_ = DeadLockDetectorStatus::kDONE;

    std::cout << "DeadLockDetector detection ends.\n";

    std::this_thread::sleep_for(std::chrono::seconds(5));
    while (*detector_status_ == DeadLockDetectorStatus::kDONE) {
    }
  }
}

}  // namespace transaction

}  // namespace quickstep
