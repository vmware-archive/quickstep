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
  constexpr std::uint64_t max_try_incoming = 100;
  constexpr std::uint64_t max_try_inner = 60; 
  while (true) {
    std::cout << "LMT: Loop starts\n";
    for (std::uint64_t tries = 0; tries < max_try_incoming; ++tries) {
      if (!incoming_requests_->empty()) {
	LockRequest request = incoming_requests_->popOne();
	if (request.getRequestType() == RequestType::kRELEASE_LOCKS) {
	  bool result = lock_manager_->releaseAllLocks(request.getTransactionId());
	  if (!result) {
	    FATAL_ERROR("It should not arrive at this point!!");
	  }
	}
	else {
	  bool result = lock_manager_->acquireLock(request.getTransactionId(),
						 request.getResourceId(),
						 request.getAccessMode());
	  if (!result) {
	    std::cout << "Transaction " + std::to_string(request.getTransactionId())
	      + " waiting " + request.getResourceId().toString() + "\n";

	    inner_pending_requests_.push(request);
	    
	  }
	  else {
	    std::cout << "Transaction " + std::to_string(request.getTransactionId())
	      + " acquired " + request.getResourceId().toString() + "\n";
	    permitted_requests_->push(request);
	  }
	}
      }
    }
    for (std::uint64_t tries = 0; tries < max_try_inner; ++tries) {
      if (!inner_pending_requests_.empty()) {
	LockRequest request = inner_pending_requests_.front();
	
	bool result = lock_manager_->acquireLock(request.getTransactionId(),
						 request.getResourceId(),
						 request.getAccessMode());
	if (result) {
	  inner_pending_requests_.pop();
	  permitted_requests_->push(request);
	}
      }
    }
    std::cout << "LMT: Killing victims\n";
    lock_manager_->killVictims();
  }
}

}
