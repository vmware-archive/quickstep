/**
 *   Copyright 2011-2015 Quickstep Technologies LLC.
 *   Copyright 2015-2016 Pivotal Software, Inc.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       https://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 **/

// This is included before other files so that we can conditionally determine
// what else to include.
#include "catalog/CatalogConfig.h"
#include "storage/StorageConfig.h"

// Define feature test macros to enable large page support for mmap.
#if defined(QUICKSTEP_HAVE_MMAP_LINUX_HUGETLB) && !defined(_GNU_SOURCE)
#define _GNU_SOURCE
#elif defined(QUICKSTEP_HAVE_MMAP_BSD_SUPERPAGE) && !defined(_BSD_SOURCE)
#define _BSD_SOURCE
#endif

#include <grpc++/grpc++.h>

#include "storage/StorageManager.hpp"

#if defined(QUICKSTEP_HAVE_MMAP_LINUX_HUGETLB) \
    || defined(QUICKSTEP_HAVE_MMAP_BSD_SUPERPAGE) \
    || defined(QUICKSTEP_HAVE_MMAP_PLAIN)
#include <sys/mman.h>
#endif

#ifdef QUICKSTEP_HAVE_LIBNUMA
#include <numa.h>
#include <numaif.h>
#endif

#include <atomic>
#include <cerrno>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "query_execution/QueryExecutionMessages.pb.h"
#include "query_execution/QueryExecutionTypedefs.hpp"
#include "query_execution/QueryExecutionUtil.hpp"
#include "storage/CountedReference.hpp"
#include "storage/DataExchange.grpc.pb.h"
#include "storage/DataExchange.pb.h"
#include "storage/EvictionPolicy.hpp"
#include "storage/FileManager.hpp"
#include "storage/FileManagerLocal.hpp"
#include "storage/StorageBlob.hpp"
#include "storage/StorageBlock.hpp"
#include "storage/StorageBlockBase.hpp"
#include "storage/StorageBlockInfo.hpp"
#include "storage/StorageBlockLayout.hpp"
#include "storage/StorageBlockLayout.pb.h"
#include "storage/StorageConstants.hpp"
#include "storage/StorageErrors.hpp"
#include "threading/Mutex.hpp"
#include "threading/SharedMutex.hpp"
#include "threading/SpinSharedMutex.hpp"
#include "utility/Alignment.hpp"

#ifdef QUICKSTEP_HAVE_FILE_MANAGER_HDFS
#include "storage/FileManagerHdfs.hpp"
#endif

#include "gflags/gflags.h"
#include "glog/logging.h"

#include "tmb/id_typedefs.h"
#include "tmb/message_bus.h"
#include "tmb/tagged_message.h"

using std::free;
using std::int32_t;
using std::malloc;
using std::memset;
using std::move;
using std::size_t;
using std::string;
using std::unique_ptr;
using std::vector;

using tmb::MessageBus;
using tmb::TaggedMessage;

namespace quickstep {

static bool ValidateBlockDomain(const char *flagname,
                                int32_t value) {
  if (value <= 0 || value > static_cast<int32_t>(kMaxDomain)) {
    std::fprintf(stderr, "--%s must be nonzero and no greater than %hu\n", flagname, kMaxDomain);
    return false;
  } else {
    return true;
  }
}
DEFINE_int32(block_domain, 1,
             "The unique domain for a distributed Quickstep instance.");
static const bool block_domain_dummy
    = gflags::RegisterFlagValidator(&FLAGS_block_domain, &ValidateBlockDomain);

static bool ValidateBufferPoolSlots(const char *flagname,
                                    std::uint64_t value) {
  if (value == 0) {
    std::fprintf(stderr, "--%s must be nonzero\n", flagname);
    return false;
  } else {
    return true;
  }
}
DEFINE_uint64(buffer_pool_slots, 1024,
              "The number of 2-megabyte slots which may be allocated in the "
              "buffer pool. This is a \"soft\" limit: the buffer pool may "
              "temporarily grow larger than this size if the buffer manager "
              "is unable to evict enough unreferenced blocks to make room for "
              "a new allocation.");
static const bool buffer_pool_slots_dummy
    = gflags::RegisterFlagValidator(&FLAGS_buffer_pool_slots, &ValidateBufferPoolSlots);

#ifdef QUICKSTEP_HAVE_FILE_MANAGER_HDFS
DEFINE_bool(use_hdfs, false, "Use HDFS as the persistent storage, instead of the local disk.");
#endif

StorageManager::StorageManager(
  const std::string &storage_path,
  const block_id_domain block_domain,
  const size_t max_memory_usage,
  EvictionPolicy *eviction_policy,
  const tmb::client_id block_locator_client_id,
  MessageBus *bus)
    : storage_path_(storage_path),
      block_domain_(block_domain),
      total_memory_usage_(0),
      max_memory_usage_(max_memory_usage),
      eviction_policy_(eviction_policy),
      block_locator_client_id_(block_locator_client_id),
      bus_(bus) {
#ifdef QUICKSTEP_HAVE_FILE_MANAGER_HDFS
  if (FLAGS_use_hdfs) {
    file_manager_.reset(new FileManagerHdfs(storage_path));
  } else {
    file_manager_.reset(new FileManagerLocal(storage_path));
  }
#else
  file_manager_.reset(new FileManagerLocal(storage_path));
#endif

  block_index_ = BlockIdUtil::GetBlockId(block_domain, file_manager_->getMaxUsedBlockCounter(block_domain));

  if (bus_) {
    storage_manager_client_id_ = bus_->Connect();

    bus_->RegisterClientAsSender(storage_manager_client_id_, kGetPeerDomainNetworkAddressMessage);
    bus_->RegisterClientAsReceiver(storage_manager_client_id_, kGetPeerDomainNetworkAddressResponseMessage);

    bus_->RegisterClientAsSender(storage_manager_client_id_, kAddBlockLocationMessage);
    bus_->RegisterClientAsSender(storage_manager_client_id_, kDeleteBlockLocationMessage);
    bus_->RegisterClientAsSender(storage_manager_client_id_, kBlockDomainUnregistrationMessage);
  }
}

StorageManager::~StorageManager() {
  if (bus_) {
    serialization::BlockDomainUnregistrationMessage proto;
    proto.set_block_domain(block_domain_);

    const size_t proto_length = proto.ByteSize();
    char *proto_bytes = static_cast<char*>(malloc(proto_length));
    CHECK(proto.SerializeToArray(proto_bytes, proto_length));

    TaggedMessage message(static_cast<const void*>(proto_bytes),
                          proto_length,
                          kBlockDomainUnregistrationMessage);
    free(proto_bytes);

    LOG(INFO) << "StorageManager (id '" << storage_manager_client_id_
              << "') sent BlockDomainUnregistrationMessage (typed '" << kBlockDomainUnregistrationMessage
              << ") to BlockLocator";
    CHECK(MessageBus::SendStatus::kOK ==
        QueryExecutionUtil::SendTMBMessage(bus_,
                                           storage_manager_client_id_,
                                           block_locator_client_id_,
                                           move(message)));
  }

  for (std::unordered_map<block_id, BlockHandle>::iterator it = blocks_.begin();
       it != blocks_.end();
       ++it) {
    if (it->second.block->isDirty()) {
      LOG(WARNING) << "Block with ID " << BlockIdUtil::ToString(it->first)
                   << " is dirty during StorageManager shutdown";
    }
    delete it->second.block;
    deallocateSlots(it->second.block_memory, it->second.block_memory_size);
  }
}

block_id StorageManager::createBlock(const CatalogRelationSchema &relation,
                                     const StorageBlockLayout &layout,
                                     const int numa_node) {
  const size_t num_slots = layout.getDescription().num_slots();

  BlockHandle new_block_handle;
  const block_id new_block_id =
      allocateNewBlockOrBlob(num_slots, &new_block_handle, numa_node);

  new_block_handle.block = new StorageBlock(relation,
                                            new_block_id,
                                            layout,
                                            true,
                                            new_block_handle.block_memory,
                                            kSlotSizeBytes * num_slots);

  {
    // Lock 'blocks_shared_mutex_' as briefly as possible to insert an entry
    // for the new block, after the block has already been constructed.
    SpinSharedMutexExclusiveLock<false> write_lock(blocks_shared_mutex_);

    // Because block IDs are generated by atomically incrementing block_index_,
    // there should never be collisions.
    DCHECK(blocks_.find(new_block_id) == blocks_.end());
    blocks_[new_block_id] = new_block_handle;
  }

  // Make '*eviction_policy_' aware of the new block's existence.
  eviction_policy_->blockCreated(new_block_id);

  if (bus_) {
    sendBlockLocationMessage(new_block_id, kAddBlockLocationMessage);
  }

  return new_block_id;
}

block_id StorageManager::createBlob(const std::size_t num_slots,
                                    int numa_node) {
  BlockHandle new_block_handle;
  block_id new_block_id =
      allocateNewBlockOrBlob(num_slots, &new_block_handle, numa_node);
  void *new_block_mem = new_block_handle.block_memory;

  new_block_handle.block = new StorageBlob(
      new_block_id, new_block_mem, kSlotSizeBytes * num_slots, true);

  {
    // Lock 'blocks_shared_mutex_' as briefly as possible to insert an entry
    // for the new block, after the block has already been constructed.
    SpinSharedMutexExclusiveLock<false> write_lock(blocks_shared_mutex_);

    // Because block IDs are generated by atomically incrementing block_index_,
    // there should never be collisions.
    DCHECK(blocks_.find(new_block_id) == blocks_.end());
    blocks_[new_block_id] = new_block_handle;
  }

  // Make '*eviction_policy_' aware of the new blob's existence.
  eviction_policy_->blockCreated(new_block_id);

  if (bus_) {
    sendBlockLocationMessage(new_block_id, kAddBlockLocationMessage);
  }

  return new_block_id;
}

bool StorageManager::blockOrBlobIsLoaded(const block_id block) const {
  SpinSharedMutexSharedLock<false> read_lock(blocks_shared_mutex_);
  if (blocks_.find(block) == blocks_.end()) {
    return false;
  } else {
    return true;
  }
}

StorageBlock* StorageManager::loadBlock(const block_id block,
                                        const CatalogRelationSchema &relation,
                                        const int numa_node) {
  BlockHandle handle = loadBlockOrBlob(block, numa_node);
  handle.block = new StorageBlock(
      relation,
      block,
      StorageBlockLayout(relation),
      false,
      handle.block_memory,
      handle.block_memory_size * kSlotSizeBytes);
  insertBlockHandleAfterLoad(block, handle);
  return static_cast<StorageBlock*>(handle.block);
}

StorageBlob* StorageManager::loadBlob(const block_id blob,
                                      const int numa_node) {
  BlockHandle handle = loadBlockOrBlob(blob, numa_node);
  handle.block = new StorageBlob(blob,
                                 handle.block_memory,
                                 handle.block_memory_size * kSlotSizeBytes,
                                 false);
  insertBlockHandleAfterLoad(blob, handle);
  return static_cast<StorageBlob*>(handle.block);
}

bool StorageManager::saveBlockOrBlob(const block_id block, const bool force) {
  SpinSharedMutexSharedLock<false> read_lock(*lock_manager_.get(block));
  return saveBlockOrBlobInternal(block, force);
}

bool StorageManager::saveBlockOrBlobInternal(const block_id block, const bool force) {
  // TODO(chasseur): This lock is held for the entire duration of this call
  // (including I/O), but really we only need to prevent the eviction of the
  // particular entry in 'blocks_' for the specified 'block'. If and when we
  // switch blocks_ to something with more fine-grained locking, this should
  // be revisited.
  SpinSharedMutexSharedLock<false> read_lock(blocks_shared_mutex_);

  std::unordered_map<block_id, BlockHandle>::iterator block_it = blocks_.find(block);
  if (block_it == blocks_.end()) {
    return false;
  }

  if (!(force || block_it->second.block->isDirty())) {
    return true;
  }

  bool res = file_manager_->writeBlockOrBlob(block,
                                             block_it->second.block_memory,
                                             kSlotSizeBytes * (block_it->second.block_memory_size));
  if (res) {
    block_it->second.block->markClean();
  }

  return res;
}

void StorageManager::evictBlockOrBlob(const block_id block) {
  if (bus_) {
    sendBlockLocationMessage(block, kDeleteBlockLocationMessage);
  }

  BlockHandle handle;
  {
    SpinSharedMutexExclusiveLock<false> write_lock(blocks_shared_mutex_);

    std::unordered_map<block_id, BlockHandle>::iterator block_it = blocks_.find(block);
    if (block_it == blocks_.end()) {
      throw BlockNotFoundInMemory();
    }
    handle = block_it->second;
    blocks_.erase(block_it);
  }

  delete handle.block;
  deallocateSlots(handle.block_memory, handle.block_memory_size);
}

void StorageManager::deleteBlockOrBlobFile(const block_id block) {
  bool need_to_evict = false;
  {
    SpinSharedMutexSharedLock<false> read_lock(blocks_shared_mutex_);
    if (blocks_.find(block) != blocks_.end()) {
      need_to_evict = true;
    }
  }
  if (need_to_evict) {
    evictBlockOrBlob(block);
    eviction_policy_->blockEvicted(block);
  }

  const bool status = file_manager_->deleteBlockOrBlob(block);
  CHECK(status) << "Failed to delete block from persistent storage: " << block;

  eviction_policy_->blockDeleted(block);
}

StorageManager::DataExchangerClientAsync::DataExchangerClientAsync(const std::shared_ptr<grpc::Channel> &channel,
                                                                   StorageManager *storage_manager)
    : stub_(DataExchange::NewStub(channel)),
      storage_manager_(storage_manager) {
}

bool StorageManager::DataExchangerClientAsync::Pull(const block_id block,
                                                    const numa_node_id numa_node,
                                                    BlockHandle *block_handle) {
  grpc::ClientContext context;

  PullRequest request;
  request.set_block_id(block);

  grpc::CompletionQueue queue;

  unique_ptr<grpc::ClientAsyncResponseReader<PullResponse>> rpc(
      stub_->AsyncPull(&context, request, &queue));

  PullResponse response;
  grpc::Status status;

  rpc->Finish(&response, &status, reinterpret_cast<void*>(1));

  void *got_tag;
  bool ok = false;

  queue.Next(&got_tag, &ok);
  CHECK(got_tag == reinterpret_cast<void*>(1));
  CHECK(ok);

  if (!status.ok()) {
    LOG(ERROR) << "DataExchangerClientAsync Pull error: RPC failed";
    return false;
  }

  if (!response.is_valid()) {
    LOG(WARNING) << "The pulling block not found in the peer";
    return false;
  }

  const size_t num_slots = response.num_slots();
  DCHECK_NE(num_slots, 0u);

  const string &block_content = response.block();
  DCHECK_EQ(kSlotSizeBytes * num_slots, block_content.size());

  void *block_buffer = storage_manager_->allocateSlots(num_slots, numa_node, block);

  block_handle->block_memory =
      std::memcpy(block_buffer, block_content.c_str(), block_content.size());
  block_handle->block_memory_size = num_slots;

  return true;
}

block_id StorageManager::allocateNewBlockOrBlob(const std::size_t num_slots,
                                                BlockHandle *handle,
                                                const int numa_node) {
  DCHECK_GT(num_slots, 0u);
  DEBUG_ASSERT(handle != nullptr);

  handle->block_memory = allocateSlots(num_slots, numa_node, kInvalidBlockId);
  handle->block_memory_size = num_slots;

  return ++block_index_;
}

vector<string> StorageManager::getPeerDomainNetworkAddress(const block_id block) {
  serialization::GetPeerDomainNetworkAddressMessage proto;
  proto.set_block_id(block);

  const size_t proto_length = proto.ByteSize();
  char *proto_bytes = static_cast<char*>(malloc(proto_length));
  CHECK(proto.SerializeToArray(proto_bytes, proto_length));

  TaggedMessage message(static_cast<const void*>(proto_bytes),
                        proto_length,
                        kGetPeerDomainNetworkAddressMessage);
  free(proto_bytes);

  LOG(INFO) << "StorageManager (id '" << storage_manager_client_id_
            << "') sent GetPeerDomainNetworkAddressMessage (typed '" << kGetPeerDomainNetworkAddressMessage
            << ") to BlockLocator";

  DCHECK_NE(block_locator_client_id_, tmb::kClientIdNone);
  DCHECK(bus_ != nullptr);
  CHECK(MessageBus::SendStatus::kOK ==
      QueryExecutionUtil::SendTMBMessage(bus_,
                                         storage_manager_client_id_,
                                         block_locator_client_id_,
                                         move(message)));

  const tmb::AnnotatedMessage annotated_message(bus_->Receive(storage_manager_client_id_, 0, true));
  const TaggedMessage &tagged_message = annotated_message.tagged_message;
  CHECK_EQ(kGetPeerDomainNetworkAddressResponseMessage, tagged_message.message_type());

  serialization::GetPeerDomainNetworkAddressResponseMessage response_proto;
  CHECK(response_proto.ParseFromArray(tagged_message.message(), tagged_message.message_bytes()));

  vector<string> domain_network_addresses;
  for (int i = 0; i < response_proto.domain_network_addresses_size(); ++i) {
    domain_network_addresses.push_back(response_proto.domain_network_addresses(i));
  }

  return domain_network_addresses;
}

StorageManager::BlockHandle StorageManager::loadBlockOrBlob(
    const block_id block, const int numa_node) {
  BlockHandle loaded_handle;

  if (BlockIdUtil::Domain(block) != block_domain_) {
    const vector<string> peer_domain_network_addresses = getPeerDomainNetworkAddress(block);
    if (!peer_domain_network_addresses.empty()) {
      DataExchangerClientAsync client(
          grpc::CreateChannel(peer_domain_network_addresses[0], grpc::InsecureChannelCredentials()),
          this);
      if (client.Pull(block, numa_node, &loaded_handle)) {
        sendBlockLocationMessage(block, kAddBlockLocationMessage);
        return loaded_handle;
      }
    }
  }

  // The caller of this function holds an exclusive lock on this block/blob's
  // mutex in the lock manager. The caller has ensured that the block is not
  // already loaded before this function gets called.
  const size_t num_slots = file_manager_->numSlots(block);
  DCHECK_NE(num_slots, 0u);
  void *block_buffer = allocateSlots(num_slots, numa_node, block);

  const bool status = file_manager_->readBlockOrBlob(block, block_buffer, kSlotSizeBytes * num_slots);
  CHECK(status) << "Failed to read block from persistent storage: " << block;

  loaded_handle.block_memory = block_buffer;
  loaded_handle.block_memory_size = num_slots;

  if (bus_) {
    sendBlockLocationMessage(block, kAddBlockLocationMessage);
  }

  return loaded_handle;
}

void StorageManager::pullBlockOrBlob(const block_id block,
                                     PullResponse *response) const {
  SpinSharedMutexSharedLock<false> read_lock(blocks_shared_mutex_);
  std::unordered_map<block_id, BlockHandle>::const_iterator cit = blocks_.find(block);
  if (cit != blocks_.end()) {
    response->set_is_valid(true);

    const BlockHandle &block_handle = cit->second;
    const std::size_t num_slots = block_handle.block_memory_size;

    response->set_num_slots(num_slots);
    response->set_block(block_handle.block_memory,
                        num_slots * kSlotSizeBytes);
  } else {
    response->set_is_valid(false);
  }
}

void StorageManager::insertBlockHandleAfterLoad(const block_id block,
                                                const BlockHandle &handle) {
  SpinSharedMutexExclusiveLock<false> lock(blocks_shared_mutex_);
  DCHECK(blocks_.find(block) == blocks_.end());
  blocks_[block] = handle;
}

void* StorageManager::allocateSlots(const std::size_t num_slots,
                                    const int numa_node,
                                    const block_id locked_block_id) {
#if defined(QUICKSTEP_HAVE_MMAP_LINUX_HUGETLB)
  static constexpr int kLargePageMmapFlags
      = MAP_PRIVATE | MAP_ANONYMOUS | MAP_HUGETLB;
#elif defined(QUICKSTEP_HAVE_MMAP_BSD_SUPERPAGE)
  static constexpr int kLargePageMmapFlags
      = MAP_PRIVATE | MAP_ANONYMOUS | MAP_ALIGNED_SUPER;
#endif

  void *slots = nullptr;

#if defined(QUICKSTEP_HAVE_MMAP_LINUX_HUGETLB) || defined(QUICKSTEP_HAVE_MMAP_BSD_SUPERPAGE)
  slots = mmap(nullptr,
               num_slots * kSlotSizeBytes,
               PROT_READ | PROT_WRITE,
               kLargePageMmapFlags,
               -1, 0);

  // Fallback to regular mmap() if large page allocation failed. Even on
  // systems with large page support, large page allocation may fail if the
  // user running the executable is not a member of hugetlb_shm_group on Linux,
  // or if all the reserved hugepages are already in use.
  if (slots == MAP_FAILED) {
    slots = mmap(nullptr,
                 num_slots * kSlotSizeBytes,
                 PROT_READ | PROT_WRITE,
                 MAP_PRIVATE | MAP_ANONYMOUS,
                 -1, 0);
  }
  if (slots == MAP_FAILED) {
    slots = nullptr;
  }
#elif defined(QUICKSTEP_HAVE_MMAP_PLAIN)
  slots = mmap(nullptr,
               num_slots * kSlotSizeBytes,
               PROT_READ | PROT_WRITE,
               MAP_PRIVATE | MAP_ANONYMOUS,
               -1, 0);
  if (slots == MAP_FAILED) {
    slots = nullptr;
  }
#else
  slots = malloc_with_alignment(num_slots * kSlotSizeBytes,
                                kCacheLineBytes);
  if (slots != nullptr) {
    memset(slots, 0x0, num_slots * kSlotSizeBytes);
  }
#endif

  if (slots == nullptr) {
    throw OutOfMemory();
  }

#if defined(QUICKSTEP_HAVE_LIBNUMA)
  if (numa_node != -1) {
    DCHECK(numa_node < numa_num_configured_nodes());
    struct bitmask *numa_node_bitmask = numa_allocate_nodemask();
    // numa_node can be 0 through n-1, where n is the num of NUMA nodes.
    numa_bitmask_setbit(numa_node_bitmask, numa_node);
    long mbind_status = mbind(slots,  // NOLINT(runtime/int)
                              num_slots * kSlotSizeBytes,
                              MPOL_PREFERRED,
                              numa_node_bitmask->maskp,
                              numa_node_bitmask->size,
                              0);
    numa_free_nodemask(numa_node_bitmask);
    if (mbind_status == -1) {
      LOG(WARNING) << "mbind() failed with errno " << errno << " ("
                   << std::strerror(errno) << ")";
    }
  }
#endif  // QUICKSTEP_HAVE_LIBNUMA

  total_memory_usage_ += num_slots;
  return slots;
}

void StorageManager::deallocateSlots(void *slots, const std::size_t num_slots) {
#if defined(QUICKSTEP_HAVE_MMAP_LINUX_HUGETLB) \
    || defined(QUICKSTEP_HAVE_MMAP_BSD_SUPERPAGE) \
    || defined(QUICKSTEP_HAVE_MMAP_PLAIN)
  DO_AND_DEBUG_ASSERT_ZERO(munmap(slots, num_slots * kSlotSizeBytes));
#else
  free(slots);
#endif
  total_memory_usage_ -= num_slots;
}

MutableBlockReference StorageManager::getBlockInternal(
    const block_id block,
    const CatalogRelationSchema &relation,
    const int numa_node) {
  std::size_t num_slots = 0u;
  MutableBlockReference ret;
  {
    // First, see if the block is in the buffer pool. If it is, we can return
    // a reference to it immediately.
    SpinSharedMutexSharedLock<false> eviction_lock(*lock_manager_.get(block));
    SpinSharedMutexSharedLock<false> read_lock(blocks_shared_mutex_);
    std::unordered_map<block_id, BlockHandle>::iterator it = blocks_.find(block);
    if (it != blocks_.end()) {
      DCHECK(!it->second.block->isBlob());
      ret = MutableBlockReference(static_cast<StorageBlock*>(it->second.block), eviction_policy_.get());
    } else {
      // The block was not loaded. Taking advantage of the shared lock on the
      // buffer pool, retrieve the size of the block's file.
      num_slots = file_manager_->numSlots(block);
    }
  }

  // Note that there is no way for the block to be evicted between the call to
  // loadBlock and the call to EvictionPolicy::blockReferenced from
  // MutableBlockReference's constructor; this is because EvictionPolicy
  // doesn't know about the block until blockReferenced is called, so
  // chooseBlockToEvict shouldn't return the block.
  if (!ret.valid()) {
    SpinSharedMutexExclusiveLock<false> io_lock(*lock_manager_.get(block));
    {
      // Check one more time if the block got loaded in memory by someone else.
      SpinSharedMutexSharedLock<false> read_lock(blocks_shared_mutex_);
      std::unordered_map<block_id, BlockHandle>::iterator it = blocks_.find(block);
      if (it != blocks_.end()) {
        DCHECK(!it->second.block->isBlob());
        ret = MutableBlockReference(static_cast<StorageBlock*>(it->second.block), eviction_policy_.get());
        return ret;
      }
    }

    // Call a best-effort method to evict blocks until the size of our buffer
    // pool falls below the current buffer pool size plus the size of the
    // block we are going to retrieve.
    makeRoomForBlock(num_slots);

    // No other thread loaded the block before us.
    // But going forward be careful as there is a potential self-deadlock
    // situation here -- we are holding an Exclusive lock (io_lock)
    //   and getting ready to go into the call chain
    //   "MutableBlockReference"/"loadBlock" -> "loadBlockOrBlob"
    //       -> "allocateSlots" -> "makeRoomForBlock"
    //   In "makeRoomForBlock," we will acquire an exclusive lock via the call
    //   "eviction_lock(*lock_manager_.get(block_index))"
    //   This situation could lead to a self-deadlock as block_index could
    //   hash to the same position in the "ShardedLockManager" as "block."
    //   To deal with this case, we pass the block information for "block"
    //   though the call chain, and check for a collision in the the
    //   "ShardedLockManager" in the function "makeRoomForBlock."
    //   If a collision is detected we avoid a self-deadlock.
    ret = MutableBlockReference(loadBlock(block, relation, numa_node), eviction_policy_.get());
  }

  return ret;
}

MutableBlobReference StorageManager::getBlobInternal(const block_id blob,
                                                     const int numa_node) {
  MutableBlobReference ret;
  {
    SpinSharedMutexSharedLock<false> eviction_lock(*lock_manager_.get(blob));
    SpinSharedMutexSharedLock<false> read_lock(blocks_shared_mutex_);
    std::unordered_map<block_id, BlockHandle>::iterator it = blocks_.find(blob);
    if (it != blocks_.end()) {
      DCHECK(it->second.block->isBlob());
      ret = MutableBlobReference(static_cast<StorageBlob*>(it->second.block), eviction_policy_.get());
    }
  }

  if (!ret.valid()) {
    SpinSharedMutexExclusiveLock<false> io_lock(*lock_manager_.get(blob));
    // Note that there is no way for the block to be evicted between the call to
    // loadBlob and the call to EvictionPolicy::blockReferenced from
    // MutableBlobReference's constructor; this is because EvictionPolicy
    // doesn't know about the blob until blockReferenced is called, so
    // chooseBlockToEvict shouldn't return the blob.
    {
      SpinSharedMutexSharedLock<false> read_lock(blocks_shared_mutex_);
      std::unordered_map<block_id, BlockHandle>::iterator it = blocks_.find(blob);
      if (it != blocks_.end()) {
        DCHECK(it->second.block->isBlob());
        ret = MutableBlobReference(static_cast<StorageBlob*>(it->second.block), eviction_policy_.get());
        return ret;
      }
    }
    // No other thread loaded the blob before us.
    ret = MutableBlobReference(loadBlob(blob, numa_node), eviction_policy_.get());
  }

  return ret;
}

void StorageManager::makeRoomForBlock(const size_t slots) {
  while (total_memory_usage_ + slots > max_memory_usage_) {
    block_id block_index;
    EvictionPolicy::Status status = eviction_policy_->chooseBlockToEvict(&block_index);

    if (status == EvictionPolicy::Status::kOk) {
      SpinSharedMutexExclusiveLock<false> eviction_lock(*lock_manager_.get(block_index));
      StorageBlockBase* block;
      {
        SpinSharedMutexSharedLock<false> read_lock(blocks_shared_mutex_);
        if (blocks_.find(block_index) == blocks_.end()) {
          // another thread must have jumped in and evicted it before us
          continue;
        }
        block = blocks_[block_index].block;
      }
      if (eviction_policy_->getRefCount(block->getID()) > 0) {
        // Someone sneaked in and referenced the block before we could evict it.
        continue;
      }
      if (saveBlockOrBlobInternal(block->getID(), false)) {
        evictBlockOrBlob(block->getID());
      }  // else : Someone sneaked in and evicted the block before we could.
    } else {
      // If status was not ok, then we must not have been able to evict enough
      // blocks; therefore, we return anyway, temporarily going over the memory
      // limit.
      break;
    }
  }
}

bool StorageManager::blockOrBlobIsLoadedAndDirty(const block_id block) {
  SpinSharedMutexSharedLock<false> read_lock(blocks_shared_mutex_);

  std::unordered_map<block_id, BlockHandle>::iterator block_it = blocks_.find(block);
  if (block_it != blocks_.end()) {
    return block_it->second.block->isDirty();
  }
  return false;
}

void StorageManager::sendBlockLocationMessage(const block_id block,
                                              const tmb::message_type_id message_type) {
  serialization::BlockLocationMessage proto;
  proto.set_block_id(block);
  proto.set_block_domain(block_domain_);

  const size_t proto_length = proto.ByteSize();
  char *proto_bytes = static_cast<char*>(malloc(proto_length));
  CHECK(proto.SerializeToArray(proto_bytes, proto_length));

  TaggedMessage message(static_cast<const void*>(proto_bytes),
                        proto_length,
                        message_type);
  free(proto_bytes);

  LOG(INFO) << "StorageManager (id '" << storage_manager_client_id_
            << "') sent BlockLocationMessage (typed '" << message_type
            << ") to BlockLocator";
  CHECK(MessageBus::SendStatus::kOK ==
      QueryExecutionUtil::SendTMBMessage(bus_,
                                         storage_manager_client_id_,
                                         block_locator_client_id_,
                                         move(message)));
}

}  // namespace quickstep
