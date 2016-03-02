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

#include "transaction/AccessMode.hpp"

#include <type_traits>

namespace quickstep {

namespace transaction {

  constexpr bool AccessMode::kCOMP_MATRIX[kNUMBER_LOCKS][kNUMBER_LOCKS];

  bool AccessMode::isCompatible(const AccessMode &other) const {
    using TypeToCast = std::underlying_type<AccessModeType>::type;
    TypeToCast this_mode = static_cast<TypeToCast>(this->access_mode_);
    TypeToCast other_mode = static_cast<TypeToCast>(other.access_mode_);
    return kCOMP_MATRIX[this_mode][other_mode];
  }

  bool AccessMode::operator==(const AccessMode &other) const {
    return access_mode_ == other.access_mode_;
  }

  bool AccessMode::isIntentionShareLock() const {
    return access_mode_ == AccessModeType::kIS_LOCK;
  }

  bool AccessMode::isIntentionExclusiveLock() const {
    return access_mode_ == AccessModeType::kIX_LOCK;
  }

  bool AccessMode::isShareLock() const {
    return access_mode_ == AccessModeType::kS_LOCK;
  }

  bool AccessMode::isShareIntentionExclusiveLock() const {
    return access_mode_ == AccessModeType::kSIX_LOCK;
  }

  bool AccessMode::isExclusiveLock() const {
    return access_mode_ == AccessModeType::kX_LOCK;
  }
}  // namespace transaction

}  // namespace quickstep
