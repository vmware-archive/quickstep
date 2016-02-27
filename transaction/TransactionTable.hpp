#ifndef QUICKSTEP_TRANSACTION_TRANSACTION_TABLE_HPP_
#define QUICKSTEP_TRANSACTION_TRANSACTION_TABLE_HPP_

#include <list>
#include <unordered_map>
#include <utility>
#include <vector>

#include "transaction/Lock.hpp"
#include "transaction/ResourceId.hpp"
#include "transaction/Transaction.hpp"
#include "utility/Macros.hpp"

namespace quickstep {

/** \addtogroup Transaction
 *  @{
 */


/**
 * @brief Represents different result for TransactionTable's methods.
 **/
enum class TransactionTableResult {
  kPLACED_IN_OWNED = 0,
  kPLACED_IN_PENDING,
  kALREADY_IN_OWNED,
  kALREADY_IN_PENDING,
  kDEL_FROM_OWNED,
  kDEL_FROM_PENDING,
  kDEL_ERROR,
  kPUT_ERROR,
  kTRANSACTION_DELETE_OK,
  kTRANSACTION_DELETE_ERROR
};

class TransactionTable {
public:
  using TransactionEntry = std::pair<ResourceId, Lock>;
  using TransactionOwnList = std::list<TransactionEntry>;
  using TransactionPendingList = std::list<TransactionEntry>;
  using TransactionListPair = std::pair<TransactionOwnList, TransactionPendingList>;

  /**
   * @brief Contructor for TransactionTable.
   **/
  TransactionTable();

  /**
   * @brief Puts a owned entry of the given resource id in the given 
   *        transaction's owned list.
   * 
   * @param tid Transaction id of the requestor.
   * @param rid Resource id of the corresponding lock.
   * @param access_mode Access mode of the lock.
   *
   * @return TransactionTableResult::kPLACED_IN_OWNED since it is 
   *         always a successful operation on owned list.
   **/
  TransactionTableResult putOwnEntry(TransactionId tid,
				     const ResourceId &rid,
				     AccessMode access_mode);

  /**
   * @brief Puts a pending entry of the given resource id in the given
   *        transaction's pending list.
   *
   * @param tid Transaction id of the requestor.
   * @param rid Resource id of the corresponding lock.
   * @param access_mode Access mode of the lock.
   *
   * @return TransactionTableResult::kPLACED_IN_PENDING
   **/
  TransactionTableResult putPendingEntry(TransactionId tid,
					 const ResourceId &rid,
					 AccessMode access_mode);

  /**
   * @brief Deletes the owned entry corresponding to the resource id
   *        in the transaction's owned list.
   *
   * @param tid Transaction id of the owner.
   * @param rid Resource id of the corresponding lock.
   * @param access_mode Access mode of the lock.
   *
   * @return TransactionTableResult::kDEL_FROM_OWNED if the entry is deleted,
   *         otherwise TransactionTable::kDEL_ERROR.
   **/
  TransactionTableResult deleteOwnEntry(TransactionId tid,
					const ResourceId &rid,
					AccessMode access_mode);

  /**
   * @brief Deletes the pending entry corresponding to the resource id
   *        in the transaction's pending list.
   * @param tid Transaction id of the owner.
   * @param rid Resource id of the corresponding lock.
   * @param access_mode Access mode of the lock.
   *
   * @return TransactionTableResult::kDEL_FROM_PENDING if the entry is
   *         successfuly deleted, otherwise TransactionTableResult::k_DEL_ERROR.
   **/
  TransactionTableResult deletePendingEntry(TransactionId tid,
					    const ResourceId &rid,
					    AccessMode access_mode);

  /**
   * @brief Returns a vector of resource ids which the corresponding transaction
   *        owns or pends.
   *
   * @param tid Transaction id of the corresponding transaction
   *
   * @return Vector of resource id that the transaction owns or pends.
   **/
  std::vector<ResourceId> getResourceIdList(TransactionId tid);

  /**
   * @brief Deletes the transaction entry from transaction table.
   *
   * @param tid Transaction id of the corresponding transaction.
   *
   * @return TransactionTableResult::kTRANSACTION_DELETE_ERROR if there is no
   *         entry for the transaction, otherwise 
   *         TransactionTableResult::kTRANSACTION_DELETE_OK.
   **/
  TransactionTableResult deleteTransaction(TransactionId tid);
  
private:
  DISALLOW_COPY_AND_ASSIGN(TransactionTable);

  
  std::unordered_map<TransactionId, TransactionListPair> internal_map_;
};

/** @} */

}
#endif
