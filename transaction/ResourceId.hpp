#ifndef QUICKSTEP_TRANSACTION_RID_HPP_
#define QUICKSTEP_TRANSACTION_RID_HPP_

#include <limits>
#include <string>
#include <type_traits>


#include "catalog/CatalogTypedefs.hpp"
#include "storage/StorageBlockInfo.hpp"
#include "utility/HashPair.hpp"

namespace quickstep {

class ResourceId {
public:

  static constexpr database_id kDB_ID_PLACEHOLDER =
    std::numeric_limits<database_id>::max();
  static constexpr relation_id kREL_ID_PLACEHOLDER =
    std::numeric_limits<relation_id>::max();
  static constexpr block_id kBLOCK_ID_PLACEHOLDER =
    std::numeric_limits<block_id>::max();
  static constexpr tuple_id kTUPLE_ID_PLACEHOLDER =
    std::numeric_limits<tuple_id>::max();

  ResourceId()
    : ResourceId(kDB_ID_PLACEHOLDER, kREL_ID_PLACEHOLDER,
		 kBLOCK_ID_PLACEHOLDER, kTUPLE_ID_PLACEHOLDER) {}
  
  ResourceId(database_id db_id)
    : ResourceId(db_id, kREL_ID_PLACEHOLDER,
		   kBLOCK_ID_PLACEHOLDER,
		   kTUPLE_ID_PLACEHOLDER) {}

  ResourceId(database_id db_id, relation_id rel_id)
    : ResourceId(db_id, rel_id, kBLOCK_ID_PLACEHOLDER,
		   kTUPLE_ID_PLACEHOLDER) {}

  ResourceId(database_id db_id, relation_id rel_id,
	     block_id block_id)
    : ResourceId(db_id, rel_id, block_id,
		   kTUPLE_ID_PLACEHOLDER) {}

  ResourceId(database_id db_id, relation_id rel_id,
	     block_id block_id, tuple_id tuple_id)
    : db_id_(db_id), rel_id_(rel_id),
      block_id_(block_id), tuple_id_(tuple_id) {}

  ResourceId(const ResourceId &other) {
    this->db_id_ = other.db_id_;
    this->rel_id_ = other.rel_id_;
    this->block_id_ = other.block_id_;
    this->tuple_id_ = other.tuple_id_;
  }

  struct ResourceIdHasher {
    std::size_t operator()(const ResourceId &rid) const;
  };
    
  bool operator==(const ResourceId &other) const;

  bool hasParent() const;

  ResourceId getParentResourceId() const;

  bool isDatabaseAccess() const;

  bool isRelationAccess() const;

  bool isBlockAccess() const;

  bool isTupleAccess() const;

  std::string toString() const;
  
private:  
  database_id db_id_;
  relation_id rel_id_;
  block_id block_id_;
  tuple_id tuple_id_;
};

}

#endif
