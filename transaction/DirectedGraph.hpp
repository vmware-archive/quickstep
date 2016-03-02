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

namespace transaction {

/** \addtogroup Transaction
 *  @{
 */

/**
 * @brief Class for representing a directed graph.
 *        Vertices are transaction ids, edges are
 *        wait-for relations.
 */
class DirectedGraph {
 public:
  using NodeId = std::uint64_t;

  /**
   * @brief Default constructor
   */
  DirectedGraph() {}

  /**
   * @brief Adds node with given transaction id.
   * @warning It does not check whether transaction id
   *          is already in the graph.
   * @warning Pointer ownership will pass to the graph,
   *          threfore it should not be deleted.
   *
   * @param data Pointer to the transaction id that
   *        will be contained in the node.
   *
   * @return Id of the newly created node.
   */
  NodeId addNode(TransactionId *data);

  /**
   * @brief Adds an edge between nodes.
   * @warning Does not check arguments are legit.
   *          It may cause out of range errors.
   *
   * @param fromNode The node that edge is orginated.
   * @param toNode The node that edge is ended.
   */
  void addEdge(NodeId fromNode, NodeId toNode);

  /**
   * @brief Check whether there is a directed edge.
   * @warning Does not check argument are legit.
   *          It may cause out of range errors.
   *
   * @param fromNode Id of the node that edge is originated from.
   * @param toNode Id of the node that edge is ended.
   *
   * @return True if there is an edge, false otherwise.
   */
  bool hasEdge(NodeId fromNode, NodeId toNode) const;

  /**
   * @brief Get data (transaction id) contained in the node.
   * @warning Does not check index validity.
   *
   * @param node Id of the node that the data is got from.
   * @return Id of the transaction that this node contains.
   */
  TransactionId getDataFromNode(NodeId node) const;

  /**
   * @brief Calculate how many nodes the graph has.
   *
   * @return The number of nodes the graph has.
   */
  std::size_t count() const;

  /**
   * @brief Gives the node ids that this node has edges to.
   *
   * @param id Id of the corresponding node.
   * @return Vector of node ids that id has edges to.
   */
  std::vector<NodeId> getAdjacentNodes(NodeId id) const;

 private:
  // Class for representing a graph node.
  class DirectedGraphNode {
   public:
    explicit DirectedGraphNode(TransactionId *data);

    void addOutgoingEdge(NodeId toNode);

    bool hasOutgoingEdge(NodeId toNode) const;

    std::vector<NodeId> getOutgoingEdges() const;

    TransactionId getData() const;

   private:
    // Owner pointer to transaction id.
    std::unique_ptr<TransactionId> data_;

    // Endpoint nodes of outgoing edges originated from this node.
    std::unordered_set<NodeId> outgoing_edges_;
  };

  // Buffer of nodes that are created. NodeId is the index of that
  // node in this buffer.
  std::vector<DirectedGraphNode> nodes_;

  DISALLOW_COPY_AND_ASSIGN(DirectedGraph);
};

/** @} */

}  // namespace transaction

}  // namespace quickstep

#endif
