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

#include "transaction/LockTable.hpp"

namespace quickstep {

namespace transaction {

LockTableResult
LockTable::putLock(TransactionId tid, const ResourceId &rid,
                   AccessMode access_mode) {
  LockListPair &lock_list_pair = internal_map_[rid];

  // Each resource id entry has own list and pending list.
  LockOwnList &lock_own_list = lock_list_pair.first;
  LockPendingList &lock_pending_list = lock_list_pair.second;

  // Check this resource id already has the same lock request from
  // the same transaction in the own list.
  for (LockOwnList::const_iterator it = lock_own_list.cbegin();
       it != lock_own_list.cend(); ++it) {
    if (it->first == tid && it->second.getAccessMode() == access_mode) {
      return LockTableResult::kALREADY_IN_OWNED;
    }
  }

  // Check this resource id already has the same lock request from
  // the same transaction in the pending list.
  for (LockPendingList::const_iterator it = lock_pending_list.cbegin();
       it != lock_pending_list.cend(); ++it) {
    if (it->first == tid && it->second.getAccessMode() == access_mode) {
      return LockTableResult::kALREADY_IN_PENDING;
    }
  }

  // If the execution can reach this point, it means the resource id
  // does not have duplicate lock record (for both in owned and pending).
  if (lock_pending_list.empty()) {
    for (LockOwnList::const_iterator it = lock_own_list.cbegin();
         it != lock_own_list.cend(); ++it) {
      if (!access_mode.isCompatible(it->second.getAccessMode())) {
        lock_pending_list.push_back(std::make_pair(tid,
                                                   Lock(rid, access_mode)));
        return LockTableResult::kPLACED_IN_PENDING;
      }
    }

    lock_own_list.push_back(std::make_pair(tid, Lock(rid, access_mode)));
    return LockTableResult::kPLACED_IN_OWNED;
  } else {
    // If the pending list is not empty, even if the lock request is compatible
    // with other owned lock entries, we put the new request into the pending
    // list to eliminate starvation.
    lock_pending_list.push_back(std::make_pair(tid, Lock(rid, access_mode)));
    return LockTableResult::kPLACED_IN_PENDING;
  }
}

LockTableResult
LockTable::deleteLock(TransactionId tid, const ResourceId &rid) {
  LockListPair &lock_list_pair = internal_map_[rid];

  // Each resource id has its own and pending locks list.
  LockOwnList &lock_own_list = lock_list_pair.first;
  LockPendingList &lock_pending_list = lock_list_pair.second;

  // Iterate over owned locks list to see the lock entry of the transaction
  // on the resource id exists.
  for (LockOwnList::const_iterator it = lock_own_list.begin();
       it != lock_own_list.end(); ++it) {
    if (it->first == tid) {
      // If it exists, erase it from the owned list.
      lock_own_list.erase(it);

      // Since we erased a lock entry from owned list, the first entries
      // in the pending list can be pushed to owned list if they are
      // compatible with the remaining owned entries.
      movePendingToOwned(rid);

      return LockTableResult::kDEL_FROM_OWNED;
    }
  }

  // Iterate over pending locks list to check the lock entry of the transaction
  // on this resource id exists.
  for (LockPendingList::const_iterator it = lock_pending_list.begin(),
	 end = lock_pending_list.end(); it != end; ++it) {
    if (it->first == tid) {
      // If it exists, erase it from pending list.
      lock_pending_list.erase(it);
      return LockTableResult::kDEL_FROM_PENDING;
    }
  }

  // Execution reaches here, if we cannot find the corresponding lock entry
  // in the both list.
  return LockTableResult::kDEL_ERROR;
}

void LockTable::movePendingToOwned(const ResourceId &rid) {
  LockListPair &lock_list_pair = internal_map_[rid];
  LockOwnList &lock_own_list = lock_list_pair.first;
  LockPendingList &lock_pending_list = lock_list_pair.second;

  // Iterate over pending list to pending requests compatible with the
  //all entries in the resource ids owned lock list.
  for (LockPendingList::const_iterator pending_it = lock_pending_list.begin(),
         end = lock_pending_list.end(); pending_it != end; ++pending_it) {
    TransactionId pending_tid = pending_it->first;
    AccessMode pending_mode = pending_it->second.getAccessMode();
    bool is_compatible_with_own_list = true;

    // Now compare against the all entries in the owned lock list.
    for (LockOwnList::const_iterator owned_it = lock_own_list.begin(),
           end = lock_pending_list.end(); owned_it != end; ++owned_it) {
      AccessMode owned_mode = owned_it->second.getAccessMode();

      if (!pending_mode.isCompatible(owned_mode)) {
        // If it is not compatible, we will not move this entry.
        is_compatible_with_own_list = false;
        break;
      }
    }

    // If this pending lock entry is compatible with the all entries in the
    // owned lock list, we should move it from pending list to owned list.
    if (is_compatible_with_own_list) {
      // Erase the entry from the list. Get the new iterator.
      pending_it = lock_pending_list.erase(pending_it);

      // Put the corresponding entry to the own list.
      lock_own_list.emplace_back(pending_tid, Lock(rid, pending_mode));

      // Move iterator one step backward because erasing an element moves the
      // iterator to the next element.
      --pending_it;
    } else {
      // There is no need to iterate pending list anymore since
      // we found first incompatible one. Checking, and accepting other pending
      // entries may cause starvation.
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

}  // namespace transaction

}  // namespace quickstep
