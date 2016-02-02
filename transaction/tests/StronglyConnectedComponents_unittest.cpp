#include "transaction/DirectedGraph.hpp"
#include "transaction/StronglyConnectedComponents.hpp"
#include "transaction/Transaction.hpp"

#include "gtest/gtest.h"

namespace quickstep {

TEST(StronglyConnectedComponents, getComponentId) {
  DirectedGraph<TransactionId> wait_for_graph;

  TransactionId *tid1 = new TransactionId(1);
  TransactionId *tid2 = new TransactionId(2);
  TransactionId *tid3 = new TransactionId(3);
  TransactionId *tid4 = new TransactionId(4);
  TransactionId *tid5 = new TransactionId(5);
  TransactionId *tid6 = new TransactionId(6);
  TransactionId *tid7 = new TransactionId(7);
  TransactionId *tid8 = new TransactionId(8);
  TransactionId *tid9 = new TransactionId(9);
  TransactionId *tid10 = new TransactionId(10);
  TransactionId *tid11 = new TransactionId(11);
  TransactionId *tid12 = new TransactionId(12);

  using NID = DirectedGraph<TransactionId>::NodeId;
  
  NID nid1 = wait_for_graph.addNode(tid1);
  NID nid2 = wait_for_graph.addNode(tid2);
  NID nid3 = wait_for_graph.addNode(tid3);
  NID nid4 = wait_for_graph.addNode(tid4);
  NID nid5 = wait_for_graph.addNode(tid5);
  NID nid6 = wait_for_graph.addNode(tid6);
  NID nid7 = wait_for_graph.addNode(tid7);
  NID nid8 = wait_for_graph.addNode(tid8);
  NID nid9 = wait_for_graph.addNode(tid9);
  NID nid10 = wait_for_graph.addNode(tid10);
  NID nid11 = wait_for_graph.addNode(tid11);
  NID nid12 = wait_for_graph.addNode(tid12);

  wait_for_graph.addEdge(nid1, nid2);

  wait_for_graph.addEdge(nid2, nid3);
  wait_for_graph.addEdge(nid2, nid4);
  wait_for_graph.addEdge(nid2, nid5);

  wait_for_graph.addEdge(nid3, nid6);

  wait_for_graph.addEdge(nid4, nid5);
  wait_for_graph.addEdge(nid4, nid7);

  wait_for_graph.addEdge(nid5, nid2);
  wait_for_graph.addEdge(nid5, nid6);
  wait_for_graph.addEdge(nid5, nid7);

  wait_for_graph.addEdge(nid6, nid3);
  wait_for_graph.addEdge(nid6, nid8);

  wait_for_graph.addEdge(nid7, nid8);
  wait_for_graph.addEdge(nid7, nid10);

  wait_for_graph.addEdge(nid8, nid7);

  wait_for_graph.addEdge(nid9, nid7);

  wait_for_graph.addEdge(nid10, nid9);
  wait_for_graph.addEdge(nid10, nid11);

  wait_for_graph.addEdge(nid11, nid12);

  wait_for_graph.addEdge(nid12, nid10);

  StronglyConnectedComponents<TransactionId> scc(&wait_for_graph);
  scc.findStronglyConnectedComponents();

  std::uint64_t total_components = scc.getTotalComponents();
  
  EXPECT_EQ(4, total_components);

  std::uint64_t nid1_component = scc.getComponentId(nid1);
  std::uint64_t nid2_component = scc.getComponentId(nid2);
  std::uint64_t nid3_component = scc.getComponentId(nid3);
  std::uint64_t nid4_component = scc.getComponentId(nid4);
  std::uint64_t nid5_component = scc.getComponentId(nid5);
  std::uint64_t nid6_component = scc.getComponentId(nid6);
  std::uint64_t nid7_component = scc.getComponentId(nid7);
  std::uint64_t nid8_component = scc.getComponentId(nid8);
  std::uint64_t nid9_component = scc.getComponentId(nid9);
  std::uint64_t nid10_component = scc.getComponentId(nid10);
  std::uint64_t nid11_component = scc.getComponentId(nid11);
  std::uint64_t nid12_component = scc.getComponentId(nid12);

  EXPECT_EQ(3, nid1_component);

  EXPECT_EQ(2, nid2_component);
  EXPECT_EQ(2, nid4_component);
  EXPECT_EQ(2, nid5_component);
  
  EXPECT_EQ(1, nid3_component);
  EXPECT_EQ(1, nid6_component);

  EXPECT_EQ(0, nid7_component);
  EXPECT_EQ(0, nid8_component);
  EXPECT_EQ(0, nid9_component);
  EXPECT_EQ(0, nid10_component);
  EXPECT_EQ(0, nid11_component);
  EXPECT_EQ(0, nid12_component);
  
}
}
