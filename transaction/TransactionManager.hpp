#ifndef QUICKSTEP_TRANSACTION_TRANSACTION_MANAGER_HPP_
#define QUICKSTEP_TRANSACTION_TRANSACTION_MANAGER_HPP_

#include <atomic>
#include <unordered_set>

#include "transaction/Transaction.hpp"
#include "utility/Macros.hpp"

namespace quickstep {

namespace transaction {

class TransactionManager {
 public:
  TransactionManager()
    : transaction_counter_(0) {
  }

  const Transaction& createTransaction();

 private:
  using TransactionSet = std::unordered_set<Transaction,
                                            Transaction::TransactionHasher>;

  std::atomic<TransactionId> transaction_counter_;
  TransactionSet transactions_;

  DISALLOW_COPY_AND_ASSIGN(TransactionManager);
};

}  // namespace transaction

}  // namespace quickstep

#endif
