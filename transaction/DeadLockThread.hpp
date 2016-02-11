#ifndef QUICKSTEP_TRANSACTION_DEADLOCK_THREAD_HPP_
#define QUICKSTEP_TRANSACTION_DEADLOCK_THREAD_HPP_

#include "threading/Thread.hpp"
#include "transaction/DeadLockDetector.hpp"

#include <memory>
#include <vector>

namespace quickstep {

enum class DeadLockDetectorStatus {
  kNOT_READY = 0,
  kDONE = 1
};

class DeadLockThread : public Thread {
public:
  DeadLockThread(LockTable *lock_table,
		 DeadLockDetectorStatus *detector_status,
		 std::vector<TransactionId> *victim_result);
  
  void run() override;
private:
  LockTable *lock_table_;
  DeadLockDetectorStatus *detector_status_;
  std::vector<TransactionId> *victim_result_;
  std::unique_ptr<DeadLockDetector> dead_lock_detector_;
 
  
};

}

#endif
