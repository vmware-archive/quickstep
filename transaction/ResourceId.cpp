#include "transaction/ResourceId.hpp"

#include <string>

namespace quickstep {

namespace transaction {

bool ResourceId::operator==(const ResourceId &other) const {
  return (db_id_ == other.db_id_) &&
    (rel_id_ == other.rel_id_) &&
    (block_id_ == other.block_id_) &&
    (tuple_id_ == other.tuple_id_);
}

bool ResourceId::hasParent() const {
  return !isDatabaseAccess();
}

ResourceId ResourceId::getParentResourceId() const {
  if (isRelationAccess()) {
    return ResourceId(db_id_);
  } else if (isBlockAccess()) {
    return ResourceId(db_id_, rel_id_);
  } else if (isTupleAccess()) {
    return ResourceId(db_id_, rel_id_, block_id_);
  } else {
    FATAL_ERROR("Trying to call getParentResourceId on database");
  }
}

bool ResourceId::isDatabaseAccess() const {
  return (db_id_ != kDB_ID_PLACEHOLDER) &&
    (rel_id_ == kREL_ID_PLACEHOLDER) &&
    (block_id_ == kBLOCK_ID_PLACEHOLDER) &&
    (tuple_id_ == kTUPLE_ID_PLACEHOLDER);
}

bool ResourceId::isRelationAccess() const {
  return (db_id_ != kDB_ID_PLACEHOLDER) &&
    (rel_id_ != kREL_ID_PLACEHOLDER) &&
    (block_id_ == kBLOCK_ID_PLACEHOLDER) &&
    (tuple_id_ == kTUPLE_ID_PLACEHOLDER);
}

bool ResourceId::isBlockAccess() const {
  return (db_id_ != kDB_ID_PLACEHOLDER) &&
    (rel_id_ != kREL_ID_PLACEHOLDER) &&
    (block_id_ != kBLOCK_ID_PLACEHOLDER) &&
    (tuple_id_ == kTUPLE_ID_PLACEHOLDER);
}

bool ResourceId::isTupleAccess() const {
  return (db_id_ != kDB_ID_PLACEHOLDER) &&
    (rel_id_ != kREL_ID_PLACEHOLDER) &&
    (block_id_ != kBLOCK_ID_PLACEHOLDER) &&
    (tuple_id_ != kTUPLE_ID_PLACEHOLDER);
}

std::string ResourceId::toString() const {
  return "ResourceId(" + std::to_string(db_id_) + ", " +
    std::to_string(rel_id_) + ", " + std::to_string(block_id_) +
    ", " + std::to_string(tuple_id_) + ")";
}

std::size_t
ResourceId::ResourceIdHasher::operator()(const ResourceId &rid) const {
  std::size_t hash1 = std::hash<database_id>()(rid.db_id_);
  std::size_t hash2 = std::hash<relation_id>()(rid.rel_id_);
  std::size_t hash3 = std::hash<block_id>()(rid.block_id_);
  std::size_t hash4 = std::hash<tuple_id>()(rid.tuple_id_);

  std::size_t comb1 = CombineHashes(hash1, hash2);
  std::size_t comb2 = CombineHashes(hash3, hash4);
  return CombineHashes(comb1, comb2);
}

}  // namespace transaction

}  // namespace quickstep
