#include "transaction/LockRequest.hpp"

namespace quickstep {

LockRequest::LockRequest(TransactionId tid,
			 const ResourceId &rid,
			 AccessMode access_mode,
			 RequestType type)
  : tid_(tid), rid_(rid)
  , access_mode_(access_mode)
  , request_type_(type) {
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

RequestType LockRequest::getRequestType() const {
  return request_type_;
}

}
