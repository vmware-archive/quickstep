#include "transaction/StronglyConnectedComponents.hpp"

namespace quickstep {

StronglyConnectedComponents::StronglyConnectedComponents(DirectedGraph *directed_graph)
  : directed_graph_(directed_graph)
  , is_marked_(directed_graph_->count())
  , component_ids_(directed_graph_->count())
  , low_ids_(directed_graph_->count())
  , preorder_counter_(0)
  , no_of_components_(0) {
}
  
void StronglyConnectedComponents::findStronglyConnectedComponents() {
  for (DirectedGraph::NodeId v = 0; v < directed_graph_->count(); ++v) {
    if (!is_marked_[v]) {
      depthFirstSearch(v);
    }
  }
}


void StronglyConnectedComponents::depthFirstSearch(DirectedGraph::NodeId v) {
  is_marked_[v] = true;
  low_ids_[v] = preorder_counter_++;
  std::uint64_t min = low_ids_[v];
  stack_.push(v);
  
  for (DirectedGraph::NodeId w : directed_graph_->getAdjacentNodes(v)) {
    if (!is_marked_[w]) {
      depthFirstSearch(w);
    }
    if (low_ids_[w] < min) {
      min = low_ids_[w];
    }
  }
  if (min < low_ids_[v]) {
    low_ids_[v] = min;
    return;
  }
  DirectedGraph::NodeId w;
  do {
    w = stack_.top();
    component_ids_[w] = no_of_components_;
    low_ids_[w] = directed_graph_->count();
    stack_.pop();
  } while (w != v);

  no_of_components_++;
  
}

std::uint64_t StronglyConnectedComponents::getComponentId(DirectedGraph::NodeId node_id) const {
  return component_ids_[node_id];
}

std::uint64_t StronglyConnectedComponents::getTotalComponents() const {
  return no_of_components_;
}

std::unordered_map<std::uint64_t, std::vector<DirectedGraph::NodeId>> StronglyConnectedComponents::getComponentMapping() const {
  std::unordered_map<std::uint64_t, std::vector<DirectedGraph::NodeId>> component_mapping;
  for (std::uint64_t i = 0; i < component_ids_.size(); ++i) {
    component_mapping[component_ids_[i]].push_back(i);
  }
  return component_mapping;
}

}
