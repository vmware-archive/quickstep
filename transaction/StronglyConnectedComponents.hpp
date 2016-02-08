#ifndef QUICKSTEP_TRANSACTION_STRONGLY_CONNECTED_COMPONENTS_HPP_
#define QUICKSTEP_TRANSACTION_STRONGLY_CONNECTED_COMPONENTS_HPP_

#include <vector>
#include <stack>
#include <unordered_map>

#include "transaction/DirectedGraph.hpp"
#include "utility/Macros.hpp"

namespace quickstep {

template <typename T>
class StronglyConnectedComponents {
public:
  StronglyConnectedComponents(DirectedGraph<T> *directed_graph);

  void findStronglyConnectedComponents();

  std::uint64_t getComponentId(typename DirectedGraph<T>::NodeId node_id) const;

  std::uint64_t getTotalComponents() const;

  std::unordered_map<std::uint64_t, std::vector<typename DirectedGraph<T>::NodeId>> getComponentMapping() const;
  
private:
  DISALLOW_COPY_AND_ASSIGN(StronglyConnectedComponents);

  void depthFirstSearch(typename DirectedGraph<T>::NodeId v);
  
  DirectedGraph<T> *directed_graph_;
  bool is_ready;

  std::vector<bool> is_marked_;
  std::vector<std::uint64_t> component_ids_; // component_ids[v] = node_id v's component id
  std::vector<std::uint64_t> low_ids_;

  std::stack<typename DirectedGraph<T>::NodeId> stack_;
  
  std::uint64_t preorder_counter_; // preorder no counter
  std::uint64_t no_of_components_; // no of SCC components
};

template <typename T>
StronglyConnectedComponents<T>::StronglyConnectedComponents(DirectedGraph<T> *directed_graph)
  : directed_graph_(directed_graph)
  , is_marked_(directed_graph_->count())
  , component_ids_(directed_graph_->count())
  , low_ids_(directed_graph_->count())
  , preorder_counter_(0)
  , no_of_components_(0) {
}
  
template <typename T>
void StronglyConnectedComponents<T>::findStronglyConnectedComponents() {
  for (typename DirectedGraph<T>::NodeId v = 0; v < directed_graph_->count(); ++v) {
    if (!is_marked_[v]) {
      depthFirstSearch(v);
    }
  }
}

template <typename T>
void StronglyConnectedComponents<T>::depthFirstSearch(typename DirectedGraph<T>::NodeId v) {
  is_marked_[v] = true;
  low_ids_[v] = preorder_counter_++;
  std::uint64_t min = low_ids_[v];
  stack_.push(v);
  for (typename DirectedGraph<T>::NodeId w : directed_graph_->getAdjacentNodes(v)) {
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
  typename DirectedGraph<T>::NodeId w;
  do {
    w = stack_.top();
    component_ids_[w] = no_of_components_;
    low_ids_[w] = directed_graph_->count();
    stack_.pop();
  } while (w != v);

  no_of_components_++;
  
}

template <typename T>
std::uint64_t StronglyConnectedComponents<T>::getComponentId(typename DirectedGraph<T>::NodeId node_id) const {
  return component_ids_[node_id];
}

template <typename T>
std::uint64_t StronglyConnectedComponents<T>::getTotalComponents() const {
  return no_of_components_;
}

template <typename T>
std::unordered_map<std::uint64_t, std::vector<typename DirectedGraph<T>::NodeId>> StronglyConnectedComponents<T>::getComponentMapping() const {
  std::unordered_map<std::uint64_t, std::vector<typename DirectedGraph<T>::NodeId>> component_mapping;
  for (std::uint64_t i = 0; i < component_ids_.size(); ++i) {
    component_mapping[component_ids_[i]].push_back(i);
  }
  return component_mapping;
}
}

#endif
