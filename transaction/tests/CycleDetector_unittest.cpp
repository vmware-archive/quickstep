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

#include "transaction/CycleDetector.hpp"

#include <cstdint>
#include <memory>
#include <unordered_set>
#include <utility>
#include <vector>

#include "transaction/DirectedGraph.hpp"
#include "transaction/Transaction.hpp"

#include "gtest/gtest.h"

namespace quickstep {
namespace transaction {

class CycleDetectorTest : public testing::Test {
 protected:
  const std::uint64_t kNumberOfTransactions = 12;

  CycleDetectorTest()
      : wait_for_graph_(std::make_unique<DirectedGraph>()) {
  }

  virtual void SetUp() {
    std::vector<transaction_id> transactions(kNumberOfTransactions);
    for (std::uint64_t i = 0; i < kNumberOfTransactions; ++i) {
      transactions.push_back(transaction_id(i));
    }

    std::vector<DirectedGraph::node_id> node_ids;
    for (std::uint64_t i = 0; i < kNumberOfTransactions; ++i) {
      node_ids.push_back(wait_for_graph_->addNodeUnchecked(transactions[i]));
    }
  }

  void initializeCycleDetector() {
    for (const auto &edge : edges_) {
      wait_for_graph_->addEdgeUnchecked(edge.first, edge.second);
    }

    cycle_detector_.reset(new CycleDetector(wait_for_graph_.get()));
  }

  void checkVictims(
      const std::unordered_set<DirectedGraph::node_id> &expected_victims) {
    const std::vector<DirectedGraph::node_id> victims =
        cycle_detector_->chooseVictimsToBreakCycle();
    ASSERT_EQ(expected_victims.size(), victims.size());

    for (const auto victim : victims) {
      EXPECT_EQ(expected_victims.count(victim), 1);
    }
  }

  std::vector<std::pair<DirectedGraph::node_id, DirectedGraph::node_id>> edges_;
  std::unique_ptr<DirectedGraph> wait_for_graph_;
  std::unique_ptr<CycleDetector> cycle_detector_;
};

TEST_F(CycleDetectorTest, BreakCycle) {
  // This edge contains lots of cycles of degree 1, 2 and 3.
  edges_ = {{0, 1},
            {1, 2}, {1, 3}, {1, 4},
            {2, 5},
            {3, 4}, {3, 6},
            {4, 1}, {4, 5}, {4, 6},
            {5, 2}, {5, 7},
            {6, 7}, {6, 9},
            {7, 6},
            {8, 6},
            {9, 8}, {9, 10},
            {10, 11},
            {11, 9}};

  initializeCycleDetector();

  std::unordered_set<DirectedGraph::node_id> expected_victims
      = {4, 5, 7, 8, 9, 10, 11};

  checkVictims(expected_victims);
}

TEST_F(CycleDetectorTest, BreakCycleSimple) {
  edges_ = {{0, 1},
            {1, 0}};

  initializeCycleDetector();

  std::unordered_set<DirectedGraph::node_id> expected_victims = {1};

  checkVictims(expected_victims);
}

}  // namespace transaction
}  // namespace quickstep
