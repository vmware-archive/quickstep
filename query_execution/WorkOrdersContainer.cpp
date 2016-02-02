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

#include "query_execution/WorkOrdersContainer.hpp"

#include <cstddef>
#include <list>
#include <memory>

#include "relational_operators/WorkOrder.pb.h"

#include "glog/logging.h"

using std::unique_ptr;

namespace quickstep {

WorkOrdersContainer::~WorkOrdersContainer() {
  // For each operator ..
  for (std::size_t op = 0; op < num_operators_; ++op) {
    if (hasNormalWorkOrder(op) || hasRebuildWorkOrder(op)) {
      LOG(WARNING) << "Destroying a WorkOrdersContainer that still has pending WorkOrders.";
      break;
    }
  }
}

serialization::WorkOrder* WorkOrdersContainer::InternalListContainer::getWorkOrderForNUMANode(
    const int numa_node) {
  for (std::list<unique_ptr<serialization::WorkOrder>>::iterator it = workorders_.begin();
       it != workorders_.end();
       ++it) {
    for (int i = 0; i < (*it)->preferred_numa_nodes_size(); ++i) {
      if ((*it)->preferred_numa_nodes(i) == numa_node) {
        serialization::WorkOrder *work_order = it->release();
        workorders_.erase(it);
        return work_order;
      }
    }
  }
  return nullptr;
}

std::size_t
    WorkOrdersContainer::InternalListContainer::getNumWorkOrdersForNUMANode(
    const int numa_node) const {
  std::size_t num_workorders = 0;
  for (const unique_ptr<serialization::WorkOrder> &work_order : workorders_) {
    for (int i = 0; i < work_order->preferred_numa_nodes_size(); ++i) {
      if (work_order->preferred_numa_nodes(i) == numa_node) {
        // Found a match.
       ++num_workorders;
      }
    }
  }
  return num_workorders;
}

bool WorkOrdersContainer::InternalListContainer::hasWorkOrderForNUMANode(
    const int numa_node) const {
  for (const unique_ptr<serialization::WorkOrder> &work_order : workorders_) {
    for (int i = 0; i < work_order->preferred_numa_nodes_size(); ++i) {
      if (work_order->preferred_numa_nodes(i) == numa_node) {
        // Found a match.
        return true;
      }
    }
  }
  return false;
}

void WorkOrdersContainer::OperatorWorkOrdersContainer::addWorkOrder(
    serialization::WorkOrder *workorder) {
  const int numa_nodes_size = workorder->preferred_numa_nodes_size();
  if (numa_nodes_size != 0) {
    if (numa_nodes_size == 1) {
      // This WorkOrder prefers exactly one NUMA node.
      single_numa_node_workorders_[workorder->preferred_numa_nodes(0)]
          .addWorkOrder(workorder);
    } else {
      // This WorkOrder prefers more than one NUMA node.
      multiple_numa_nodes_workorders_.addWorkOrder(workorder);
    }
  } else {
    numa_agnostic_workorders_.addWorkOrder(workorder);
  }
}

serialization::WorkOrder* WorkOrdersContainer::OperatorWorkOrdersContainer::getWorkOrder(
    const bool prefer_single_NUMA_node) {
  // This function tries to get any available WorkOrder.
  serialization::WorkOrder *workorder = numa_agnostic_workorders_.getWorkOrder();
  if (workorder == nullptr) {
    if (prefer_single_NUMA_node) {
      workorder = getSingleNUMANodeWorkOrderHelper();
      if (workorder == nullptr) {
        workorder = multiple_numa_nodes_workorders_.getWorkOrder();
      }
    } else {
      workorder = multiple_numa_nodes_workorders_.getWorkOrder();
      if (workorder == nullptr) {
        workorder = getSingleNUMANodeWorkOrderHelper();
      }
    }
  }
  return workorder;
}

serialization::WorkOrder* WorkOrdersContainer::OperatorWorkOrdersContainer::
    getSingleNUMANodeWorkOrderHelper() {
  serialization::WorkOrder *workorder = nullptr;
  for (PtrVector<InternalQueueContainer>::iterator it =
           single_numa_node_workorders_.begin();
       it != single_numa_node_workorders_.end(); ++it) {
    workorder = it->getWorkOrder();
    if (workorder != nullptr) {
      return workorder;
    }
  }
  return nullptr;
}

}  // namespace quickstep
