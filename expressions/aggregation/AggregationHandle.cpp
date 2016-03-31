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

#include "expressions/aggregation/AggregationHandle.hpp"

#include <cstddef>
#include <memory>
#include <vector>

#include "catalog/CatalogTypedefs.hpp"
#include "storage/HashTable.hpp"
#include "storage/HashTableFactory.hpp"

namespace quickstep {

class StorageManager;
class Type;
class ValueAccessor;

AggregationStateHashTableBase* AggregationHandle::createDistinctifyHashTable(
    const HashTableImplType hash_table_impl,
    const std::vector<const Type*> &key_types,
    const std::size_t estimated_num_distinct_keys,
    StorageManager *storage_manager) const {
  return AggregationStateHashTableFactory<bool>::CreateResizable(
      hash_table_impl,
      key_types,
      estimated_num_distinct_keys,
      storage_manager);
}

void AggregationHandle::insertValueAccessorIntoDistinctifyHashTable(
    ValueAccessor *accessor,
    const std::vector<attribute_id> &key_ids,
    AggregationStateHashTableBase *distinctify_hash_table) const {
  const auto noop_upserter = [](const auto &accessor, const bool *value) -> void {};

  AggregationStateHashTable<bool> *hash_table =
      static_cast<AggregationStateHashTable<bool>*>(distinctify_hash_table);
  if (key_ids.size() == 1) {
    hash_table->upsertValueAccessor(accessor,
                                    key_ids[0],
                                    true,
                                    true, /* Initial value */
                                    &noop_upserter);
  } else {
    hash_table->upsertValueAccessorCompositeKey(accessor,
                                                key_ids,
                                                true,
                                                true, /* Initial value */
                                                &noop_upserter);
  }
}

}  // namespace quickstep
