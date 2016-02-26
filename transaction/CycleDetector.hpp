#ifndef QUICKSTEP_TRANSACTION_CYCLE_DETECTOR_HPP_
#define QUICKSTEP_TRANSACTION_CYCLE_DETECTOR_HPP_

#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

#include "transaction/DirectedGraph.hpp"
#include "transaction/StronglyConnectedComponents.hpp"



namespace quickstep {

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
  CycleDetector(DirectedGraph *wait_for_graph);

  /**
   * @brief Calculate which nodes should be killed to eliminate all cycles
   *        in the graph.
   *
   * @return Vector of node ids that should be killed to break all cycles.
   */
  std::vector<DirectedGraph::NodeId> breakCycle();

private:
  DISALLOW_COPY_AND_ASSIGN(CycleDetector);

  std::vector<DirectedGraph::NodeId> breakComponent(const std::vector<DirectedGraph::NodeId> &nodes);

  bool hasCycleWithin(const std::set<DirectedGraph::NodeId> &within);
  
  std::unique_ptr<StronglyConnectedComponents> scc_;
  DirectedGraph *wait_for_graph_;
};

/** @} */

}  
#endif
