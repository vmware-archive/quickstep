#ifndef QUICKSTEP_TRANSACTION_ACCESS_MODE_HPP_
#define QUICKSTEP_TRANSACTION_ACCESS_MODE_HPP_

#include <cstdint>

namespace quickstep {

/** \addtogroup Transaction
 *  @{
 */

/**
 * @brief Class for representing resource lock's access mode
 **/
class AccessMode {
public:
  /**
   * @brief Represents mode type. Possible options are NL, IS, IX, S, SIX, X.
   **/
  enum class AccessModeType : std::uint8_t {
    kNO_LOCK = 0,
    kIS_LOCK = 1,
    kIX_LOCK = 2,
    kS_LOCK = 3,
    kSIX_LOCK = 4,
    kX_LOCK = 5
  };

  /**
   * @brief Only constructor for access mode.
   * 
   * @param access_mode Mode type of the object. 
   **/
  AccessMode(AccessModeType access_mode)
    : access_mode_(access_mode) {}
  
  /**
   * @brief Checks whether this access mode is compatible with the other.
   *
   * @param other Other access mode that will be checked against to this one.
   *
   * @return True if they are compatible, otherwise false.
   */
  bool isCompatible(const AccessMode &other) const;


  /**
   * @brief Checks whether this access mode is IS mode.
   *
   * @return True if it is IS mode, false otherwise.
   */
  bool isIntentionShareLock() const;

  /**
   * @brief Checks whether this access mode is IX mode.
   *
   * @return True if it is IX mode, false otherwise.
   */
  bool isIntentionExclusiveLock() const;

  /**
   * @brief Checks whether this access mdoe is SIX mode.
   *
   * @return True if it is SIX mode, false otherwise.
   */
  bool isShareIntentionExclusiveLock() const;

  /**
   * @brief Checks whether this access mode is S mode.
   *
   * @return True if it is S mode, false otherwise.
   */
  bool isShareLock() const;

  /**
   * @brief Checks whether this access mode is X mode.
   *
   * @return True if it is X mode, false otherwise.
   */
  bool isExclusiveLock() const;

  /*
   * @brief Checks whether this access mode is in the same level with other mode.
   *
   * @return True if both modes have the same level.
   */
  bool operator==(const AccessMode &other) const;
  
private:

  // The compatibility matrix should be N by N. kNUMBER_LOCKS == N.
  static constexpr std::uint64_t kNUMBER_LOCKS = 6;

  // Compatibility matrix for checking access modes. True means they are compatible.
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

/** @} */

}
#endif
