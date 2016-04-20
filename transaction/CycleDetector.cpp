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
#include <set>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

#include "transaction/DirectedGraph.hpp"
#include "transaction/StronglyConnectedComponents.hpp"

namespace quickstep {
namespace transaction {

CycleDetector::CycleDetector(DirectedGraph *wait_for_graph)
  : wait_for_graph_(wait_for_graph) {
  scc_ = std::make_unique<StronglyConnectedComponents>(*wait_for_graph_);
}

std::vector<DirectedGraph::node_id> CycleDetector::breakCycle() {
  std::vector<DirectedGraph::node_id> nodes_to_kill;
  std::unordered_map<std::uint64_t, std::vector<DirectedGraph::node_id>>
    component_mapping = scc_->getComponentMapping();
  for (std::pair<std::uint64_t, std::vector<DirectedGraph::node_id>>
         entry : component_mapping) {
    // One node means no cycle.
    if (entry.second.size() == 1) {
      continue;
    } else {
      std::vector<DirectedGraph::node_id> targets
          = breakComponent(entry.second);
      for (DirectedGraph::node_id elem : targets) {
        nodes_to_kill.push_back(elem);
      }
    }
  }

  return nodes_to_kill;
}

std::vector<DirectedGraph::node_id>
CycleDetector::breakComponent(const std::vector<DirectedGraph::node_id> &nodes) {
  std::vector<DirectedGraph::node_id> targets;
  // Convert it to set to ensure defensively that the elements are unique.
  std::set<DirectedGraph::node_id> nodes_set(nodes.begin(), nodes.end());
  while (true) {
    bool has_cycle = hasCycleWithin(nodes_set);
    if (!has_cycle) {
      break;
    }
    // If there is a cycle, start to pop a node from the beginning.
    // TODO(Hakan): This is very inefficient scheme, however in the
    //              future, we can use the transaction's priority
    //              as the victim selection parameter.
    DirectedGraph::node_id victim = *(nodes_set.begin());
    nodes_set.erase(nodes_set.begin());
    targets.push_back(victim);
  }
  return targets;
}

bool
CycleDetector::hasCycleWithin(const std::set<DirectedGraph::node_id> &within) {
  // Keeps track of the nodes the algorithms visited.
  std::set<DirectedGraph::node_id> visited;
  for (DirectedGraph::node_id node_id : within) {
    // If it is visited, then pass to the next one.
    if (visited.count(node_id) == 1) {
      continue;
    }
    // Save the backtracking information.
    std::stack<DirectedGraph::node_id> to_visit;
    // Mark this id as "to be visited".
    to_visit.push(node_id);
    // Start to visit nodes until it is done.
    while (!to_visit.empty()) {
      DirectedGraph::node_id current_node = to_visit.top();
      to_visit.pop();
      // Mark the node coming from stack as "visited".
      visited.insert(current_node);
      // For all adjacent nodes of this "visited" node,
      std::vector<DirectedGraph::node_id> adjacents
          = wait_for_graph_->getAdjacentNodes(current_node);
      for (DirectedGraph::node_id adj : adjacents) {
        if (adj == node_id) {
          // If this adjacent node is the node we started, then
          // there is a cycle.
          return true;
        } else if (within.count(adj) == 1 && visited.count(adj) == 0) {
          // Otherwise, if it is a node that we did not visit before
          // mark this nodes as "to be visited".
          to_visit.push(adj);
        }
      }
    }
  }
  // If we have already visited all nodes and could not find a cycle,
  // then we should return "no cycle" result.
  return false;
}

}  // namespace transaction
}  // namespace quickstep
