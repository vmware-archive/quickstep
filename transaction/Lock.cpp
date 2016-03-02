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

#include "transaction/Lock.hpp"

namespace quickstep {

namespace transaction {

Lock::Lock(ResourceId rid, AccessMode access_mode)
  : rid_(rid), access_mode_(access_mode) {}

bool Lock::operator==(const Lock &other) const {
  return rid_ == other.rid_
    && access_mode_ == other.access_mode_;
}

ResourceId Lock::getResourceId() const {
  return rid_;
}

AccessMode Lock::getAccessMode() const {
  return access_mode_;
}

}  // namespace transaction

}  // namespace quickstep
