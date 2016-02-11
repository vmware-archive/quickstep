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

void DeadLockThread::run() {
  while (true) {
    dead_lock_detector_.release();
    dead_lock_detector_ = std::make_unique<DeadLockDetector>(lock_table_);
    std::cout << "DeadLockDetector detection starts.\n";
    std::vector<TransactionId> victims = dead_lock_detector_->getAllVictims();
    *detector_status_ = DeadLockDetectorStatus::kDONE;
    *victim_result_ = std::move(victims);
    std::cout << "DeadLockDetector detection ends.\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));

    while (*detector_status_ == DeadLockDetectorStatus::kDONE) {
    }
  }
}

}
