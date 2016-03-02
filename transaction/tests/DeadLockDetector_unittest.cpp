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

#include "transaction/DeadLockDetector.hpp"

#include <vector>

#include "gtest/gtest.h"

namespace quickstep {

namespace transaction {

TEST(DeadLockDetector, DeadLockExists) {
  TransactionId tid1 = TransactionId(1);
  TransactionId tid2 = TransactionId(2);

  LockTable lock_table;
  lock_table.putLock(tid1, ResourceId(1, 1, 2), AccessMode(AccessModeType::kX_LOCK));

  lock_table.putLock(tid2, ResourceId(1, 1, 1), AccessMode(AccessModeType::kX_LOCK));

  lock_table.putLock(tid2, ResourceId(1, 1, 2), AccessMode(AccessModeType::kX_LOCK));

  lock_table.putLock(tid1, ResourceId(1, 1, 1), AccessMode(AccessModeType::kX_LOCK));

  DeadLockDetector dead_lock_detector(&lock_table);

  std::vector<TransactionId> victims = dead_lock_detector.getAllVictims();

  EXPECT_EQ(1, victims.size());
}

}  // namespace transaction

}  // namespace quickstep
