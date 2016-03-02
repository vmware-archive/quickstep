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
