/**
 *   Copyright 2016, Quickstep Research Group, Computer Sciences Department,
 *     University of Wisconsin—Madison.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 **/

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
