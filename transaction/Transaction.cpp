#include "transaction/Transaction.hpp"

#include <functional>

namespace quickstep {

namespace transaction {

TransactionId Transaction::getTransactionId() const {
  return tid_;
}

void Transaction::setStatus(TransactionStatus status) {
  status_ = status;
}

TransactionStatus Transaction::getStatus() const {
  return status_;
}

bool Transaction::operator==(const Transaction &other) const {
  return tid_ == other.tid_;
}

std::size_t Transaction::TransactionHasher::operator()(const Transaction &transaction) const {
  return std::hash<TransactionId>()(transaction.tid_);
}

}  // namespace transaction

}  // namespace quickstep
