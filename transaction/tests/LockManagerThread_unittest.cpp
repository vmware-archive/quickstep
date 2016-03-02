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

#include "transaction/LockManagerThread.hpp"

#include <random>

#include "transaction/LockRequest.hpp"
#include "transaction/ResourceId.hpp"

using namespace quickstep::transaction;  // NOLINT(build/namespaces)
using quickstep::ThreadSafeQueue;

class RandomResourceId {
 public:
  explicit RandomResourceId(std::uint64_t max_no)
    : rd()
    , engine(rd())
    , dist(0, max_no) {
  }

  ResourceId operator()() {
    std::uint64_t db_id = dist(engine);
    std::uint64_t rel_id = dist(engine);
    std::uint64_t blk_id = dist(engine);

    return ResourceId(db_id, rel_id, blk_id);
  }

 private:
  std::random_device rd;
  std::mt19937 engine;
  std::uniform_int_distribution<std::uint64_t> dist;
};

void putRequest(TransactionId tid, ThreadSafeQueue<LockRequest> *input_queue) {
  RandomResourceId random_rid(2);
  while (true) {
    ResourceId rid = random_rid();
    AccessMode mode(AccessModeType::kX_LOCK);
    input_queue->push(LockRequest(tid, rid, mode, RequestType::kACQUIRE_LOCK));
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

int main() {
  ThreadSafeQueue<LockRequest> input_queue;
  ThreadSafeQueue<LockRequest> output_queue;
  LockManagerThread lock_manager_thread(&input_queue, &output_queue);

  std::thread transaction1(putRequest, 1, &input_queue);
  std::thread transaction2(putRequest, 2, &input_queue);

  lock_manager_thread.start();

  lock_manager_thread.join();
  transaction1.join();
  transaction2.join();
}
