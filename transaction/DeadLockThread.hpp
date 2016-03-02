#ifndef QUICKSTEP_TRANSACTION_DEADLOCK_THREAD_HPP_
#define QUICKSTEP_TRANSACTION_DEADLOCK_THREAD_HPP_

#include <memory>
#include <vector>

#include "threading/Thread.hpp"
#include "transaction/DeadLockDetector.hpp"

namespace quickstep {

namespace transaction {

/** \addtogroup Transaction
 *  @{
 */

/**
 * @brief Class for representing DeadLockThread status,
 *        kNOT_READY means
 *        kDONE means it will move victims to victims buffer.
 */
enum class DeadLockDetectorStatus {
  kNOT_READY = 0,
  kDONE = 1
};

/**
 * @brief DeadLockThread will run always and check deadlocks,
 *        after checking, it will sleep for 5 seconds.
 */
class DeadLockThread : public Thread {
 public:
  /**
   * @brief Constructor for DeadLockThread
   *
   * @param lock_table Pointer to lock table.
   * @param detector_status Pointer to detector status as a
   *        signal mechanism between this and constructer.
   * @param victim_result Pointer to list of victims for each round,
   *        it is a buffer between this and constructer.
   */
  DeadLockThread(LockTable *lock_table,
                 DeadLockDetectorStatus *detector_status,
                 std::vector<TransactionId> *victim_result);

  /**
   * @brief DeadLockThread class main logic function.
   *        Since its base class is Thread, it is overriden.
   */
  void run() override;

 private:
  // Pointer to lock table. It is needed because it will pass
  // to DeadLockDetector.
  LockTable *lock_table_;

  // Pointer to detector status. Signal mechanism between this
  // and lock manager.
  DeadLockDetectorStatus *detector_status_;

  // Victim buffer, lock manager also has pointer to it.
  std::vector<TransactionId> *victim_result_;

  // Owned pointer to DeadLockDetector. Run method will clear, delete,
  // and create new one for each iteration.
  std::unique_ptr<DeadLockDetector> dead_lock_detector_;
};

/** @} */

}  // namespace transaction

}  // namespace quickstep

#endif
