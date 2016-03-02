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

namespace transaction {

/** \addtogroup Transaction
 *  @{
 */

/**
 * @brief Class for deadlock detection on wait-for graph.
 */
class DeadLockDetector {
 public:
  using DepGraph = DirectedGraph;
  using TransactionIdNodeMap = std::unordered_map<TransactionId,
                                                  DepGraph::NodeId>;

  /**
   * @brief Constructor for DeadLockDetector.
   *
   * @param lock_table Pointer to lock table, which this class gets the
   *        necessary information.
   */
  explicit DeadLockDetector(LockTable *lock_table);

  /**
   * @brief Adds pending information based on a resource conflict.
   *
   * @param pending Id of the transaction that waits for the resource lock.
   * @param owner Id of the transaction that owns the resource lock.
   */
  void addPendingInfo(TransactionId pending,
                      TransactionId owner);

  /**
   * @brief Deletes pending information on a resource.
   *
   * @param pending Id of the transaction that waits for the resource lock.
   * @param owner Id of the transaction that owns the resource lock.
   *
   * @warning This method is not implemented yet.
   */
  void deletePendingInfo(TransactionId pending,
                         TransactionId owner);

  /**
   * @brief Check whether first transaction waits for the latter.
   *
   * @param pending Id of the transaction which will be checked whether
   *        it waits for the other.
   * @param owner Id of the transaction which will be checked whether
   *        it is waited by the first.
   *
   * @warning This method is not implemented yet.
   */
  bool isDependent(TransactionId pending, TransactionId owner);

  /**
   * @brief Gives the ids of transactions that wait for the owner transaction.
   *
   * @param owner Id of the transaction whose the penders will be returned.
   * @return Vector of transaction ids that wait for owner.
   */
  std::vector<TransactionId> getAllDependents(TransactionId owner);

  /**
   * @brief Gives the ids of transaction that the pending transaction waits for.
   * @warning This method is not implemented yet.

   * @param pending Id of the transaction that is pending.
   * @return Vector of transaction ids which the pending transaction waits for.
   */
  std::vector<TransactionId> getAllDependees(TransactionId pending);

  /**
   * @brief Gives the list of victims whose the terminations will end the cycle.
   *
   * @return Vector of victim transaction ids.
   */
  std::vector<TransactionId> getAllVictims();

 private:
  DepGraph::NodeId getNodeId(TransactionId tid);

  DepGraph::NodeId addNode(TransactionId tid);

  // Owned pointer to wait-for graph.
  std::unique_ptr<DepGraph> wait_for_graph_;

  // Mapping from TransactioId to NodeId in graph.
  std::unique_ptr<TransactionIdNodeMap> tid_node_mapping_;

  // Pointer to lock table. Dependence edges will be created
  // by the information got from lock table.
  LockTable *lock_table_;
};

/** @} */

}  // namespace transaction

}  // namespace quickstep
#endif
