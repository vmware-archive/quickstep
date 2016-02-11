#ifndef QUICKSTEP_TRANSACTION_DEAD_LOCK_DETECTOR_HPP_
#define QUICKSTEP_TRANSACTION_DEAD_LOCK_DETECTOR_HPP_

#include <memory>
#include <unordered_map>
#include <vector>

#include "transaction/DirectedGraph.hpp"
#include "transaction/Lock.hpp"
#include "transaction/LockTable.hpp"
#include "transaction/ResourceId.hpp"
#include "transaction/Transaction.hpp"

namespace quickstep {

class DeadLockDetector {
public:
  using DepGraph = DirectedGraph<TransactionId>;
  using TransactionIdNodeMap = std::unordered_map<TransactionId, DepGraph::NodeId>;
 

  DeadLockDetector(LockTable *lock_table);

  void addPendingInfo(TransactionId pending,
		      TransactionId owner);

  void deleteAllPendingInfo(TransactionId pending,
			    TransactionId owner);

  void deletePendingInfo(TransactionId pending,
			 TransactionId owner);

  // is pending waiting for owner
  bool isDependent(TransactionId pending, TransactionId owner);

  std::vector<TransactionId> getAllDependents(TransactionId owner);

  std::vector<TransactionId> getAllDependees(TransactionId pending);

  // Killing victims means there will be no cycle.
  std::vector<TransactionId> getAllVictims();

private:
  DepGraph::NodeId getNodeId(TransactionId tid);
  
  
  DepGraph::NodeId addNode(TransactionId tid);
  
  
  std::unique_ptr<DepGraph> wait_for_graph_;
  std::unique_ptr<TransactionIdNodeMap> tid_node_mapping_;
  LockTable *lock_table_;
  //std::uint64_t counter_;
  //const std::uint64_t check_cycle_;
};
  
}
#endif
