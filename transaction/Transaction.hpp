#ifndef QUICKSTEP_TRANSACTION_TRANSACTION_HPP_
#define QUICKSTEP_TRANSACTION_TRANSACTION_HPP_

#include <cstdint>

namespace quickstep {
  
using TransactionId = std::uint64_t;

class Transaction {
public:
  Transaction(TransactionId tid)
    : tid_(tid) {
  }
  
  TransactionId getTransactionId() const;

  bool operator==(const Transaction &other) const;

  struct TransactionHasher {
    std::size_t operator()(const Transaction &transaction) const;
  };
  
private:
  TransactionId tid_;
  //std::unique_ptr<QueryPlan> query_plan_;
  //std::unique_ptr<TransactionThread> thread_;
};
}

#endif
