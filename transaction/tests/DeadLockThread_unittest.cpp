#include "transaction/DeadLockThread.hpp"

#include <thread>

int main() {
  using namespace quickstep;
  LockTable lock_table;
  DeadLockDetectorStatus status = DeadLockDetectorStatus::kNOT_READY;
  std::vector<TransactionId> victims;
  DeadLockThread deadlock_thread(&lock_table, &status, &victims);
  deadlock_thread.start();

  std::thread t([&status]() {
      while (true) {
	while (status == DeadLockDetectorStatus::kNOT_READY) {
	}
	//Process it
	status = DeadLockDetectorStatus::kNOT_READY;
      }
    });

  deadlock_thread.join();
  t.join();
}
