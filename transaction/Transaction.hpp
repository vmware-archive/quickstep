#ifndef QUICKSTEP_TRANSACTION_TRANSACTION_HPP_
#define QUICKSTEP_TRANSACTION_TRANSACTION_HPP_

#include <cstdint>

namespace quickstep {
  
using TransactionId = std::uint64_t;

class Transaction {
public:
  TransactionId getTID();
private:
  Transaction(TransactionId tid);
  
  TransactionId tid_;
  //std::unique_ptr<QueryPlan> query_plan_;
  //std::unique_ptr<TransactionThread> thread_;
};
}

#endif
