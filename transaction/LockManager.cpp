#include "transaction/LockManager.hpp"

#include <stack>
#include <utility>

namespace quickstep {
  LockManager::LockManager()
    : lock_table_(std::make_unique<LockTable>())
    , transaction_table_(std::make_unique<TransactionTable>()) {}
  
  bool LockManager::acquireLock(TransactionId tid,
				const ResourceId &rid,
				AccessMode access_mode) {
    std::stack<std::pair<ResourceId, AccessMode>> stack;
    ResourceId current_rid = rid;
    AccessMode current_access_mode = access_mode;
    stack.push(std::make_pair(current_rid, current_access_mode));
    
    while (current_rid.hasParent()) {
      current_rid = rid.getParentResourceId();
      current_access_mode =
	(current_access_mode.isShareLock() ||
	 current_access_mode.isIntentionShareLock())
	? AccessMode::AccessModeType::kIS_LOCK
	: AccessMode::AccessModeType::kIX_LOCK;

      stack.push(std::make_pair(current_rid, current_access_mode));
    }

    while (!stack.empty()) {
      std::pair<ResourceId, AccessMode> pair_to_pick = stack.top();
      ResourceId rid_to_pick = pair_to_pick.first;
      AccessMode access_mode_to_pick = pair_to_pick.second;

      bool result = acquireLockInternal(tid,
					rid_to_pick,
					access_mode_to_pick);
      if (!result) {
	return false;
      }
      stack.pop();
    }
    
    return true;
  }

  bool LockManager::releaseAllLocks(TransactionId tid,
				    const ResourceId &rid,
				    AccessMode access_mode) {
    return true;
  }

  // If not blocked return true
  // if block return false
  bool LockManager::acquireLockInternal(TransactionId tid,
					const ResourceId &rid,
					AccessMode access_mode) {
    MutexLock lock(mutex_);
    LockTableResult l_result = lock_table_->putLock(tid, rid, access_mode);
    if (l_result == LockTableResult::kPUT_ERROR) {
      FATAL_ERROR("Unexpected result in LockManager.acquireLockInternal");
    }

    if (l_result == LockTableResult::kALREADY_IN_OWNED) {
      return true;
    }
    else if (l_result == LockTableResult::kPLACED_IN_OWNED) {
      TransactionTableResult t_result = transaction_table_->putOwnEntry(tid, rid, access_mode);
      if (t_result != TransactionTableResult::kPLACED_IN_OWNED) {
	FATAL_ERROR("Unexpected result in LockManager.acquireLockInternal: "
		    "Mismatch of table results No1.");
      }
      return true;
    }
    else if (l_result == LockTableResult::kALREADY_IN_PENDING) {
      return false;
    }
    else if (l_result == LockTableResult::kPLACED_IN_PENDING) {
       TransactionTableResult t_result =
	 transaction_table_->putPendingEntry(tid, rid, access_mode);
       if (t_result != TransactionTableResult::kPLACED_IN_PENDING) {
	 FATAL_ERROR("Unexpected result in LockManager.acquireLockInternal: "
		     "Mismatch of table results No2.");
       }
      return false;
    }
    return false;
  }
}

