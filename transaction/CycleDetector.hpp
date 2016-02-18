#ifndef QUICKSTEP_TRANSACTION_CYCLE_DETECTOR_HPP_
#define QUICKSTEP_TRANSACTION_CYCLE_DETECTOR_HPP_

#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

#include "transaction/DirectedGraph.hpp"
#include "transaction/StronglyConnectedComponents.hpp"



namespace quickstep {
  
class CycleDetector {
public:
  CycleDetector(DirectedGraph *wait_for_graph);

  std::vector<DirectedGraph::NodeId> breakCycle();

  bool hasCycleWithin(const std::set<DirectedGraph::NodeId> &within);
private:
  DISALLOW_COPY_AND_ASSIGN(CycleDetector);

  std::vector<DirectedGraph::NodeId> breakComponent(const std::vector<DirectedGraph::NodeId> &nodes);

  
  
  std::unique_ptr<StronglyConnectedComponents> scc_;
  DirectedGraph *wait_for_graph_;
};


}  
#endif
