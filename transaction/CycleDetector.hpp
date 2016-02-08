#ifndef QUICKSTEP_TRANSACTION_CYCLE_DETECTOR_HPP_
#define QUICKSTEP_TRANSACTION_CYCLE_DETECTOR_HPP_

#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

#include "transaction/DirectedGraph.hpp"
#include "transaction/StronglyConnectedComponents.hpp"



namespace quickstep {
  
template <typename T>
class CycleDetector {
public:
  CycleDetector(DirectedGraph<T> *wait_for_graph);

  std::vector<typename DirectedGraph<T>::NodeId> breakCycle();

  bool hasCycleWithin(const std::set<typename DirectedGraph<T>::NodeId> &within);
private:
  DISALLOW_COPY_AND_ASSIGN(CycleDetector);

  std::vector<typename DirectedGraph<T>::NodeId> breakComponent(const std::vector<typename DirectedGraph<T>::NodeId> &nodes);

  
  
  std::unique_ptr<StronglyConnectedComponents<T>> scc_;
  DirectedGraph<T> *wait_for_graph_;
};

template <typename T>
CycleDetector<T>::CycleDetector(DirectedGraph<T> *wait_for_graph)
  : wait_for_graph_(wait_for_graph) {
  scc_ = std::make_unique<StronglyConnectedComponents<T>>(wait_for_graph_);
}

template <typename T>
std::vector<typename DirectedGraph<T>::NodeId> CycleDetector<T>::breakCycle() {
  std::vector<typename DirectedGraph<T>::NodeId> nodes_to_kill;
  scc_->findStronglyConnectedComponents();
  std::unordered_map<std::uint64_t, std::vector<typename DirectedGraph<T>::NodeId>>
    component_mapping = scc_->getComponentMapping();
  
  for (std::pair<std::uint64_t, std::vector<typename DirectedGraph<T>::NodeId>>
	 entry : component_mapping) {
    if (entry.second.size() == 1) {
      continue;
    }
    else {
      std::vector<typename DirectedGraph<T>::NodeId>
	targets = breakComponent(entry.second);

      for (typename DirectedGraph<T>::NodeId elem : targets) {
	nodes_to_kill.push_back(elem);
      }
    }
  }

  return nodes_to_kill;
}

template <typename T>
std::vector<typename DirectedGraph<T>::NodeId> CycleDetector<T>::breakComponent(const std::vector<typename DirectedGraph<T>::NodeId> &nodes) {
  std::vector<typename DirectedGraph<T>::NodeId> targets;
  std::set<typename DirectedGraph<T>::NodeId> nodes_set(nodes.begin(), nodes.end());
  while (true) {
    bool has_cycle = hasCycleWithin(nodes_set);
    if (!has_cycle) {
      break;
    }
    typename DirectedGraph<T>::NodeId victim = *(nodes_set.begin());
    nodes_set.erase(nodes_set.begin());
    targets.push_back(victim);
  }
  return targets;
  
}

template <typename T>
bool CycleDetector<T>::hasCycleWithin(const std::set<typename DirectedGraph<T>::NodeId> &within) {
  std::set<typename DirectedGraph<T>::NodeId> visited;
  for (typename DirectedGraph<T>::NodeId node_id : within) {
    if (visited.count(node_id) == 1) {
      continue;
    }
    std::stack<typename DirectedGraph<T>::NodeId> to_visit;
    to_visit.push(node_id);
    while (!to_visit.empty()) {
      typename DirectedGraph<T>::NodeId current_node = to_visit.top();
      to_visit.pop();
      visited.insert(current_node);
      std::vector<typename DirectedGraph<T>::NodeId> adjacents = wait_for_graph_->getAdjacentNodes(current_node);
      for (typename DirectedGraph<T>::NodeId adj : adjacents) {
	if (adj == node_id) {
	  return true;
	}
	else if (within.count(adj) == 1 && visited.count(adj) == 0) {
	  to_visit.push(adj);
	}
      }
    }
  }
  return false;
}

}  
#endif
