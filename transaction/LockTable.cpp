#include "transaction/LockTable.hpp"

namespace quickstep {

  LockTableResult LockTable::putLock(TransactionId tid, const ResourceId &rid, AccessMode access_mode) {
    LockListPair &lock_list_pair = internal_map_[rid];
    LockOwnList &lock_own_list = lock_list_pair.first;
    LockPendingList &lock_pending_list = lock_list_pair.second;

    // TODO(Hakan): Checking whether a transaction owns or pends a lock
    //              in transaction table is faster.
    for (LockOwnList::const_iterator it = lock_own_list.cbegin();
	 it != lock_own_list.cend(); ++it) {
      if (it->first == tid && it->second.getAccessMode() == access_mode) {
	return LockTableResult::kALREADY_IN_OWNED;
      }
    }

    for (LockPendingList::const_iterator it = lock_pending_list.cbegin();
	 it != lock_pending_list.cend(); ++it) {
      if (it->first == tid && it->second.getAccessMode() == access_mode) {
	return LockTableResult::kALREADY_IN_PENDING;
      }
    }

    // TODO(Hakan): Second iteration over pending list might be carried to above.
    if (lock_pending_list.empty()) {
      for (LockOwnList::const_iterator it = lock_own_list.cbegin();
	   it != lock_own_list.cend(); ++it) {
	if (!access_mode.isCompatible(it->second.getAccessMode())) {
	  lock_pending_list.push_back(std::make_pair(tid, Lock(rid, access_mode)));
	  return LockTableResult::kPLACED_IN_PENDING;
	}
      }

      lock_own_list.push_back(std::make_pair(tid, Lock(rid, access_mode)));
      return LockTableResult::kALREADY_IN_OWNED;
    }
    else {
      lock_pending_list.push_back(std::make_pair(tid, Lock(rid, access_mode)));
      return LockTableResult::kPLACED_IN_PENDING;
    }
  }
}
