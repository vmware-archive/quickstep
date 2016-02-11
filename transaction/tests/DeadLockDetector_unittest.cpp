#include "transaction/DeadLockDetector.hpp"

#include "gtest/gtest.h"

namespace quickstep {

TEST(DeadLockDetector, AddDependency) {
  TransactionId tid1 = TransactionId(1);
  TransactionId tid2 = TransactionId(2);

  LockTable lock_table;
  DeadLockDetector dead_lock_detector(&lock_table);

  dead_lock_detector.addPendingInfo(tid1, tid2);
  EXPECT_TRUE(dead_lock_detector.isDependent(tid2, tid1));
  
  //dead_lock_detector.addPendingInfo(tid1, tid2, ResourceId(4, 2));
  //EXPECT_TRUE(dead_lock_detector.isDependent(tid2, tid1));
  
  
}

}
