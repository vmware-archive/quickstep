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

#include "gtest/gtest.h"

namespace quickstep {

namespace transaction {

TEST(AccessModeTest, ModeCompatibilty) {
  AccessMode is_mode = AccessMode(AccessModeType::kIS_LOCK);
  AccessMode ix_mode = AccessMode(AccessModeType::kIX_LOCK);
  AccessMode s_mode = AccessMode(AccessModeType::kS_LOCK);
  AccessMode x_mode = AccessMode(AccessModeType::kX_LOCK);

  EXPECT_TRUE(is_mode.isCompatible(is_mode));
  EXPECT_TRUE(is_mode.isCompatible(ix_mode));
  EXPECT_TRUE(is_mode.isCompatible(s_mode));
  EXPECT_FALSE(is_mode.isCompatible(x_mode));

  EXPECT_TRUE(ix_mode.isCompatible(is_mode));
  EXPECT_TRUE(ix_mode.isCompatible(ix_mode));
  EXPECT_FALSE(ix_mode.isCompatible(s_mode));
  EXPECT_FALSE(ix_mode.isCompatible(x_mode));

  EXPECT_TRUE(s_mode.isCompatible(is_mode));
  EXPECT_FALSE(s_mode.isCompatible(ix_mode));
  EXPECT_TRUE(s_mode.isCompatible(s_mode));
  EXPECT_FALSE(s_mode.isCompatible(x_mode));

  EXPECT_FALSE(x_mode.isCompatible(is_mode));
  EXPECT_FALSE(x_mode.isCompatible(ix_mode));
  EXPECT_FALSE(x_mode.isCompatible(s_mode));
  EXPECT_FALSE(x_mode.isCompatible(x_mode));
}

TEST(AccessModeTest, ModeQueryChecks) {
  AccessMode is_mode = AccessMode(AccessModeType::kIS_LOCK);
  AccessMode ix_mode = AccessMode(AccessModeType::kIX_LOCK);
  AccessMode s_mode = AccessMode(AccessModeType::kS_LOCK);
  AccessMode x_mode = AccessMode(AccessModeType::kX_LOCK);

  EXPECT_TRUE(is_mode.isIntentionShareLock());
  EXPECT_FALSE(is_mode.isExclusiveLock());
  EXPECT_FALSE(is_mode.isShareLock());
  EXPECT_FALSE(is_mode.isExclusiveLock());

  EXPECT_FALSE(ix_mode.isIntentionShareLock());
  EXPECT_TRUE(ix_mode.isIntentionExclusiveLock());
  EXPECT_FALSE(ix_mode.isShareLock());
  EXPECT_FALSE(ix_mode.isExclusiveLock());

  EXPECT_FALSE(s_mode.isIntentionShareLock());
  EXPECT_FALSE(s_mode.isIntentionExclusiveLock());
  EXPECT_TRUE(s_mode.isShareLock());
  EXPECT_FALSE(s_mode.isExclusiveLock());

  EXPECT_FALSE(x_mode.isIntentionShareLock());
  EXPECT_FALSE(x_mode.isIntentionExclusiveLock());
  EXPECT_FALSE(x_mode.isShareLock());
  EXPECT_TRUE(x_mode.isExclusiveLock());
}

TEST(AccessModeTest, Equality) {
  AccessMode is_mode_1 = AccessMode(AccessModeType::kIS_LOCK);
  AccessMode ix_mode_1 = AccessMode(AccessModeType::kIX_LOCK);
  AccessMode s_mode_1 = AccessMode(AccessModeType::kS_LOCK);
  AccessMode x_mode_1 = AccessMode(AccessModeType::kX_LOCK);

  AccessMode is_mode_2 = AccessMode(AccessModeType::kIS_LOCK);
  AccessMode ix_mode_2 = AccessMode(AccessModeType::kIX_LOCK);
  AccessMode s_mode_2 = AccessMode(AccessModeType::kS_LOCK);
  AccessMode x_mode_2 = AccessMode(AccessModeType::kX_LOCK);

  EXPECT_TRUE(is_mode_1 == is_mode_2);
  EXPECT_FALSE(is_mode_1 == ix_mode_1);
  EXPECT_FALSE(is_mode_1 == s_mode_1);
  EXPECT_FALSE(is_mode_1 == x_mode_1);

  EXPECT_FALSE(ix_mode_1 == is_mode_1);
  EXPECT_TRUE(ix_mode_1 == ix_mode_2);
  EXPECT_FALSE(ix_mode_1 == s_mode_1);
  EXPECT_FALSE(ix_mode_1 == x_mode_1);

  EXPECT_FALSE(s_mode_1 == is_mode_1);
  EXPECT_FALSE(s_mode_1 == ix_mode_1);
  EXPECT_TRUE(s_mode_1 == s_mode_2);
  EXPECT_FALSE(s_mode_1 == x_mode_1);

  EXPECT_FALSE(x_mode_1 == is_mode_1);
  EXPECT_FALSE(x_mode_1 == ix_mode_1);
  EXPECT_FALSE(x_mode_1 == s_mode_1);
  EXPECT_TRUE(x_mode_1 == x_mode_2);
}

}  // namespace transaction

}  // namespace quickstep
