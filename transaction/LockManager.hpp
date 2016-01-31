#ifndef QUICKSTEP_TRANSACTION_LOCK_MANAGER_HPP_
#define QUICKSTEP_TRANSACTION_LOCK_MANAGER_HPP_

#include "threading/Mutex.hpp"
#include "transaction/AccessMode.hpp"
#include "transaction/DeadLockDetector.hpp"
#include "transaction/LockTable.hpp"
#include "transaction/ResourceId.hpp"
#include "transaction/Transaction.hpp"
#include "transaction/TransactionTable.hpp"

namespace quickstep {
  
class LockManager {
public:
  LockManager();
  
  bool acquireLock(TransactionId tid,
		   const ResourceId &rid,
		   AccessMode access_mode);

  bool releaseAllLocks(TransactionId tid,
		       const ResourceId &rid,
		       AccessMode access_mode);
private:
  bool acquireLockInternal(TransactionId tid,
			   const ResourceId &rid,
			   AccessMode access_mode);

  std::unique_ptr<LockTable> lock_table_;
  std::unique_ptr<TransactionTable> transaction_table_;
  std::unique_ptr<DeadLockDetector> deadlock_detector_;
  
  Mutex mutex_;
};

}
#endif
