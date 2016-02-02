#ifndef QUICKSTEP_TRANSACTION_DEAD_LOCK_DETECTOR_HPP_
#define QUICKSTEP_TRANSACTION_DEAD_LOCK_DETECTOR_HPP_

#include <memory>
#include <unordered_map>
#include <vector>

#include "utility/DAG.hpp"
#include "transaction/Lock.hpp"
#include "transaction/ResourceId.hpp"
#include "transaction/Transaction.hpp"

namespace quickstep {

class DeadLockDetector {
public:
  using DepGraph = DAG<TransactionId, ResourceId>;
  using TransactionIdNodeMap = std::unordered_map<TransactionId, DepGraph::size_type_nodes>;
  using ResourceIdNodeMap = std::unordered_map<ResourceId,
					       DepGraph::size_type_nodes,
					       ResourceId::ResourceIdHasher>;

  DeadLockDetector();

  void addPendingInfo(TransactionId pending,
		      TransactionId owner,
		      const ResourceId &rid);

  void deleteAllPendingInfo(TransactionId pending,
			    TransactionId owner);

  void deletePendingInfo(TransactionId pending,
			 TransactionId owner,
			 const ResourceId &rid);

  // is pending waiting for owner
  bool isDependent(TransactionId pending, TransactionId owner);

  std::vector<TransactionId> getAllDependents(TransactionId owner);

  std::vector<TransactionId> getAllDependees(TransactionId pending);

private:
  DepGraph::size_type_nodes getNodeId(TransactionId tid);
  DepGraph::size_type_nodes getNodeId(const ResourceId &rid);
  
  DepGraph::size_type_nodes addNode(TransactionId tid);
  DepGraph::size_type_nodes addNode(const ResourceId &rid);
  
  std::unique_ptr<DepGraph> wait_for_graph_;
  std::unique_ptr<TransactionIdNodeMap> tid_node_mapping_;
  std::unique_ptr<ResourceIdNodeMap> rid_node_mapping_;
  //std::uint64_t counter_;
  //const std::uint64_t check_cycle_;
};
  
}
#endif
