#include "transaction/LockRequest.hpp"

namespace quickstep {

LockRequest::LockRequest(TransactionId tid,
			 const ResourceId &rid,
			 AccessMode access_mode)
  : tid_(tid), rid_(rid)
  , access_mode_(access_mode) {
}

TransactionId LockRequest::getTransactionId() const {
  return tid_;
}

ResourceId LockRequest::getResourceId() const {
  return rid_;
}

AccessMode LockRequest::getAccessMode() const {
  return access_mode_;
}


}
