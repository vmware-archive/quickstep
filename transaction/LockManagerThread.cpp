#include "transaction/LockManagerThread.hpp"

#include "transaction/LockManager.hpp"

namespace quickstep {

LockManagerThread::LockManagerThread(ThreadSafeQueue<LockRequest> *incoming_requests,
				     ThreadSafeQueue<LockRequest> *permitted_requests)
  : lock_manager_(std::make_unique<LockManager>())
  , incoming_requests_(incoming_requests)
  , permitted_requests_(permitted_requests)
  , inner_pending_requests_() {
}

void LockManagerThread::run() {
  constexpr std::uint64_t max_try_incoming = 50;
  constexpr std::uint64_t max_try_inner = 60; 
  while (true) {
    for (std::uint64_t tries = 0; tries < max_try_incoming; ++tries) {
      if (!incoming_requests_->empty()) {
	LockRequest request = incoming_requests_->popOne();
	bool result = lock_manager_->acquireLock(request.getTransactionId(),
						 request.getResourceId(),
						 request.getAccessMode());
	if (!result) {
	  inner_pending_requests_.push(request);
	}
      }
    }
    for (std::uint64_t tries = 0; tries < max_try_inner; ++tries) {
      if (!inner_pending_requests_.empty()) {
	LockRequest request = inner_pending_requests_.front();
	inner_pending_requests_.pop();
	bool result = lock_manager_->acquireLock(request.getTransactionId(),
						 request.getResourceId(),
						 request.getAccessMode());
	if (!result) {
	  inner_pending_requests_.push(request);
	}
      }
    }
  }
}

}
