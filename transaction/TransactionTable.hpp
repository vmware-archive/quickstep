/**
 *   Copyright 2016, Quickstep Research Group, Computer Sciences Department,
 *     University of Wisconsin—Madison.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 **/

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
namespace transaction {

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

/**
 * @brief Class for keeping track of the owner and pending list of transactions.
 **/
class TransactionTable {
 public:
  typedef std::pair<ResourceId, Lock> transaction_entry;
  typedef transaction_own_list std::list<transaction_entry>;
  typedef transaction_pending_list = std::list<transaction_entry>;
  typedef transaction_list_pair = std::pair<transaction_own_list,
                                            transaction_pending_list>;

  /**
   * @brief Contructor for TransactionTable.
   **/
  TransactionTable() {
  }

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
  std::unordered_map<TransactionId, TransactionListPair> internal_map_;

  DISALLOW_COPY_AND_ASSIGN(TransactionTable);
};

/** @} */

}  // namespace transaction
}  // namespace quickstep

#endif
