#ifndef QUICKSTEP_TYPES_DECIMAL_LIT_HPP_
#define QUICKSTEP_TYPES_DECIMAL_LIT_HPP_

#include <cstdint>
#include <cmath>

namespace quickstep {

/** \addtogroup Type
 *  @{
 */

/**
 * @brief A literal representing fixed-precision decimal.
 **/
struct DecimalLit {
  typedef std::int64_t data_type;

  static DecimalLit fromDouble(double value) {
    return DecimalLit{static_cast<data_type>(value * kMaxFractionInt)};
  }

  static DecimalLit fromInt(int64_t value) {
    return DecimalLit{static_cast<data_type>(value * kMaxFractionInt)};
  }

  data_type data_;

  static constexpr std::uint64_t kPrecisionWidth = 4;

  static constexpr std::int64_t kMaxFractionInt = 10000;

  inline std::uint64_t getFractionalPart() const {
    return static_cast<std::uint64_t>(static_cast<std::uint64_t>(std::abs(data_)) % kMaxFractionInt);
  }

  inline std::int64_t getIntegerPart() const {
    return static_cast<std::uint64_t>(static_cast<std::uint64_t>(std::abs(data_)) / kMaxFractionInt);
  };

  inline bool operator<(const DecimalLit& other) const {
    return data_ < other.data_;
  }

  inline bool operator>(const DecimalLit& other) const {
    return data_ > other.data_;
  }

  inline bool operator<=(const DecimalLit& other) const {
    return data_ <= other.data_;
  }

  inline bool operator>=(const DecimalLit& other) const {
    return data_ >= other.data_;
  }

  inline bool operator==(const DecimalLit& other) const {
    return data_ == other.data_;
  }

  inline bool operator!=(const DecimalLit& other) const {
    return data_ != other.data_;
  }

  inline DecimalLit operator-() const {
    return DecimalLit{-data_};
  }

  inline DecimalLit operator+(const DecimalLit& other) const {
    return DecimalLit{data_ + other.data_};
  }

  inline DecimalLit operator-(const DecimalLit& other) const {
    return DecimalLit{data_ - other.data_};
  }

  inline DecimalLit operator*(const DecimalLit& other) const {
    return DecimalLit{(data_ * other.data_) / kMaxFractionInt};
  }

  inline DecimalLit operator/(const DecimalLit& other) const {
    return DecimalLit{(data_ * kMaxFractionInt) / other.data_};
  }

  inline DecimalLit operator%(const DecimalLit& other) const {
    return DecimalLit{data_ % other.data_};
  }

  inline DecimalLit& operator+=(const DecimalLit& other) {
    data_ += other.data_;
    return *this;
  }

  inline DecimalLit& operator-=(const DecimalLit& other) {
    data_ -= other.data_;
    return *this;
  }

  inline DecimalLit& operator*=(const DecimalLit& other) {
    data_ = (data_ * other.data_) / kMaxFractionInt;
    return *this;
  }

  inline DecimalLit& operator/=(const DecimalLit& other) {
    data_ = (data_ * kMaxFractionInt) / other.data_;
    return *this;
  }
};

//** @} */

}  // namespace quickstep

#endif  // QUICKSTEP_TYPES_DECIMAL_LIT_HPP_
