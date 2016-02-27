#ifndef QUICKSTEP_TRANSACTION_LOCK_MANAGER_THREAD_HPP_
#define QUICKSTEP_TRANSACTION_LOCK_MANAGER_THREAD_HPP_

#include <queue>

#include "threading/Thread.hpp"
#include "transaction/LockManager.hpp"
#include "transaction/LockRequest.hpp"
#include "utility/ThreadSafeQueue.hpp"

namespace quickstep {

/** \addtogroup Transaction 
 *  @{
 */ 

/**
 * @brief Class for the thread runs on LockManager.
 */
class LockManagerThread : public Thread {
public:
  /**
   * @brief Constructor for LockManagerThread. Initial point
   *        for Transaction module.
   * 
   * @param incoming_requests Pointer to queue for incoming lock requests.
   * @param permitted_requests Pointer to the queue for outputting permitted
   *        lock requests. 
   */
  LockManagerThread(ThreadSafeQueue<LockRequest> *incoming_requests,
		    ThreadSafeQueue<LockRequest> *permitted_requests);

  /**
   * @brief Main logic loop for LockManagerThread.
   */
  void run() override;
  
private:
  // Owner pointer to lock mananager.
  std::unique_ptr<LockManager> lock_manager_;

  // Pointer to incoming buffer.
  ThreadSafeQueue<LockRequest> *incoming_requests_;

  // Pointer to output buffer.
  ThreadSafeQueue<LockRequest> *permitted_requests_;

  // Buffer for the requests popped from incoming but cannot
  // grant the lock for them.
  std::queue<LockRequest> inner_pending_requests_;
};

/** @} */

}
#endif
