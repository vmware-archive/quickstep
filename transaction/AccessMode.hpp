#ifndef QUICKSTEP_TRANSACTION_ACCESS_MODE_HPP_
#define QUICKSTEP_TRANSACTION_ACCESS_MODE_HPP_

#include <cstdint>

namespace quickstep {

class AccessMode {
public:
  enum class AccessModeType : std::uint8_t {
    kNO_LOCK = 0,
    kIS_LOCK = 1,
    kIX_LOCK = 2,
    kS_LOCK = 3,
    kSIX_LOCK = 4,
    kX_LOCK = 5
  };
  
  AccessMode(AccessModeType access_mode)
    : access_mode_(access_mode) {}
  
  /* Returns true is this access mode compatible with other access mode */  
  bool isCompatible(const AccessMode &other) const;

  bool isIntentionShareLock() const;

  bool isIntentionExclusiveLock() const;

  bool isShareIntentionExclusiveLock() const;

  bool isShareLock() const;

  bool isExclusiveLock() const;

  bool operator==(const AccessMode &other) const;
  
private:
  
  static constexpr std::uint64_t kNUMBER_LOCKS = 6;

  static constexpr bool kCOMP_MATRIX[kNUMBER_LOCKS][kNUMBER_LOCKS] = {
/*           NL     IS     IX      S     SIX     X    */
/*  NL  */ {true , true , true , true , true , true },
/*  IS  */ {true , true , true , true , true , false},
/*  IX  */ {true , true , true , false, false, false},
/*  S   */ {true , true , false, true , false, false},
/*  SIX */ {true , true , false, false, false, false},
/*  X   */ {true , false, false, false, false, false}
  };

  AccessModeType access_mode_;
};

}
#endif
