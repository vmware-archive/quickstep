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

#include <set>
#include <stack>
#include <vector>
#include <utility>

namespace quickstep {

namespace transaction {

CycleDetector::CycleDetector(DirectedGraph *wait_for_graph)
  : wait_for_graph_(wait_for_graph) {
  scc_ = std::make_unique<StronglyConnectedComponents>(wait_for_graph_);
}

std::vector<DirectedGraph::NodeId> CycleDetector::breakCycle() {
  std::vector<DirectedGraph::NodeId> nodes_to_kill;
  scc_->findStronglyConnectedComponents();
  std::unordered_map<std::uint64_t, std::vector<DirectedGraph::NodeId>>
    component_mapping = scc_->getComponentMapping();

  for (std::pair<std::uint64_t, std::vector<DirectedGraph::NodeId>>
         entry : component_mapping) {
    // One node means no cycle.
    if (entry.second.size() == 1) {
      continue;
    } else {
      std::vector<DirectedGraph::NodeId> targets
          = breakComponent(entry.second);

      for (DirectedGraph::NodeId elem : targets) {
        nodes_to_kill.push_back(elem);
      }
    }
  }

  return nodes_to_kill;
}

std::vector<DirectedGraph::NodeId>
CycleDetector::breakComponent(const std::vector<DirectedGraph::NodeId> &nodes) {
  std::vector<DirectedGraph::NodeId> targets;
  std::set<DirectedGraph::NodeId> nodes_set(nodes.begin(), nodes.end());
  while (true) {
    bool has_cycle = hasCycleWithin(nodes_set);
    if (!has_cycle) {
      break;
    }
    DirectedGraph::NodeId victim = *(nodes_set.begin());
    nodes_set.erase(nodes_set.begin());
    targets.push_back(victim);
  }
  return targets;
}

bool
CycleDetector::hasCycleWithin(const std::set<DirectedGraph::NodeId> &within) {
  std::set<DirectedGraph::NodeId> visited;
  for (DirectedGraph::NodeId node_id : within) {
    if (visited.count(node_id) == 1) {
      continue;
    }
    std::stack<DirectedGraph::NodeId> to_visit;
    to_visit.push(node_id);
    while (!to_visit.empty()) {
      DirectedGraph::NodeId current_node = to_visit.top();
      to_visit.pop();
      visited.insert(current_node);
      std::vector<DirectedGraph::NodeId> adjacents
          = wait_for_graph_->getAdjacentNodes(current_node);
      for (DirectedGraph::NodeId adj : adjacents) {
        if (adj == node_id) {
          return true;
        } else if (within.count(adj) == 1 && visited.count(adj) == 0) {
          to_visit.push(adj);
        }
      }
    }
  }
  return false;
}

}  // namespace transaction

}  // namespace quickstep
