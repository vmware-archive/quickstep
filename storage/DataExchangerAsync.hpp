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

#ifndef QUICKSTEP_STORAGE_DATA_EXCHANGER_ASYNC_HPP_
#define QUICKSTEP_STORAGE_DATA_EXCHANGER_ASYNC_HPP_

#include <grpc++/grpc++.h>

#include <memory>
#include <string>

#include "storage/DataExchange.grpc.pb.h"
#include "threading/Thread.hpp"
#include "utility/Macros.hpp"

namespace quickstep {

class StorageManager;

class DataExchangerAsync final : public Thread {
 public:
  DataExchangerAsync();

  ~DataExchangerAsync() override {}

  void set_storage_manager(StorageManager *storage_manager) {
    storage_manager_ = storage_manager;
  }

  std::string network_address() const {
    return server_address_ + std::to_string(port_);
  }

  void shutdown() {
    server_->Shutdown();
    // Always shutdown the completion queue after the server.
    queue_->Shutdown();
  }

 protected:
  void run() override;

 private:
  static const char *server_address_;

  DataExchange::AsyncService service_;
  int port_ = 0;

  std::unique_ptr<grpc::ServerCompletionQueue> queue_;
  std::unique_ptr<grpc::Server> server_;

  StorageManager *storage_manager_ = nullptr;

  friend StorageManager;

  DISALLOW_COPY_AND_ASSIGN(DataExchangerAsync);
};

}  // namespace quickstep

#endif  // QUICKSTEP_STORAGE_DATA_EXCHANGER_ASYNC_HPP_
