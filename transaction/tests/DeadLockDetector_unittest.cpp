#include "transaction/DeadLockDetector.hpp"

#include "gtest/gtest.h"

namespace quickstep {

TEST(DeadLockDetector, AddDependency) {
  TransactionId tid1 = TransactionId(1);
  TransactionId tid2 = TransactionId(2);

  DeadLockDetector dead_lock_detector;

  dead_lock_detector.addPendingInfo(tid1, tid2, ResourceId(3, 4, 5));
  EXPECT_TRUE(dead_lock_detector.isDependent(tid2, tid1));
  
  //dead_lock_detector.addPendingInfo(tid1, tid2, ResourceId(4, 2));
  //EXPECT_TRUE(dead_lock_detector.isDependent(tid2, tid1));
  
  
}

}
