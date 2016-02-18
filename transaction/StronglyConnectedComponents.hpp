#ifndef QUICKSTEP_TRANSACTION_STRONGLY_CONNECTED_COMPONENTS_HPP_
#define QUICKSTEP_TRANSACTION_STRONGLY_CONNECTED_COMPONENTS_HPP_

#include <vector>
#include <stack>
#include <unordered_map>

#include "transaction/DirectedGraph.hpp"
#include "utility/Macros.hpp"

namespace quickstep {

class StronglyConnectedComponents {
public:
  StronglyConnectedComponents(DirectedGraph *directed_graph);

  void findStronglyConnectedComponents();

  std::uint64_t getComponentId(DirectedGraph::NodeId node_id) const;

  std::uint64_t getTotalComponents() const;

  std::unordered_map<std::uint64_t, std::vector<DirectedGraph::NodeId>> getComponentMapping() const;
  
private:
  DISALLOW_COPY_AND_ASSIGN(StronglyConnectedComponents);

  void depthFirstSearch(DirectedGraph::NodeId v);
  
  DirectedGraph *directed_graph_;
  //bool is_ready;

  std::vector<bool> is_marked_;
  std::vector<std::uint64_t> component_ids_; // component_ids[v] = node_id v's component id
  std::vector<std::uint64_t> low_ids_;

  std::stack<DirectedGraph::NodeId> stack_;
  
  std::uint64_t preorder_counter_; // preorder no counter
  std::uint64_t no_of_components_; // no of SCC components
};

}

#endif
