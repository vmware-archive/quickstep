#ifndef QUICKSTEP_TRANSACTION_DIRECTED_GRAPH_HPP_
#define QUICKSTEP_TRANSACTION_DIRECTED_GRAPH_HPP_

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>

#include "utility/Macros.hpp"

namespace quickstep {

template <typename T>
class DirectedGraph {
public:
  using NodeId = std::uint64_t;

  DirectedGraph();
  
  NodeId addNode(T *data);

  void addEdge(NodeId fromNode, NodeId toNode);
  
  bool hasEdge(NodeId fromNode, NodeId toNode) const;
  
  std::size_t count() const;
    
  std::vector<NodeId> getAdjacentNodes(NodeId id) const;

private:
  class DirectedGraphNode {
  public:
    DirectedGraphNode(T *data);

    void addOutgoingEdge(NodeId toNode);

    bool hasOutgoingEdge(NodeId toNode) const;

    std::vector<NodeId> getOutgoingEdges() const;
    
  private:
    std::unique_ptr<T> data_;
    std::unordered_set<NodeId> outgoing_edges_;
  };
  
  DISALLOW_COPY_AND_ASSIGN(DirectedGraph);
  std::vector<DirectedGraphNode> nodes_;
};


/******************
 Implementation
******************/

template <typename T>
DirectedGraph<T>::DirectedGraph() {
}

template <typename T>
typename DirectedGraph<T>::NodeId DirectedGraph<T>::addNode(T *data) {
  nodes_.emplace_back(data);
  return nodes_.size() - 1;
}

template <typename T>
void DirectedGraph<T>::addEdge(NodeId fromNode, NodeId toNode) {
  nodes_[fromNode].addOutgoingEdge(toNode);
}

template <typename T>
bool DirectedGraph<T>::hasEdge(NodeId fromNode, NodeId toNode) const {
  return nodes_[fromNode].hasOutgoingEdge(toNode);
}

template <typename T>
std::size_t DirectedGraph<T>::count() const {
  return nodes_.size();
}

template <typename T>
std::vector<typename DirectedGraph<T>::NodeId> DirectedGraph<T>::getAdjacentNodes(NodeId id) const {
  return nodes_[id].getOutgoingEdges();
}

template <typename T>
DirectedGraph<T>::DirectedGraphNode::DirectedGraphNode(T *data)
  : data_(data) {
}

template <typename T>
void DirectedGraph<T>::DirectedGraphNode::addOutgoingEdge(NodeId toNode) {
  outgoing_edges_.insert(toNode);
}

template <typename T>
bool DirectedGraph<T>::DirectedGraphNode::hasOutgoingEdge(NodeId toNode) const {
  return outgoing_edges_.count(toNode) == 1;
}

template <typename T>
std::vector<typename DirectedGraph<T>::NodeId> DirectedGraph<T>::DirectedGraphNode::getOutgoingEdges() const {
  std::vector<NodeId> result;
  std::copy(outgoing_edges_.begin(), outgoing_edges_.end(), std::back_inserter(result));
  return result;
}
}

#endif
