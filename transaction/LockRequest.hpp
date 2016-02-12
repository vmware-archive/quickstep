#ifndef QUICKSTEP_TRANSACTION_LOCK_REQUEST_HPP_
#define QUICKSTEP_TRANSACTION_LOCK_REQUEST_HPP_

#include "transaction/AccessMode.hpp"
#include "transaction/ResourceId.hpp"
#include "transaction/Transaction.hpp"

namespace quickstep {

enum class RequestType {
  kACQUIRE_LOCK = 0,
  kRELEASE_LOCKS
};

class LockRequest {
public:
  LockRequest(TransactionId tid,
	      const ResourceId &rid,
	      AccessMode access_mode,
	      RequestType type);

  TransactionId getTransactionId() const;

  ResourceId getResourceId() const;

  AccessMode getAccessMode() const;

  RequestType getRequestType() const;
  
private:
  TransactionId tid_;
  ResourceId rid_;
  AccessMode access_mode_;
  RequestType request_type_;
};

}

#endif
