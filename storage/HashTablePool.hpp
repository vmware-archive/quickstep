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

#ifndef QUICKSTEP_STORAGE_HASH_TABLE_POOL_HPP_
#define QUICKSTEP_STORAGE_HASH_TABLE_POOL_HPP_

#include <chrono>
#include <memory>
#include <utility>
#include <vector>

#include "expressions/aggregation/AggregationHandle.hpp"
#include "storage/HashTableBase.hpp"
#include "threading/SpinMutex.hpp"
#include "utility/Macros.hpp"
#include "utility/StringUtil.hpp"

#include "glog/logging.h"

namespace quickstep {

class StorageManager;
class Type;

/** \addtogroup Storage
 *  @{
 */

/**
 * @brief A pool of HashTables used for a single "group by" clause by the
 *        aggregation WorkOrders for reduced contension. This class has similar
 *        functionality as InsertDestination, but for checking out HashTables.
 **/
class HashTablePool {
 public:
  HashTablePool(const std::size_t estimated_num_entries,
                const HashTableImplType hash_table_impl_type,
                const std::vector<const Type *> &group_by_types,
                AggregationHandle *agg_handle,
                StorageManager *storage_manager)
      : estimated_num_entries_(estimated_num_entries / 100),
        hash_table_impl_type_(hash_table_impl_type),
        group_by_types_(group_by_types),
        agg_handle_(DCHECK_NOTNULL(agg_handle)),
        storage_manager_(DCHECK_NOTNULL(storage_manager)) {
        // std::cout << "Agg HT estimated # entries: " << estimated_num_entries << " changing to " << estimated_num_entries_ << "\n";
    /*const std::size_t estimated_num_hash_tables = 20;
    std::cout << "Prepopulating " << estimated_num_hash_tables << " hash tables\n";
    for (std::size_t hash_table_index = 0; hash_table_index < estimated_num_hash_tables; ++hash_table_index) {
      hash_tables_.push_back(std::unique_ptr<AggregationStateHashTableBase>(createNewHashTable()));
    }*/
  }

  AggregationStateHashTableBase* getHashTable() {
    {
      SpinMutexLock lock(mutex_);
      if (!hash_tables_.empty()) {
        std::unique_ptr<AggregationStateHashTableBase> ret_hash_table(std::move(hash_tables_.back()));
        hash_tables_.pop_back();
        DCHECK(ret_hash_table != nullptr);
        return ret_hash_table.release();
      }
    }
    return createNewHashTable();
  }

  void returnHashTable(AggregationStateHashTableBase *hash_table) {
    SpinMutexLock lock(mutex_);
    hash_tables_.push_back(std::unique_ptr<AggregationStateHashTableBase>(hash_table));
  }

  const std::vector<std::unique_ptr<AggregationStateHashTableBase>>*
      getAllHashTables() {
    // std::cout << hash_tables_.size() << " hash tables in the pool\n";
    return &hash_tables_;
  }

 private:
  AggregationStateHashTableBase* createNewHashTable() {
    /*std::chrono::time_point<std::chrono::steady_clock> start, end;
    start = std::chrono::steady_clock::now();*/
    AggregationStateHashTableBase *ret_ht = agg_handle_->createGroupByHashTable(hash_table_impl_type_,
                                               group_by_types_,
                                               estimated_num_entries_,
                                               storage_manager_);
    /*end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> time_ms = end - start;
    printf("Hash table create time %s ms\n",
           DoubleToStringWithSignificantDigits(time_ms.count(), 3).c_str());*/
    return ret_ht;
  }

  std::vector<std::unique_ptr<AggregationStateHashTableBase>> hash_tables_;

  const std::size_t estimated_num_entries_;
  const HashTableImplType hash_table_impl_type_;

  const std::vector<const Type *> group_by_types_;

  AggregationHandle *agg_handle_;
  StorageManager *storage_manager_;

  SpinMutex mutex_;

  DISALLOW_COPY_AND_ASSIGN(HashTablePool);
};

/** @} */

}  // namespace quickstep

#endif  // QUICKSTEP_STORAGE_HASH_TABLE_POOL_HPP_
