#ifndef QUICKSTEP_TRANSACTION_LOCK_HPP_
#define QUICKSTEP_TRANSACTION_LOCK_HPP_

#include "transaction/AccessMode.hpp"
#include "transaction/ResourceId.hpp"

namespace quickstep {

/** \addtogroup Transaction
 *  @{
 */

/**
 * @brief Class for representing resource locks. 
 **/
class Lock {
public:
  /**
   * @brief Constructor for Lock class.
   * 
   * @param rid Resource id of the resource on which the lock is taken.
   *
   * @param access_mode Mode of the lock access.
   **/
  Lock(ResourceId rid, AccessMode access_mode);

  /**
   * @brief Equality operator for lock.
   * 
   * @param other Reference to othe Lock object that will be compared against to this 
   *
   * @return True if both locks have equal resource ids and access modes, false otherwise.
   **/
  bool operator==(const Lock &other) const;

  /**
   * @brief Getter for resource id.
   *
   * @return Resource id of the lock.
   **/
  ResourceId getResourceId() const;

  /**
   * @brief Getter for access mode.
   * 
   * @return Access mode of the lock.
   **/
  AccessMode getAccessMode() const;
  
private:
  ResourceId rid_;
  AccessMode access_mode_;
};
  
}

#endif
