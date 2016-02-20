/**
 *   Copyright 2011-2015 Quickstep Technologies LLC.
 *   Copyright 2015-2016 Pivotal Software, Inc.
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

#ifndef QUICKSTEP_RELATIONAL_OPERATORS_BUILD_HASH_OPERATOR_HPP_
#define QUICKSTEP_RELATIONAL_OPERATORS_BUILD_HASH_OPERATOR_HPP_

#include <utility>
#include <vector>

#include "catalog/CatalogRelation.hpp"
#include "catalog/CatalogTypedefs.hpp"
#include "query_execution/QueryContext.hpp"
#include "relational_operators/RelationalOperator.hpp"
#include "relational_operators/WorkOrder.hpp"
#include "storage/HashTable.hpp"
#include "storage/StorageBlockInfo.hpp"
#include "utility/Macros.hpp"

namespace quickstep {

class CatalogRelationSchema;
class StorageManager;
class WorkOrdersContainer;

namespace serialization { class WorkOrder; }

/** \addtogroup RelationalOperators
 *  @{
 */

/**
 * @brief An operator which builds a shared hash table on one
 *        relation.
 **/
class BuildHashOperator : public RelationalOperator {
 public:
  /**
   * @brief Constructor.
   *
   * @param input_relation The relation to build hash table on.
   * @param input_relation_is_stored If input_relation is a stored relation and
   *        is fully available to the operator before it can start generating
   *        workorders.
   * @param join_key_attributes The IDs of equijoin attributes in
   *        input_relation.
   * @param any_join_key_attributes_nullable If any attribute is nullable.
   * @param hash_table_index The index of the JoinHashTable in QueryContext.
   *        The HashTable's key Type(s) should be the Type(s) of the
   *        join_key_attributes in input_relation.
   **/
  BuildHashOperator(const CatalogRelation &input_relation,
                    const bool input_relation_is_stored,
                    const std::vector<attribute_id> &join_key_attributes,
                    const bool any_join_key_attributes_nullable,
                    const QueryContext::join_hash_table_id hash_table_index)
    : input_relation_(input_relation),
      input_relation_is_stored_(input_relation_is_stored),
      join_key_attributes_(join_key_attributes),
      any_join_key_attributes_nullable_(any_join_key_attributes_nullable),
      hash_table_index_(hash_table_index),
      input_relation_block_ids_(input_relation_is_stored ? input_relation.getBlocksSnapshot()
                                                         : std::vector<block_id>()),
      num_workorders_generated_(0),
      started_(false) {}

  ~BuildHashOperator() override {}

  bool getAllWorkOrders(WorkOrdersContainer *container) override;

  void feedInputBlock(const block_id input_block_id,
                      const relation_id input_relation_id) override {
    input_relation_block_ids_.push_back(input_block_id);
  }

  void feedInputBlocks(const relation_id rel_id,
                       std::vector<block_id> *partially_filled_blocks) override {
    input_relation_block_ids_.insert(input_relation_block_ids_.end(),
                                     partially_filled_blocks->begin(),
                                     partially_filled_blocks->end());
  }

 private:
  /**
   * @brief Create Work Order proto.
   *
   * @param block The block id used in the Work Order.
   *
   * @return The created WorkOrder proto.
   **/
  serialization::WorkOrder* createWorkOrderProto(const block_id block) const;

  const CatalogRelation &input_relation_;
  const bool input_relation_is_stored_;
  const std::vector<attribute_id> join_key_attributes_;
  const bool any_join_key_attributes_nullable_;
  const QueryContext::join_hash_table_id hash_table_index_;

  std::vector<block_id> input_relation_block_ids_;
  std::vector<block_id>::size_type num_workorders_generated_;

  bool started_;

  DISALLOW_COPY_AND_ASSIGN(BuildHashOperator);
};

/**
 * @brief A WorkOrder produced by BuildHashOperator
 **/
class BuildHashWorkOrder : public WorkOrder {
 public:
  /**
   * @brief Constructor.
   *
   * @param relation_schema The relation schema to build hash table on.
   * @param build_block_id The block id.
   * @param any_join_key_attributes_nullable If any attribute is nullable.
   * @param join_key_attributes The IDs of equijoin attributes in
   *        'relation_schema'.
   * @param hash_table The The hash table for joins.
   * @param storage_manager The StorageManager to use.
   **/
  BuildHashWorkOrder(const CatalogRelationSchema &relation_schema,
                     const block_id build_block_id,
                     const bool any_join_key_attributes_nullable,
                     std::vector<attribute_id> &&join_key_attributes,
                     JoinHashTable *hash_table,
                     StorageManager *storage_manager)
      : relation_schema_(relation_schema),
        build_block_id_(build_block_id),
        any_join_key_attributes_nullable_(any_join_key_attributes_nullable),
        join_key_attributes_(std::move(join_key_attributes)),
        hash_table_(hash_table),
        storage_manager_(storage_manager) {}

  ~BuildHashWorkOrder() override {}

  void execute() override;

 private:
  const CatalogRelationSchema &relation_schema_;
  const block_id build_block_id_;
  const bool any_join_key_attributes_nullable_;
  const std::vector<attribute_id> join_key_attributes_;
  JoinHashTable *hash_table_;
  StorageManager *storage_manager_;

  DISALLOW_COPY_AND_ASSIGN(BuildHashWorkOrder);
};

/** @} */

}  // namespace quickstep

#endif  // QUICKSTEP_RELATIONAL_OPERATORS_BUILD_HASH_OPERATOR_HPP_
