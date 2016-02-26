#ifndef QUICKSTEP_TRANSACTION_TRANSACTION_HPP_
#define QUICKSTEP_TRANSACTION_TRANSACTION_HPP_

#include <cstdint>

namespace quickstep {

using TransactionId = std::uint64_t;

enum class TransactionStatus {
  kRUNNING = 0,
  kABORTED,
  kCOMMITTED
};

class Transaction {
public:
  Transaction(TransactionId tid)
    : tid_(tid) {
  }
  
  TransactionId getTransactionId() const;

  void setStatus(TransactionStatus status);

  TransactionStatus getStatus() const;

  bool operator==(const Transaction &other) const;

  struct TransactionHasher {
    std::size_t operator()(const Transaction &transaction) const;
  };
  
private:
  TransactionId tid_;
  TransactionStatus status_;
  //std::unique_ptr<QueryPlan> query_plan_;
  //std::unique_ptr<TransactionThread> thread_;
};
}

#endif
