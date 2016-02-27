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

/** \addtogroup Transaction
 * @{
 */

/**
 * @brief Represents different results for LockTable's methods.
 **/
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

/**
 * @brief LockTable class represents the hash map for RID and 
 *        list of locks on RID.
 **/
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
  /**
   * @brief Constructor for LockTable.
   */
  LockTable() {}

  /**
   * @brief Puts the lock entry into the lock table for correspondin resource.
   *
   * @param tid Id of the transaction that requests the lock.
   * @param rid Id of the resource to be locked.
   * @param access_mode Access mode of the lock.
   *
   * @return LockTableResult::kPLACED_IN_OWNED if lock is granted,
   *         LockTableResult::kPLACED_IN_PENDING if lock is not granted,
   *         LockTableResult::kALREADY_IN_OWNED if lock has been 
   *         already granted,
   *         LockTableResult::kALREADY_IN_PENDING if lock has been
   *         already pending. 
   **/
  LockTableResult putLock(TransactionId tid,
			  const ResourceId &rid,
			  AccessMode access_mode);
  /**
   * @brief Deletes the lock entry.
   *
   * @param tid
   * @param rid
   *
   **/
  LockTableResult deleteLock(TransactionId tid,
			     const ResourceId &rid);


  /** 
   * @brief Iterator for begin position.
   *
   * @return Non-const Iterator which points to begin point
   *         of the lock table.
   */
  Iterator begin();

  /**
   * @brief Iterator for end position.
   *
   * @return Non-const iterator which points to end point
   *         of the lock table.
   **/
  Iterator end();

  /**
   * @brief ConstIterator for begin position.
   *
   * @return Const iterator which points to the begin 
   *         point of the lock table.
   **/
  ConstIterator begin() const;

  /**
   * @brief ConstIterator for end position.
   *
   * @return Const iterator which points to the end
   *         point of the lock table.
   **/
  ConstIterator end() const;

  /**
   * @brief Latch mutex in shared mode. Multiple shared mode
   *        latch acquisition is compatible.
   **/
  void latchShared();

  /**
   * @brief Unlatch mutex in shared mode.
   **/
  void unlatchShared();

  /**
   * @brief Latch mutex in exclusive mode.
   */
  void latchExclusive();

  /**
   * @brief Unlatch mutex in exclusive mode.
   */
  void unlatchExclusive();
  
private:
  DISALLOW_COPY_AND_ASSIGN(LockTable);

  // This method will be called after deletion of locks.
  // After delete, some pending locks might be acquired.
  void movePendingToOwned(const ResourceId &rid);
  
  std::unordered_map<ResourceId, LockListPair, ResourceId::ResourceIdHasher> internal_map_;

  SharedMutex mutex_;
};  
}

#endif
