
#include <random>

#include "transaction/LockManagerThread.hpp"
#include "transaction/LockRequest.hpp"
#include "transaction/ResourceId.hpp"


using namespace quickstep;



class RandomResourceId {
public:
  RandomResourceId(std::uint64_t max_no)
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
  RandomResourceId random_rid(5);
  while (true) {
    ResourceId rid = random_rid();
    AccessMode mode = AccessMode::AccessModeType::kX_LOCK;
    input_queue->push(LockRequest(tid, rid, mode, RequestType::kACQUIRE_LOCK));
    std::string message = "Transaction " + std::to_string(tid) + " requested "
      + rid.toString() + "\n";
    std::cout << message;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  }
};

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
