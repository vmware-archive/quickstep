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

#include <atomic>
#include <memory>
#include <vector>

#include "transaction/DirectedGraph.hpp"
#include "transaction/LockTable.hpp"
#include "transaction/Transaction.hpp"

#include "gtest/gtest.h"

namespace quickstep {
namespace transaction {

class DeadLockDetectorTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    lock_table_ = std::make_unique<LockTable>();
    status_.store(DeadLockDetectorStatus::kDone);
  }

  std::unique_ptr<LockTable> lock_table_;
  std::atomic<DeadLockDetectorStatus> status_;
  std::vector<DirectedGraph::node_id> victims_;
};

TEST_F(DeadLockDetectorTest, SimpleCycle) {
  lock_table_->putLock(transaction_id(1),
                       ResourceId(4, 5),
                       AccessMode(AccessModeType::kXLock));

  lock_table_->putLock(transaction_id(2),
                       ResourceId(1, 2),
                       AccessMode(AccessModeType::kXLock));

  lock_table_->putLock(transaction_id(1),
                       ResourceId(1, 2),
                       AccessMode(AccessModeType::kXLock));

  lock_table_->putLock(transaction_id(2),
                       ResourceId(4, 5),
                       AccessMode(AccessModeType::kXLock));

  DeadLockDetector dl_detector(lock_table_.get(), &status_, &victims_);
  status_.store(DeadLockDetectorStatus::kNotReady);

  dl_detector.start();

  while (status_.load() == DeadLockDetectorStatus::kNotReady) {
  }

  status_.store(DeadLockDetectorStatus::kQuit);
  dl_detector.join();
  ASSERT_EQ(1u, victims_.size());
}

}  // namespace transaction
}  // namespace quickstep
