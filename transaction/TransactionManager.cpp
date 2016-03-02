#include "transaction/TransactionManager.hpp"

#include <utility>

namespace quickstep {

namespace transaction {

const Transaction& TransactionManager::createTransaction() {
  TransactionId tid = transaction_counter_.fetch_add(1);
  std::pair<TransactionSet::const_iterator, bool> result = transactions_.emplace(tid);
  return *(result.first);
}

}  // namespace transaction

}  // namespace quickstep
