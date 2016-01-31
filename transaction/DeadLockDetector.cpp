#include "transaction/DeadLockDetector.hpp"

namespace quickstep {

DeadLockDetector::DeadLockDetector(std::uint64_t check_cycle)
  : wait_for_graph_(std::make_unique<DAG<TransactionId, ResourceId>>())
  , tid_node_mapping_(std::make_unique<IdNodeMap>())
    //, counter_(0)
    //, check_cycle_(check_cycle)
{}

void DeadLockDetector::addPendingInfo(TransactionId pending,
				      TransactionId owner,
				      const ResourceId &rid) {
  DepGraph::size_type_nodes pending_node_id = getNodeId(pending);
  DepGraph::size_type_nodes owner_node_id = getNodeId(owner);

  // TODO(Hakan): Check first whether link is already created
  wait_for_graph_->createLink(owner_node_id, pending_node_id, rid);
}

void DeadLockDetector::deletePendingInfo(TransactionId pending,
					 TransactionId owner) {
  FATAL_ERROR("Not implemented");
}

DeadLockDetector::DepGraph::size_type_nodes DeadLockDetector::getNodeId(TransactionId tid) {
  DepGraph::size_type_nodes node_id;
  if (tid_node_mapping_->count(tid) == 0) {
    node_id = addNode(tid);
  }
  else {
    node_id = (*tid_node_mapping_)[tid];
  }
  return wait_for_graph_->getNodePayload(node_id);
}

DeadLockDetector::DepGraph::size_type_nodes DeadLockDetector::addNode(TransactionId tid) {
  TransactionId *tid_payload = new TransactionId(tid);
  DepGraph::size_type_nodes node_id = wait_for_graph_->createNode(tid_payload);
  return node_id;
}
}
