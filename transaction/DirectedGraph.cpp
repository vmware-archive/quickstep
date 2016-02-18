#include "transaction/DirectedGraph.hpp"

namespace quickstep {

DirectedGraph::NodeId DirectedGraph::addNode(TransactionId *data) {
  nodes_.emplace_back(data);
  return nodes_.size() - 1;
}

void DirectedGraph::addEdge(NodeId from_node, NodeId to_node) {
  nodes_[from_node].addOutgoingEdge(to_node);
}

bool DirectedGraph::hasEdge(NodeId from_node, NodeId to_node) const {
  return nodes_[from_node].hasOutgoingEdge(to_node);
}

std::size_t DirectedGraph::count() const {
  return nodes_.size();
}

TransactionId DirectedGraph::getDataFromNode(NodeId node) const {
  return nodes_[node].getData();
}

std::vector<DirectedGraph::NodeId>
DirectedGraph::getAdjacentNodes(NodeId id) const {
  return nodes_[id].getOutgoingEdges();
}

DirectedGraph::DirectedGraphNode::DirectedGraphNode(TransactionId *data)
  : data_(data) {
}

void DirectedGraph::DirectedGraphNode::addOutgoingEdge(NodeId to_node) {
  outgoing_edges_.insert(to_node);
}

bool DirectedGraph::DirectedGraphNode::hasOutgoingEdge(NodeId to_node) const {
  return outgoing_edges_.count(to_node) == 1;
}

std::vector<DirectedGraph::NodeId> DirectedGraph::DirectedGraphNode::getOutgoingEdges() const {
  std::vector<NodeId> result;
  std::copy(outgoing_edges_.begin(), outgoing_edges_.end(), std::back_inserter(result));
  return result;
}

TransactionId DirectedGraph::DirectedGraphNode::getData() const {
  return *(data_.get());
}

}
