#ifndef QUICKSTEP_TRANSACTION_TRANSACTION_HPP_
#define QUICKSTEP_TRANSACTION_TRANSACTION_HPP_

#include <cstdint>

namespace quickstep {

/** \addtogroup Transaction
 *  @{
 */

/**
 * @brief Type that represents id of a transaction.
 **/
using TransactionId = std::uint64_t;

/**
 * @brief Enum class for transaction internal status.
 **/
enum class TransactionStatus {
  kRUNNING = 0,
  kABORTED,
  kCOMMITTED
};

/**
 * @brief Transaction
 **/
class Transaction {
public:
  /**
   * @brief Constructor for Transaction.
   * 
   * @param tid Id of this transaction.
   **/
  Transaction(TransactionId tid)
    : tid_(tid) {
  }

  /**
   * @brief Getter for transaction id.
   *
   * @return Transaction id of this.
   **/
  TransactionId getTransactionId() const;

  /**
   * @brief Setter for transaction status.
   *
   * @param status New status of the transaction.
   **/
  void setStatus(TransactionStatus status);

  TransactionStatus getStatus() const;

  /**
   * @brief Equality operator for Transaction class.
   *
   * @param other Other transaction to be compared with.
   *
   * @return True if other tid and this tid are equal, false otherwise.
   **/
  bool operator==(const Transaction &other) const;

  /**
   * @brief Helper hasher class for transaction.
   *
   **/
  struct TransactionHasher {
    std::size_t operator()(const Transaction &transaction) const;
  };
  
private:
  TransactionId tid_;
  TransactionStatus status_;
  //std::unique_ptr<QueryPlan> query_plan_;
  //std::unique_ptr<TransactionThread> thread_;
};

/** @} */

}

#endif
