#include "transaction/DeadLockDetector.hpp"

#include "gtest/gtest.h"

namespace quickstep {

TEST(DeadLockDetector, DeadLockExists) {
  TransactionId tid1 = TransactionId(1);
  TransactionId tid2 = TransactionId(2);

  LockTable lock_table;
  lock_table.putLock(tid1, ResourceId(1,1,2), AccessMode::AccessModeType::kX_LOCK);
  lock_table.putLock(tid2, ResourceId(1,1,1), AccessMode::AccessModeType::kX_LOCK);
  lock_table.putLock(tid2, ResourceId(1,1,2), AccessMode::AccessModeType::kX_LOCK);
  lock_table.putLock(tid1, ResourceId(1,1,1), AccessMode::AccessModeType::kX_LOCK);
  
  DeadLockDetector dead_lock_detector(&lock_table);
  
  std::vector<TransactionId> victims = dead_lock_detector.getAllVictims();

  
  EXPECT_EQ(1, victims.size());
  
  //dead_lock_detector.addPendingInfo(tid1, tid2, ResourceId(4, 2));
  //EXPECT_TRUE(dead_lock_detector.isDependent(tid2, tid1));
  
  
}

}
