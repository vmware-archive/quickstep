#include "transaction/DeadLockThread.hpp"

namespace quickstep {

DeadLockThread::DeadLockThread(LockTable *lock_table,
			       DeadLockDetectorStatus *detector_status,
			       std::vector<TransactionId> *victim_result)
  : lock_table_(lock_table)
  , detector_status_(detector_status)
  , victim_result_(victim_result)
  , dead_lock_detector_(nullptr) {
}

// Infinite loop for thread logic:
// 1-) Reinitiate DeadLockDetector.
// 2-) Run deadlock detection alogrithm on lock table.
// 3-) Pass results to the victim result buffer.
// 4-) Signal status with kDONE.
// 5-) Sleep for 5 seconds.
// 6-) Do not go to the beginning of the loop if status
//     is still kDONE.
void DeadLockThread::run() {
  while (true) {
    dead_lock_detector_.release();
    dead_lock_detector_ = std::make_unique<DeadLockDetector>(lock_table_);

    std::cout << "DeadLockDetector detection starts.\n";

   
   
    std::vector<TransactionId> victims = dead_lock_detector_->getAllVictims();

    std::cout << "Victim size: " + std::to_string(victims.size()) + "\n"; 

    
    *victim_result_ = std::move(victims);
    *detector_status_ = DeadLockDetectorStatus::kDONE;

    
    
    std::cout << "DeadLockDetector detection ends.\n";

    std::this_thread::sleep_for(std::chrono::seconds(5));

    while (*detector_status_ == DeadLockDetectorStatus::kDONE) {
    }
  }
}

}
