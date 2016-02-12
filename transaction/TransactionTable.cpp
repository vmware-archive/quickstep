#include "transaction/TransactionTable.hpp"

namespace quickstep {

TransactionTable::TransactionTable() {  
}

TransactionTableResult TransactionTable::putOwnEntry(TransactionId tid, const ResourceId &rid, AccessMode access_mode) {
  TransactionListPair &transaction_list_pair = internal_map_[tid];
  TransactionOwnList &transaction_own_list = transaction_list_pair.first;
  
  transaction_own_list.push_back(std::make_pair(rid, Lock(rid, access_mode)));
  
  return TransactionTableResult::kPLACED_IN_OWNED;
}

TransactionTableResult TransactionTable::putPendingEntry(TransactionId tid, const ResourceId &rid, AccessMode access_mode) {
  TransactionListPair &transaction_list_pair = internal_map_[tid];
  TransactionPendingList &transaction_pending_list = transaction_list_pair.second;
  
  transaction_pending_list.push_back(std::make_pair(rid, Lock(rid, access_mode)));
  
  return TransactionTableResult::kPLACED_IN_PENDING;
}

TransactionTableResult TransactionTable::deleteOwnEntry(TransactionId tid, const ResourceId &rid, AccessMode access_mode) {
  TransactionListPair &transaction_list_pair = internal_map_[tid];
  TransactionOwnList &transaction_own_list = transaction_list_pair.first;

  std::size_t original_size = transaction_own_list.size();
  transaction_own_list.remove_if([&rid, &access_mode](TransactionEntry &entry) {
      return entry.second.getResourceId() == rid
	&& entry.second.getAccessMode() == access_mode;
    });
  if (transaction_own_list.size() == original_size) {
    return TransactionTableResult::kDEL_ERROR;
  }
  else {
    return TransactionTableResult::kDEL_FROM_OWNED;
  }
  
}

TransactionTableResult TransactionTable::deletePendingEntry(TransactionId tid, const ResourceId &rid, AccessMode access_mode) {
  TransactionListPair &transaction_list_pair = internal_map_[tid];
  TransactionPendingList &transaction_pending_list = transaction_list_pair.second;

  std::size_t original_size = transaction_pending_list.size();
  transaction_pending_list.remove_if([&rid, &access_mode](TransactionEntry &entry) {
      return entry.second.getResourceId() == rid
	&& entry.second.getAccessMode() == access_mode;
    });

  if (transaction_pending_list.size() == original_size) {
    return TransactionTableResult::kDEL_ERROR;
  }
  else {
    return TransactionTableResult::kDEL_FROM_PENDING;
  }
}

std::vector<ResourceId> TransactionTable::getResourceIdList(TransactionId tid) {
  std::vector<ResourceId> result;
  const TransactionListPair &transaction_list_pair = internal_map_[tid];
  const TransactionOwnList &transaction_own_list = transaction_list_pair.second;
  const TransactionPendingList &transaction_pending_list = transaction_list_pair.first;
  
  for (TransactionOwnList::const_iterator it = transaction_own_list.begin();
       it != transaction_own_list.end();
       ++it) {
    result.push_back(it->first);
  }

  for (TransactionPendingList::const_iterator it = transaction_pending_list.begin();
       it != transaction_pending_list.end();
       ++it) {
    result.push_back(it->first);
  }

  return result;
}

TransactionTableResult TransactionTable::deleteTransaction(TransactionId id) {
  std::size_t original_size = internal_map_.size();
  internal_map_.erase(id);
  std::size_t size_after_delete = internal_map_.size();

  if (original_size == size_after_delete) {
    return  TransactionTableResult::kTRANSACTION_DELETE_ERROR;
  }

  return TransactionTableResult::kTRANSACTION_DELETE_OK;
}

}
