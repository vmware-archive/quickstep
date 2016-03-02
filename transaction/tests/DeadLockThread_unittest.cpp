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

#include <thread>  // NOLINT(build/c++11)
#include <vector>

int main() {
  using namespace quickstep::transaction;  // NOLINT(build/namespaces)
  LockTable lock_table;
  DeadLockDetectorStatus status = DeadLockDetectorStatus::kNOT_READY;
  std::vector<TransactionId> victims;
  DeadLockThread deadlock_thread(&lock_table, &status, &victims);
  deadlock_thread.start();

  std::thread t([&status]() {
      while (true) {
        while (status == DeadLockDetectorStatus::kNOT_READY) {
        }
        // Process it.
        status = DeadLockDetectorStatus::kNOT_READY;
      }
    });

  deadlock_thread.join();
  t.join();
}
