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

  // TODO(Hakan): Using list is overkill since one pending entry
  //              will be in list each time.
  using TransactionPendingList = std::list<TransactionEntry>;
  using TransactionListPair = std::pair<TransactionOwnList, TransactionPendingList>;
  
  TransactionTable();

  TransactionTableResult putOwnEntry(TransactionId tid,
				     const ResourceId &rid,
				     AccessMode access_mode);

  TransactionTableResult putPendingEntry(TransactionId tid,
					 const ResourceId &rid,
					 AccessMode access_mode);
  
  TransactionTableResult deleteOwnEntry(TransactionId tid,
					const ResourceId &rid,
					AccessMode access_mode);

  TransactionTableResult deletePendingEntry(TransactionId tid,
					    const ResourceId &rid,
					    AccessMode access_mode);

  std::vector<ResourceId> getResourceIdList(TransactionId tid);

  TransactionTableResult deleteTransaction(TransactionId tid);
  
private:
  DISALLOW_COPY_AND_ASSIGN(TransactionTable);

  std::unordered_map<TransactionId, TransactionListPair> internal_map_;
};
  
}

#endif
