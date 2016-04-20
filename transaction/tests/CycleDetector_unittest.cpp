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
#include <unordered_map>
#include <utility>
#include <vector>

#include "transaction/DirectedGraph.hpp"
#include "transaction/StronglyConnectedComponents.hpp"
#include "transaction/Transaction.hpp"

#include "gtest/gtest.h"

namespace quickstep {
namespace transaction {

class CycleDetectorTest : public testing::Test {
 protected:
  virtual void SetUp() {
    for (std::uint64_t i = 0; i < 12; ++i) {
      transactions_.push_back(new transaction_id(i));
    }

    wait_for_graph_ = std::make_unique<DirectedGraph>();

    for (std::uint64_t i = 0; i < 12; ++i) {
      node_ids_.push_back(wait_for_graph_->addNodeUnchecked(transactions_[i]));
    }

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

    for (std::uint64_t i = 0; i < edges_.size(); ++i) {
      std::pair<DirectedGraph::node_id, DirectedGraph::node_id> edge = edges_[i];
      wait_for_graph_->addEdgeUnchecked(edge.first, edge.second);
    }

    cycle_detector_ = std::make_unique<CycleDetector>(wait_for_graph_.get());
  }

  std::vector<std::pair<DirectedGraph::node_id, DirectedGraph::node_id>> edges_;
  std::unique_ptr<DirectedGraph> wait_for_graph_;
  std::vector<transaction_id*> transactions_;
  std::vector<DirectedGraph::node_id> node_ids_;
  std::unique_ptr<CycleDetector> cycle_detector_;
};

class CycleDetectorTestSimple : public testing::Test {
 protected:
  virtual void SetUp() {
    for (std::uint64_t i = 0; i < 12; ++i) {
      transactions_.push_back(new transaction_id(i));
    }

    wait_for_graph_ = std::make_unique<DirectedGraph>();

    for (std::uint64_t i = 0; i < 12; ++i) {
      node_ids_.push_back(wait_for_graph_->addNodeUnchecked(transactions_[i]));
    }

    edges_ = {{0, 1},
              {1, 0}};

    for (std::uint64_t i = 0; i < edges_.size(); ++i) {
      std::pair<DirectedGraph::node_id, DirectedGraph::node_id> edge = edges_[i];
      wait_for_graph_->addEdgeUnchecked(edge.first, edge.second);
    }

    cycle_detector_ = std::make_unique<CycleDetector>(wait_for_graph_.get());
  }

  std::vector<std::pair<DirectedGraph::node_id, DirectedGraph::node_id>> edges_;
  std::unique_ptr<DirectedGraph> wait_for_graph_;
  std::vector<transaction_id*> transactions_;
  std::vector<DirectedGraph::node_id> node_ids_;
  std::unique_ptr<CycleDetector> cycle_detector_;
};


TEST_F(CycleDetectorTest, BreakCycle) {
  std::vector<DirectedGraph::node_id> victims = cycle_detector_->breakCycle();
  std::vector<DirectedGraph::node_id> expected_victims = {6, 7, 8, 9, 2, 1};
  EXPECT_EQ(expected_victims.size(), victims.size());
  for (std::size_t i = 0; i < victims.size(); ++i) {
    EXPECT_EQ(expected_victims[i], victims[i]);
  }
}

TEST_F(CycleDetectorTestSimple, BreakCycleSimple) {
  std::vector<DirectedGraph::node_id> victims = cycle_detector_->breakCycle();
  std::vector<DirectedGraph::node_id> expected_victims = {0};
  EXPECT_EQ(expected_victims.size(), victims.size());
  for (std::size_t i = 0; i < victims.size(); ++i) {
    EXPECT_EQ(expected_victims[i], victims[i]);
  }
}

}  // namespace transaction
}  // namespace quickstep
