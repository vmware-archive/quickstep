#ifndef QUICKSTEP_TRANSACTION_LOCK_TABLE_HPP_
#define QUICKSTEP_TRANSACTION_LOCK_TABLE_HPP_

#include <list>
#include <unordered_map>
#include <utility>
#include <vector>

#include "threading/SharedMutex.hpp"
#include "transaction/AccessMode.hpp"
#include "transaction/Lock.hpp"
#include "transaction/ResourceId.hpp"
#include "transaction/Transaction.hpp"
#include "utility/Macros.hpp"

namespace quickstep {

enum class LockTableResult {
  kPLACED_IN_OWNED = 0,
  kPLACED_IN_PENDING,
  kALREADY_IN_OWNED,
  kALREADY_IN_PENDING,
  kDEL_FROM_OWNED,
  kDEL_FROM_PENDING,
  kDEL_ERROR,  
  kPUT_ERROR
};
  
class LockTable {
public:
  using LockEntry = std::pair<TransactionId, Lock>;
  using LockOwnList = std::list<LockEntry>;
  using LockPendingList = std::list<LockEntry>;
  using LockListPair = std::pair<LockOwnList, LockPendingList>;
  using Iterator = std::unordered_map<ResourceId,
				      LockListPair,
				      ResourceId::ResourceIdHasher>::iterator;
  using ConstIterator = std::unordered_map<ResourceId,
					   LockListPair,
					   ResourceId::ResourceIdHasher>::const_iterator;
  LockTable() {}

  LockTableResult putLock(TransactionId tid,
			  const ResourceId &rid,
			  AccessMode access_mode);

  LockTableResult deleteLock(TransactionId tid,
			     const ResourceId &rid);

  void movePendingToOwned(const ResourceId &rid);

  Iterator begin();
  Iterator end();

  ConstIterator begin() const;
  ConstIterator end() const;

  void latchShared();

  void unlatchShared();

  void latchExclusive();

  void unlatchExclusive();
  
private:
  DISALLOW_COPY_AND_ASSIGN(LockTable);

  std::unordered_map<ResourceId, LockListPair, ResourceId::ResourceIdHasher> internal_map_;

  SharedMutex mutex_;
};  
}

#endif
