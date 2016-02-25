#include "transaction/DirectedGraph.hpp"
#include "transaction/Transaction.hpp"

#include "gtest/gtest.h"

namespace quickstep {

TEST(DirectedGraphTest, AddNode) {
  DirectedGraph wait_for_graph;
  TransactionId *tid3 = new TransactionId(3);
  TransactionId *tid4 = new TransactionId(4);
  TransactionId *tid5 = new TransactionId(5);
  TransactionId *tid6 = new TransactionId(6);
  
  EXPECT_TRUE(wait_for_graph.count() == 0);
  
  wait_for_graph.addNode(tid3);

  EXPECT_TRUE(wait_for_graph.count() == 1);
  
  wait_for_graph.addNode(tid4);

  EXPECT_TRUE(wait_for_graph.count() == 2);

  
  wait_for_graph.addNode(tid5);
  wait_for_graph.addNode(tid6);

  EXPECT_TRUE(wait_for_graph.count() == 4);
}

TEST(DirectedGraphTest, AddEdge) {
  DirectedGraph wait_for_graph;
  TransactionId *tid3 = new TransactionId(3);
  TransactionId *tid4 = new TransactionId(4);
  TransactionId *tid5 = new TransactionId(5);
  TransactionId *tid6 = new TransactionId(6);

  using NID = DirectedGraph::NodeId;
  NID nid3 = wait_for_graph.addNode(tid3);
  NID nid6 = wait_for_graph.addNode(tid6);
  NID nid4 = wait_for_graph.addNode(tid4);
  NID nid5 = wait_for_graph.addNode(tid5);

  wait_for_graph.addEdge(nid3, nid5);
  wait_for_graph.addEdge(nid6, nid4);
  wait_for_graph.addEdge(nid3, nid6);
  wait_for_graph.addEdge(nid4, nid6);

  EXPECT_TRUE(wait_for_graph.hasEdge(nid3, nid5));
  EXPECT_TRUE(wait_for_graph.hasEdge(nid6, nid4));
  EXPECT_TRUE(wait_for_graph.hasEdge(nid4, nid6));
  EXPECT_TRUE(wait_for_graph.hasEdge(nid3, nid6));

  EXPECT_FALSE(wait_for_graph.hasEdge(nid5, nid3));
  EXPECT_FALSE(wait_for_graph.hasEdge(nid6, nid3));
  EXPECT_FALSE(wait_for_graph.hasEdge(nid4, nid5));
  
}

TEST(DirectedGraphTest, GetAdjacentNodes) {
  DirectedGraph wait_for_graph;
  TransactionId *tid3 = new TransactionId(3);
  TransactionId *tid4 = new TransactionId(4);
  TransactionId *tid5 = new TransactionId(5);
  TransactionId *tid6 = new TransactionId(6);

  using NID = DirectedGraph::NodeId;
  NID nid3 = wait_for_graph.addNode(tid3);
  NID nid6 = wait_for_graph.addNode(tid6);
  NID nid4 = wait_for_graph.addNode(tid4);
  NID nid5 = wait_for_graph.addNode(tid5);

  std::vector<NID> result1 = wait_for_graph.getAdjacentNodes(nid3);
  EXPECT_TRUE(result1.size() == 0);
  
  wait_for_graph.addEdge(nid3, nid4);
  wait_for_graph.addEdge(nid3, nid5);

  std::vector<NID> result2 = wait_for_graph.getAdjacentNodes(nid3);
  EXPECT_TRUE(result2.size() == 2);

  wait_for_graph.addEdge(nid3, nid6);
  std::vector<NID> result3 = wait_for_graph.getAdjacentNodes(nid3);
  EXPECT_TRUE(result3.size() == 3);

}
}
