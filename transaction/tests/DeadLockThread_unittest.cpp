#include "transaction/DeadLockThread.hpp"

#include <thread>  // NOLINT(build/c++11)
#include <vector>

int main() {
  using namespace quickstep::transaction;  // NOLINT(build/namespaces)
  LockTable lock_table;
  DeadLockDetectorStatus status = DeadLockDetectorStatus::kNOT_READY;
  std::vector<TransactionId> victims;
  DeadLockThread deadlock_thread(&lock_table, &status, &victims);
  deadlock_thread.start();

  std::thread t([&status]() {
      while (true) {
        while (status == DeadLockDetectorStatus::kNOT_READY) {
        }
        // Process it.
        status = DeadLockDetectorStatus::kNOT_READY;
      }
    });

  deadlock_thread.join();
  t.join();
}
