#ifndef QUICKSTEP_TRANSACTION_DIRECTED_GRAPH_HPP_
#define QUICKSTEP_TRANSACTION_DIRECTED_GRAPH_HPP_

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>

#include "transaction/Transaction.hpp"
#include "utility/Macros.hpp"

namespace quickstep {

class DirectedGraph {
public:
  using NodeId = std::uint64_t;

  DirectedGraph() {}
  
  NodeId addNode(TransactionId *data);

  void addEdge(NodeId fromNode, NodeId toNode);
  
  bool hasEdge(NodeId fromNode, NodeId toNode) const;

  TransactionId getDataFromNode(NodeId node) const;
  
  std::size_t count() const;
  
  std::vector<NodeId> getAdjacentNodes(NodeId id) const;

private:
  class DirectedGraphNode {
  public:
    DirectedGraphNode(TransactionId *data);

    void addOutgoingEdge(NodeId toNode);

    bool hasOutgoingEdge(NodeId toNode) const;

    std::vector<NodeId> getOutgoingEdges() const;

    TransactionId getData() const;
    
  private:
    std::unique_ptr<TransactionId> data_;
    std::unordered_set<NodeId> outgoing_edges_;
    
    //std::unordered_set<NodeId> incoming_edges_;
  };
  
  DISALLOW_COPY_AND_ASSIGN(DirectedGraph);
  std::vector<DirectedGraphNode> nodes_;
};

}

#endif
