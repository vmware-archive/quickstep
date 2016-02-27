#include "transaction/LockTable.hpp"

namespace quickstep {

LockTableResult LockTable::putLock(TransactionId tid, const ResourceId &rid, AccessMode access_mode) {
  LockListPair &lock_list_pair = internal_map_[rid];
  LockOwnList &lock_own_list = lock_list_pair.first;
  LockPendingList &lock_pending_list = lock_list_pair.second;
  
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

  if (lock_pending_list.empty()) {
    for (LockOwnList::const_iterator it = lock_own_list.cbegin();
	 it != lock_own_list.cend(); ++it) {
      if (!access_mode.isCompatible(it->second.getAccessMode())) {
	lock_pending_list.push_back(std::make_pair(tid, Lock(rid, access_mode)));
	return LockTableResult::kPLACED_IN_PENDING;
      }
    }

    lock_own_list.push_back(std::make_pair(tid, Lock(rid, access_mode)));
    return LockTableResult::kPLACED_IN_OWNED;
  }
  else {
    lock_pending_list.push_back(std::make_pair(tid, Lock(rid, access_mode)));
    return LockTableResult::kPLACED_IN_PENDING;
  }
}

LockTableResult LockTable::deleteLock(TransactionId tid, const ResourceId &rid) {
  LockListPair &lock_list_pair = internal_map_[rid];
  LockOwnList &lock_own_list = lock_list_pair.first;
  LockPendingList &lock_pending_list = lock_list_pair.second;

  for (LockOwnList::const_iterator it = lock_own_list.begin();
       it != lock_own_list.end();
       ++it) {
    if (it->first == tid) {
      lock_own_list.erase(it);
      
      movePendingToOwned(rid);
      
      return LockTableResult::kDEL_FROM_OWNED;
    }
  }
  for (LockPendingList::const_iterator it = lock_pending_list.begin();
       it != lock_pending_list.end();
       ++it) {
    if (it->first == tid) {
      lock_pending_list.erase(it);
      return LockTableResult::kDEL_FROM_PENDING;
    }
  }
  return LockTableResult::kDEL_ERROR;
};

void LockTable::movePendingToOwned(const ResourceId &rid) {
  LockListPair &lock_list_pair = internal_map_[rid];
  LockOwnList &lock_own_list = lock_list_pair.first;
  LockPendingList &lock_pending_list = lock_list_pair.second;
  
  for (LockPendingList::const_iterator pending_it = lock_pending_list.begin();
       pending_it != lock_pending_list.end();
       ++pending_it) {
    
    TransactionId pending_tid = pending_it->first;
    AccessMode pending_mode = pending_it->second.getAccessMode();
    bool is_compatible_with_own_list = true;
    
    for (LockOwnList::const_iterator owned_it = lock_own_list.begin();
	 owned_it != lock_own_list.end();
	 ++owned_it) {
      AccessMode owned_mode = owned_it->second.getAccessMode();
      
      if(!pending_mode.isCompatible(owned_mode)) {
	is_compatible_with_own_list = false;
	break;
      }
    }
    if (is_compatible_with_own_list) {
      //TODO(Hakan) Check this if logic
      // List erase invalidates the iterator, therefore
      // we reassign pending_it.
      pending_it = lock_pending_list.erase(pending_it);
      lock_own_list.emplace_back(pending_tid, Lock(rid, pending_mode));
      --pending_it;
    }
    else {
      // No need for iterating pending list more since
      // we find first incompatible one.
      break;
    }
  }
}

LockTable::Iterator LockTable::begin() {
  return internal_map_.begin();
}

LockTable::Iterator LockTable::end() {
  return internal_map_.end();
}

LockTable::ConstIterator LockTable::begin() const {
  return internal_map_.begin();
}

LockTable::ConstIterator LockTable::end() const {
  return internal_map_.end();
}

void LockTable::latchShared() {
  mutex_.lockShared();
}

void LockTable::unlatchShared() {
  mutex_.unlockShared();
}

void LockTable::latchExclusive() {
  mutex_.lock();
}

void LockTable::unlatchExclusive() {
  mutex_.unlock();
}

}
