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

#ifndef QUICKSTEP_QUERY_EXECUTION_POLICY_ENFORCER_HPP_
#define QUICKSTEP_QUERY_EXECUTION_POLICY_ENFORCER_HPP_

#include <cstddef>
#include <memory>
#include <queue>
#include <unordered_map>
#include <vector>

#include "query_execution/QueryManager.hpp"
#include "query_execution/WorkerMessage.hpp"
#include "utility/Macros.hpp"

#include "tmb/id_typedefs.h"
#include "tmb/message_bus.h"
#include "tmb/tagged_message.h"

namespace quickstep {

class CatalogDatabase;
class StorageManager;
class WorkerDirectory;

/**
 * @brief A class that ensures that a high level policy is maintained
 *        in sharing resources among concurrent queries.
 **/
class PolicyEnforcer {
 public:
  /**
   * @brief Constructor.
   *
   * @param foreman_client_id The TMB client ID of the Foreman.
   * @param num_numa_nodes Number of NUMA nodes used by the system.
   * @param worker_directory The WorkerDirectory.
   * @param catalog_database The CatalogDatabase used.
   * @param storage_manager The StorageManager used.
   * @param bus The TMB.
   **/
  PolicyEnforcer(const tmb::client_id foreman_client_id,
                 const std::size_t num_numa_nodes,
                 const WorkerDirectory &worker_directory,
                 CatalogDatabaseLite *catalog_database,
                 StorageManager *storage_manager,
                 tmb::MessageBus *bus)
      : foreman_client_id_(foreman_client_id),
        num_numa_nodes_(num_numa_nodes),
        worker_directory_(worker_directory),
        catalog_database_(catalog_database),
        storage_manager_(storage_manager),
        bus_(bus) {}

  /**
   * @brief Admit a query to the system.
   *
   * @param query_handle The QueryHandle for the new query.
   *
   * @return Whether the query was admitted to the system.
   **/
  bool admitQuery(QueryHandle *query_handle);

  /**
   * @brief Admit multiple queries in the system.
   *
   * @param query_handles A vector of QueryHandles for the queries to be
   *        admitted.
   *
   * @return True if all the queries were admitted, false if at least one query
   *         was not admitted.
   **/
  bool admitQueries(std::vector<QueryHandle*> query_handles) {
    LOG(ERROR) << "PolicyEnforcer::admitQueries is not supported right now.";
    return false;
  }

  /**
   * @brief Get worker messages to be dispatched. These worker messages come
   *        from the active queries.
   *
   * @param worker_messages The worker messages to be dispatched.
   **/
  void getWorkerMessages(
      std::vector<std::unique_ptr<WorkerMessage>> *worker_messages);

  /**
   * @brief Process a message sent to the Foreman, which gets passed on to the
   *        policy enforcer.
   *
   * @param message The message.
   **/
  void processMessage(const TaggedMessage &tagged_message);

  /**
   * @brief Check if there are any queries to be executed.
   *
   * @return True if there is at least one active or waiting query, false if
   *         the policy enforcer doesn't have any query.
   **/
  inline bool hasQueries() const {
    return !(admitted_queries_.empty() && waiting_queries_.empty());
  }

 private:
  static constexpr std::size_t kMaxConcurrentQueries = 1;
  static constexpr std::size_t kMaxNumWorkerMessages = 20;

  void removeQuery(const std::size_t query_id);

  const tmb::client_id foreman_client_id_;
  const std::size_t num_numa_nodes_;

  const WorkerDirectory &worker_directory_;

  CatalogDatabaseLite *catalog_database_;
  StorageManager *storage_manager_;

  tmb::MessageBus *bus_;

  // Key = query ID, value = QueryManager* for the key query.
  std::unordered_map<std::size_t, std::unique_ptr<QueryManager>> admitted_queries_;

  // The queries which haven't been admitted yet.
  std::queue<QueryHandle*> waiting_queries_;

  DISALLOW_COPY_AND_ASSIGN(PolicyEnforcer);
};

/** @} */

}  // namespace quickstep

#endif  // QUICKSTEP_QUERY_EXECUTION_QUERY_MANAGER_HPP_
