#include "transaction/Transaction.hpp"

#include <functional>

namespace quickstep {

bool Transaction::operator==(const Transaction &other) const {
  return tid_ == other.tid_;
}

std::size_t Transaction::TransactionHasher::operator()(const Transaction &transaction) const {
  return std::hash<TransactionId>()(transaction.tid_);
}

}
