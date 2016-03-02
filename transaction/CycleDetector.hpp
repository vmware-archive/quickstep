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

#ifndef QUICKSTEP_TRANSACTION_CYCLE_DETECTOR_HPP_
#define QUICKSTEP_TRANSACTION_CYCLE_DETECTOR_HPP_

#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

#include "transaction/DirectedGraph.hpp"
#include "transaction/StronglyConnectedComponents.hpp"

namespace quickstep {

namespace transaction {

/** \addtogroup Transaction
 *  @{
 */

/**
 * @brief Class for running cycle detection algorithm on directed graph.
 */
class CycleDetector {
 public:
  /**
   * @brief Constructor for DirectedGraph.
   *
   * @param wait_for_graph Pointer to a directed wait-for graph.
   */
  explicit CycleDetector(DirectedGraph *wait_for_graph);

  /**
   * @brief Calculate which nodes should be killed to eliminate all cycles
   *        in the graph.
   *
   * @return Vector of node ids that should be killed to break all cycles.
   */
  std::vector<DirectedGraph::NodeId> breakCycle();

 private:
  std::vector<DirectedGraph::NodeId>
      breakComponent(const std::vector<DirectedGraph::NodeId> &nodes);

  // Checks whether the nodes in the set make a cycle.
  bool hasCycleWithin(const std::set<DirectedGraph::NodeId> &within);

  // Pointer to the
  std::unique_ptr<StronglyConnectedComponents> scc_;

  DirectedGraph *wait_for_graph_;

  DISALLOW_COPY_AND_ASSIGN(CycleDetector);
};

/** @} */

}  // namespace transaction

}  // namespace quickstep

#endif
