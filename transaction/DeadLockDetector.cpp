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

#include <algorithm>
#include <atomic>
#include <chrono>
#include <memory>
#include <utility>
#include <vector>

#include "transaction/CycleDetector.hpp"
#include "transaction/DirectedGraph.hpp"
#include "transaction/LockTable.hpp"
#include "transaction/Transaction.hpp"

namespace quickstep {
namespace transaction {

constexpr std::int64_t DeadLockDetector::kSleepDuration;

DeadLockDetector::DeadLockDetector(LockTable *lock_table,
                                   std::atomic<DeadLockDetectorStatus> *status,
                                   std::vector<DirectedGraph::node_id> *victims)
    : wait_for_graph_(nullptr),
      tid_node_mapping_(std::make_unique<transaction_id_node_map>()),
      lock_table_(lock_table),
      status_(*status),
      victims_(*victims) {
}

void DeadLockDetector::run() {
  while (true) {
    if (status_.load() == DeadLockDetectorStatus::kQuit) {
      // DeadLockDetector should stop.
      return;
    }
    while (status_.load() == DeadLockDetectorStatus::kDone) {
      // LockTable has not process the previous batch yet.
    }

    // TODO(Hakan): Implement logging mechanism for deadlock detection
    //              start and end times.
    std::vector<DirectedGraph::node_id> victim_new_batch = getAllVictims();

    // Swap new batch with old batch to make LockTable to see new victims.
    std::swap(victim_new_batch, victims_);

    // Signal LockTable that new batch is ready.
    status_.store(DeadLockDetectorStatus::kDone);

    // DeadLockDetector should run once in a predefined interval.
    std::this_thread::sleep_for(
        std::chrono::seconds(kSleepDuration));
  }
}

void DeadLockDetector::addPendingInfo(transaction_id pending,
                                      transaction_id owner) {
  DirectedGraph::node_id pending_node_id = getNodeId(pending);
  DirectedGraph::node_id owner_node_id = getNodeId(owner);

  // TODO(Hakan): Check first whether link is already created. Use checked
  //              version for adding an edge.
  wait_for_graph_->addEdgeUnchecked(pending_node_id, owner_node_id);
}

void DeadLockDetector::deletePendingInfo(transaction_id pending,
                                         transaction_id owner) {
  FATAL_ERROR("Not implemented");
}

bool DeadLockDetector::isDependent(transaction_id pending, transaction_id owner) {
  FATAL_ERROR("Not implemented");
}

std::vector<transaction_id>
DeadLockDetector::getAllDependents(transaction_id owner) {
  FATAL_ERROR("Not implemented");
}

std::vector<transaction_id>
DeadLockDetector::getAllDependees(transaction_id pending) {
  DirectedGraph::node_id pending_node_id = getNodeId(pending);
  std::vector<DirectedGraph::node_id> nodes
      = wait_for_graph_->getAdjacentNodes(pending_node_id);
  std::vector<transaction_id> transactions;
  transactions.reserve(nodes.size());
  for (DirectedGraph::node_id node_id : nodes) {
    transaction_id tid = wait_for_graph_->getDataFromNode(node_id);
    transactions.push_back(tid);
  }
  return transactions;
}

DirectedGraph::node_id DeadLockDetector::getNodeId(transaction_id tid) {
  DirectedGraph::node_id node_id;
  if (tid_node_mapping_->count(tid) == 0) {
    // If it is not created, create it.
    node_id = addNode(tid);
  } else {
    // Otherwise find it in the map.
    node_id = (*tid_node_mapping_)[tid];
  }
  return node_id;
}


DirectedGraph::node_id DeadLockDetector::addNode(transaction_id tid) {
  transaction_id *tid_ptr = new transaction_id(tid);
  DirectedGraph::node_id node_id = wait_for_graph_->addNodeUnchecked(tid_ptr);
  (*tid_node_mapping_)[tid] = node_id;
  return node_id;
}

std::vector<transaction_id> DeadLockDetector::getAllVictims() {
  std::vector<transaction_id> result_victims;
  wait_for_graph_ = std::make_unique<DirectedGraph>();

  // Critical region on LockTable starts here.
  lock_table_->latchShared();

  for (LockTable::const_iterator it = lock_table_->begin();
       it != lock_table_->end(); ++it) {
    const LockTable::lock_own_list &own_list = it->second.first;
    const LockTable::lock_pending_list &pending_list = it->second.second;

    for (LockTable::lock_own_list::const_iterator it_own_list = own_list.begin();
         it_own_list != own_list.end(); ++it_own_list) {
      transaction_id owned_transaction = it_own_list->first;

      // TODO(Hakan): Convert them to log messages.
      // std::cout << "Owned: " << owned_transaction << std::endl;

      DirectedGraph::node_id owned_node = getNodeId(owned_transaction);

      for (LockTable::lock_pending_list::const_iterator
               it_pending_list = pending_list.begin();
           it_pending_list != pending_list.end(); ++it_pending_list) {
        transaction_id pending_transaction = it_pending_list->first;
        // std::cout << "Pending: " <<  pending_transaction << std::endl;

        DirectedGraph::node_id pending_node = getNodeId(pending_transaction);

        wait_for_graph_->addEdgeUnchecked(pending_node, owned_node);

        // std::cout << "AddEdge(" << pending_transaction << ", "
        //           << owned_transaction << ")" << std::endl;
      }
    }
  }

  lock_table_->unlatchShared();
  // Critical region on LockTable ends here.

  CycleDetector cycle_detector(wait_for_graph_.get());
  std::vector<DirectedGraph::node_id> victim_nodes = cycle_detector.breakCycle();
  for (DirectedGraph::node_id node_id : victim_nodes) {
    transaction_id victim_tid = wait_for_graph_->getDataFromNode(node_id);
    result_victims.push_back(victim_tid);
  }

  // Destroy the wait graph. It will be reconstructed kSleepDurationSeconds
  // seconds later.
  wait_for_graph_.release();

  return result_victims;
}

}  // namespace transaction
}  // namespace quickstep
