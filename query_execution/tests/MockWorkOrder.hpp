/**
 *   Copyright 2016 Pivotal Software, Inc.
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

#ifndef QUICKSTEP_QUERY_EXECUTION_TESTS_MOCK_WORKORDER_HPP_
#define QUICKSTEP_QUERY_EXECUTION_TESTS_MOCK_WORKORDER_HPP_

#include <vector>

#include "query_optimizer/QueryPlan.hpp"
#include "relational_operators/WorkOrder.hpp"
#include "utility/Macros.hpp"

#include "glog/logging.h"

namespace quickstep {

/** \addtogroup QueryExecutionTests
 *  @{
 */

/**
 * @brief A MockWorkOrder for unit tests.
 **/
class MockWorkOrder : public WorkOrder {
 public:
  /**
   * @brief Constructor.
   *
   * @param operator_index The index of the MockOperator in the query plan DAG.
   **/
  explicit MockWorkOrder(const QueryPlan::DAGNodeIndex op_index)
      : op_index_(op_index) {
  }

  void execute() override {
    VLOG(3) << "WorkOrder[" << op_index_ << "] executing.";
  }

  /**
   * @brief Get the operator index.
   *
   * @return The index of the MockOperator in the query plan DAG.
   **/
  inline QueryPlan::DAGNodeIndex getOpIndex() const {
    return op_index_;
  }

 private:
  const QueryPlan::DAGNodeIndex op_index_;

  DISALLOW_COPY_AND_ASSIGN(MockWorkOrder);
};

/** @} */

}  // namespace quickstep

#endif  // QUICKSTEP_QUERY_EXECUTION_TESTS_MOCK_WORKORDER_HPP_
