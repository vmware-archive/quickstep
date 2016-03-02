/**
 *   Copyright 2016, Quickstep Research Group, Computer Sciences Department,
 *     University of Wisconsin—Madison.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 **/

#include "transaction/LockRequest.hpp"

namespace quickstep {

namespace transaction {

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

}  // namespace transaction

}  // namespace quickstep
