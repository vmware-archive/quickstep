#include "transaction/Lock.hpp"

namespace quickstep {

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
    
}
