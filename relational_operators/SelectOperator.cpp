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

#include "relational_operators/SelectOperator.hpp"

#include <vector>

#include "catalog/CatalogRelationSchema.hpp"
#include "query_execution/WorkOrdersContainer.hpp"
#include "relational_operators/WorkOrder.pb.h"
#include "storage/InsertDestination.hpp"
#include "storage/StorageBlock.hpp"
#include "storage/StorageBlockInfo.hpp"
#include "storage/StorageManager.hpp"

#include "glog/logging.h"

namespace quickstep {

serialization::WorkOrder* SelectOperator::createWorkOrderProto(const block_id block) const {
  serialization::WorkOrder *proto = new serialization::WorkOrder;
  proto->set_work_order_type(serialization::SELECT);

  proto->SetExtension(serialization::SelectWorkOrder::relation_id, input_relation_.getID());
  proto->SetExtension(serialization::SelectWorkOrder::insert_destination_index, output_destination_index_);
  proto->SetExtension(serialization::SelectWorkOrder::predicate_index, predicate_index_);
  proto->SetExtension(serialization::SelectWorkOrder::block_id, block);
  proto->SetExtension(serialization::SelectWorkOrder::simple_projection, simple_projection_);
  if (simple_projection_) {
    for (const attribute_id attr_id : *simple_selection_) {
      proto->AddExtension(serialization::SelectWorkOrder::simple_selection, attr_id);
    }
  }
  proto->SetExtension(serialization::SelectWorkOrder::selection_index, selection_index_);

  return proto;
}

bool SelectOperator::getAllWorkOrders(WorkOrdersContainer *container) {
  if (input_relation_is_stored_) {
    if (!started_) {
      for (const block_id input_block_id : input_relation_block_ids_) {
        container->addNormalWorkOrder(createWorkOrderProto(input_block_id), op_index_);
      }
      started_ = true;
    }
    return started_;
  } else {
    while (num_workorders_generated_ < input_relation_block_ids_.size()) {
      container->addNormalWorkOrder(
          createWorkOrderProto(input_relation_block_ids_[num_workorders_generated_]),
          op_index_);
      ++num_workorders_generated_;
    }
    return done_feeding_input_relation_;
  }
}

void SelectWorkOrder::execute() {
  BlockReference block(
      storage_manager_->getBlock(input_block_id_, input_relation_schema_));

  if (simple_projection_) {
    block->selectSimple(simple_selection_,
                        predicate_,
                        output_destination_);
  } else {
    DCHECK(selection_ != nullptr);
    block->select(*selection_,
                  predicate_,
                  output_destination_);
  }
}

}  // namespace quickstep
