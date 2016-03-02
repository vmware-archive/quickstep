#ifndef QUICKSTEP_TRANSACTION_LOCK_REQUEST_HPP_
#define QUICKSTEP_TRANSACTION_LOCK_REQUEST_HPP_

#include "transaction/AccessMode.hpp"
#include "transaction/ResourceId.hpp"
#include "transaction/Transaction.hpp"

namespace quickstep {

namespace transaction {

/** \addtogroup Transaction
 *  @{
 */

/**
 * @brief Enum class for representing request types.
 */
enum class RequestType {
  kACQUIRE_LOCK = 0,
  kRELEASE_LOCKS
};

/**
 * @brief Class for encapsulate lock request put into
 *        the buffers.
 */
class LockRequest {
 public:
  /**
   * @brief Constructor for LockRequest.
   *
   * @param tid Id of the transaction that requests the lock.
   * @param rid Id of the resource that is requested.
   * @param access_mode Access mode of the request.
   * @param type Type of the request.
   */
  LockRequest(TransactionId tid,
              const ResourceId &rid,
              AccessMode access_mode,
              RequestType type);

  /**
   * @brief Getter for transaction id.
   *
   * @return Transaction id of the request.
   */
  TransactionId getTransactionId() const;

  /**
   * @brief Getter for resource id.
   *
   * @return Resource id of the request.
   */
  ResourceId getResourceId() const;

  /**
   * @brief Getter for access mode.
   *
   * @return Access mode of the request.
   */
  AccessMode getAccessMode() const;

  /**
   * @brief Getter for request type.
   *
   * @return Type of the request.
   */
  RequestType getRequestType() const;

 private:
  TransactionId tid_;
  ResourceId rid_;
  AccessMode access_mode_;
  RequestType request_type_;
};

/** @} */

}  // namespace transaction

}  // namespace quickstep

#endif
