#ifndef QUICKSTEP_TRANSACTION_RESOURCE_ID_HPP_
#define QUICKSTEP_TRANSACTION_RESOURCE_ID_HPP_

#include <limits>
#include <string>
#include <type_traits>

#include "catalog/CatalogTypedefs.hpp"
#include "storage/StorageBlockInfo.hpp"
#include "utility/HashPair.hpp"
#include "utility/Macros.hpp"

namespace quickstep {

namespace transaction {

/** \addtogroup Transaction
 *  @{
 */

/**
 * @brief Class for representing unique id for each database resource
 *        e.g Tuple, block, relation, database etc...
 **/
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

  /**
   * @brief Constructor for invalid resource id.
   **/
  ResourceId()
    : ResourceId(kDB_ID_PLACEHOLDER, kREL_ID_PLACEHOLDER,
                 kBLOCK_ID_PLACEHOLDER, kTUPLE_ID_PLACEHOLDER) {}

  /**
   * @brief Constructor for database level resource id.
   *
   * @param db_id unique id of database resource.
   **/
  explicit ResourceId(database_id db_id)
    : ResourceId(db_id, kREL_ID_PLACEHOLDER,
                   kBLOCK_ID_PLACEHOLDER,
                   kTUPLE_ID_PLACEHOLDER) {}
  /**
   * @brief Constructor for relation level resource id.
   *
   * @param db_id unique id of database resource.
   * @param rel_id unique id of relation resource in database.
   **/
  ResourceId(database_id db_id, relation_id rel_id)
    : ResourceId(db_id, rel_id, kBLOCK_ID_PLACEHOLDER,
                   kTUPLE_ID_PLACEHOLDER) {}

  /**
   * @brief Constructor for block level resource id.
   *
   * @param db_id unique id of the databse resource.
   * @param rel_id unique id of the relation resource in the database.
   * @param block_id unique id of the block resource in the relation.
   **/
  ResourceId(database_id db_id, relation_id rel_id,
             block_id block_id)
    : ResourceId(db_id, rel_id, block_id,
                   kTUPLE_ID_PLACEHOLDER) {}

  /**
   * @brief Constructor for tuple level resource id.
   *
   * @param db_id Unique id of the database resource.
   * @param rel_id Unique id of the relation resource in the database.
   * @param block_id Unique id of the block resource in the relation.
   * @param tuple_id Unique id of the tuple resource in the block.
   **/
  ResourceId(database_id db_id, relation_id rel_id,
             block_id block_id, tuple_id tuple_id)
    : db_id_(db_id), rel_id_(rel_id),
      block_id_(block_id), tuple_id_(tuple_id) {}

  /**
   * @brief Copy constructor.
   *
   * @param other The ResourceId that will be copied.
   **/
  ResourceId(const ResourceId &other) {
    this->db_id_ = other.db_id_;
    this->rel_id_ = other.rel_id_;
    this->block_id_ = other.block_id_;
    this->tuple_id_ = other.tuple_id_;
  }

  /**
   * @brief Hasher class for ResourceId class to use it in the hash map.
   **/
  struct ResourceIdHasher {
    /**
     * @brief Functor of the class.
     *
     * @param rid Resource id to be hashed.
     * @return Hash of the resource id.
     **/
    std::size_t operator()(const ResourceId &rid) const;
  };

  /**
   * @brief Equality operator for ResourceId class.
   *
   * @param other Resource
   * @return True if this and other are the id of the same
   *         resource, false otherwise.
   **/
  bool operator==(const ResourceId &other) const;

  /**
   * @brief Checks whether this resource id has a parent in resource hierarchy.
   *
   * @return False if this resource id is database level, true otherwise.
   **/
  bool hasParent() const;

  /**
   * @brief Getter for this resource id's parent in the hierarchy.
   *
   * @return The resource id of this resource id's parent.
   **/
  ResourceId getParentResourceId() const;

  /**
   * @brief Checks whether this is a database level resource id.
   *
   * @return True if this is a database level access, false otherwise.
   **/
  bool isDatabaseAccess() const;

  /**
   * @brief Checks whether this is a relation level resource id.
   *
   * @return True if this is a relation level access, false otherwise.
   **/
  bool isRelationAccess() const;

  /**
   * @brief Checks whether this is a block level resource id.
   *
   * @return True if this is a block level access, false otherwise.
   **/
  bool isBlockAccess() const;

  /**
   * @brief Checks whether this is a tuple level resource id.
   *
   * @return True if this is a tuple level access, false otherwise.
   **/
  bool isTupleAccess() const;

  /**
   * @brief This is a helper method for string representation
   *        of the resource id.
   *
   * @return String representation of this.
   **/
  std::string toString() const;

 private:
  database_id db_id_;
  relation_id rel_id_;
  block_id block_id_;
  tuple_id tuple_id_;
};

/** @} */

}  // namespace transaction

}  // namespace quickstep

#endif
