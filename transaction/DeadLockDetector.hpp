#ifndef QUICKSTEP_TRANSACTION_DEAD_LOCK_DETECTOR_HPP_
#define QUICKSTEP_TRANSACTION_DEAD_LOCK_DETECTOR_HPP_

#include <memory>
#include <unordered_map>

#include "utility/DAG.hpp"
#include "transaction/Lock.hpp"
#include "transaction/ResourceId.hpp"
#include "transaction/Transaction.hpp"

namespace quickstep {

class DeadLockDetector {
public:
  using DepGraph = DAG<TransactionId, ResourceId>;
  using IdNodeMap = std::unordered_map<TransactionId, DepGraph::size_type_nodes>;
  
  DeadLockDetector(std::uint64_t check_cycle);

  void addPendingInfo(TransactionId pending,
		      TransactionId owner,
		      const ResourceId &rid);

  void deletePendingInfo(TransactionId pending,
			 TransactionId owner);
  
private:
  DepGraph::size_type_nodes getNodeId(TransactionId tid);
  DepGraph::size_type_nodes addNode(TransactionId tid);
  
  std::unique_ptr<DepGraph> wait_for_graph_;
  std::unique_ptr<IdNodeMap> tid_node_mapping_;
  //std::uint64_t counter_;
  //const std::uint64_t check_cycle_;
};
  
}
#endif
