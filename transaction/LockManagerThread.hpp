#ifndef QUICKSTEP_TRANSACTION_LOCK_MANAGER_THREAD_HPP_
#define QUICKSTEP_TRANSACTION_LOCK_MANAGER_THREAD_HPP_

#include <queue>

#include "threading/Thread.hpp"
#include "transaction/LockManager.hpp"
#include "transaction/LockRequest.hpp"
#include "utility/ThreadSafeQueue.hpp"

namespace quickstep {

class LockManagerThread : public Thread {
public:
  LockManagerThread(ThreadSafeQueue<LockRequest> *incoming_requests,
		    ThreadSafeQueue<LockRequest> *permitted_requests);

  void run() override;
  
private:
  std::unique_ptr<LockManager> lock_manager_;
  ThreadSafeQueue<LockRequest> *incoming_requests_;
  ThreadSafeQueue<LockRequest> *permitted_requests_;
  
  std::queue<LockRequest> inner_pending_requests_;
  
}; 
}
#endif
