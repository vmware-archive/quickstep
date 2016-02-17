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

#include "relational_operators/DropTableOperator.hpp"

#include <vector>

#include "catalog/CatalogDatabase.hpp"
#include "catalog/CatalogRelation.hpp"
#include "catalog/CatalogTypedefs.hpp"
#include "query_execution/WorkOrdersContainer.hpp"
#include "relational_operators/WorkOrder.pb.h"
#include "storage/StorageBlockInfo.hpp"
#include "storage/StorageManager.hpp"

#include "glog/logging.h"

namespace quickstep {

bool DropTableOperator::getAllWorkOrders(WorkOrdersContainer *container) {
  if (blocking_dependencies_met_ && !work_generated_) {
    work_generated_ = true;

    const relation_id rel_id = relation_.getID();
    CatalogRelation *relation = database_->getRelationByIdMutable(rel_id);
    DCHECK(relation != nullptr);

    std::vector<block_id> relation_blocks(relation->getBlocksSnapshot());

    // Create WorkOrder proto that only drops blocks, if any.
    serialization::WorkOrder *proto = new serialization::WorkOrder;
    proto->set_work_order_type(serialization::DROP_TABLE);

    for (const block_id relation_block : relation_blocks) {
      proto->AddExtension(serialization::DropTableWorkOrder::block_ids, relation_block);
    }

    container->addNormalWorkOrder(proto, op_index_);

    // Drop table accordingly.
    // TODO(zuyu): move the following code outside of this function.
    if (only_drop_blocks_) {
      relation->clearBlocks();
    } else {
      database_->dropRelationById(rel_id);
    }
  }
  return work_generated_;
}

void DropTableWorkOrder::execute() {
  for (const block_id relation_block_id : blocks_) {
    storage_manager_->deleteBlockOrBlobFile(relation_block_id);
  }
}

}  // namespace quickstep
