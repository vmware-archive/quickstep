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

#include "transaction/ResourceId.hpp"

#include "gtest/gtest.h"

namespace quickstep {

namespace transaction {

TEST(ResourceIdTest, CheckAccessLevels) {
  ResourceId db2(2);
  ResourceId rel4_db2(2, 4);
  ResourceId block5_rel4_db2(2, 4, 5);
  ResourceId tpl8_block5_rel4_db2(2, 4, 5, 8);

  EXPECT_TRUE(db2.isDatabaseAccess());
  EXPECT_FALSE(rel4_db2.isDatabaseAccess());
  EXPECT_FALSE(block5_rel4_db2.isDatabaseAccess());
  EXPECT_FALSE(tpl8_block5_rel4_db2.isDatabaseAccess());

  EXPECT_FALSE(db2.isRelationAccess());
  EXPECT_TRUE(rel4_db2.isRelationAccess());
  EXPECT_FALSE(block5_rel4_db2.isRelationAccess());
  EXPECT_FALSE(tpl8_block5_rel4_db2.isRelationAccess());

  EXPECT_FALSE(db2.isBlockAccess());
  EXPECT_FALSE(rel4_db2.isBlockAccess());
  EXPECT_TRUE(block5_rel4_db2.isBlockAccess());
  EXPECT_FALSE(tpl8_block5_rel4_db2.isBlockAccess());

  EXPECT_FALSE(db2.isTupleAccess());
  EXPECT_FALSE(rel4_db2.isTupleAccess());
  EXPECT_FALSE(block5_rel4_db2.isTupleAccess());
  EXPECT_TRUE(tpl8_block5_rel4_db2.isTupleAccess());
}

TEST(ResourceIdTest, Equality) {
}

TEST(ResourceIdTest, CheckAccessLevel) {
  ResourceId db2(2);
  ResourceId db3(3);
  ResourceId rel2_db2(2, 2);
  ResourceId rel4_db2(2, 4);
  ResourceId rel5_db3(3, 5);
  ResourceId rel9_db3(3, 9);
  ResourceId block2_rel2_db2(2, 2, 2);
  ResourceId block3_rel2_db2(2, 2, 3);
  ResourceId block7_rel5_db3(3, 5, 7);
  ResourceId block9_rel5_db3(3, 5, 9);
  ResourceId tuple4_block2_rel2_db2(2, 2, 2, 4);
  ResourceId tuple7_block2_rel2_db2(2, 2, 2, 7);
}

}  // namespace transaction

}  // namespace quickstep
