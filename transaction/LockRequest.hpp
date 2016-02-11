#ifndef QUICKSTEP_TRANSACTION_LOCK_REQUEST_HPP_
#define QUICKSTEP_TRANSACTION_LOCK_REQUEST_HPP_

#include "transaction/AccessMode.hpp"
#include "transaction/ResourceId.hpp"
#include "transaction/Transaction.hpp"

namespace quickstep {

class LockRequest {
public:
  LockRequest(TransactionId tid, const ResourceId &rid, AccessMode access_mode);

  TransactionId getTransactionId() const;

  ResourceId getResourceId() const;

  AccessMode getAccessMode() const;
  
private:
  TransactionId tid_;
  ResourceId rid_;
  AccessMode access_mode_;
};

}

#endif
