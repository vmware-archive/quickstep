#ifndef QUICKSTEP_TRANSACTION_LOCK_HPP_
#define QUICKSTEP_TRANSACTION_LOCK_HPP_

#include "transaction/AccessMode.hpp"
#include "transaction/ResourceId.hpp"

namespace quickstep {

class Lock {
public:
  Lock(ResourceId rid, AccessMode access_mode);

  bool operator==(const Lock &other) const;

  ResourceId getResourceId() const;

  AccessMode getAccessMode() const;
private:
  ResourceId rid_;
  AccessMode access_mode_;
};
  
}

#endif
