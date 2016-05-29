#include "types/DecimalType.hpp"

#include <cstdint>
#include <cstdio>
#include <string>
#include <sstream>

#include "types/DecimalLit.hpp"
#include "types/NullCoercibilityCheckMacro.hpp"
#include "types/Type.hpp"
#include "types/TypeID.hpp"
#include "utility/EqualsAnyConstant.hpp"

#include "glog/logging.h"

namespace quickstep {

const TypeID DecimalType::kStaticTypeID = kDecimal;

bool DecimalType::isSafelyCoercibleFrom(const Type &original_type) const {
  QUICKSTEP_NULL_COERCIBILITY_CHECK();
  return QUICKSTEP_EQUALS_ANY_CONSTANT(original_type.getTypeID(),
                                       kInt, kDecimal);
}

TypedValue DecimalType::coerceValue(const TypedValue &original_value,
                                    const Type &original_type) const {
  DCHECK(isCoercibleFrom(original_type))
      << "Can't coerce value of Type " << original_type.getName()
      << " to Type " << getName();

  if (original_value.isNull()) {
    return makeNullValue();
  }

  switch (original_type.getTypeID()) {
    case kInt:
      return TypedValue(DecimalLit::fromInt(original_value.getLiteral<int>()));
    case kLong:
      return TypedValue(DecimalLit::fromInt(original_value.getLiteral<std::int64_t>()));
    case kFloat:
      return TypedValue(DecimalLit::fromDouble(original_value.getLiteral<float>()));
    case kDouble:
      return original_value;
    default:
      LOG(FATAL) << "Attempted to coerce Type " << original_type.getName()
                 << " (not recognized as a numeric Type) to " << getName();
  }
}

std::string DecimalType::printValueToString(const TypedValue &value) const {
  DCHECK(!value.isNull());

  DecimalLit decimal = value.getLiteral<DecimalLit>();
  std::stringstream ss;
  ss << decimal.getIntegerPart() << "."
     << decimal.getFractionalPart();
  return ss.str();
}

void DecimalType::printValueToFile(const TypedValue &value,
                                   FILE *file,
                                   const int padding) const {
  DCHECK(!value.isNull());

  DecimalLit decimal = value.getLiteral<DecimalLit>();
  std::fprintf(file, "%*ld.%lu",
               static_cast<int>(padding),
               decimal.getIntegerPart(),
               decimal.getFractionalPart());
}

bool DecimalType::parseValueFromString(const std::string &value_string,
                                       TypedValue *value) const {
  double parsed_double;
  int read_chars;

  int matched = std::sscanf(value_string.c_str(),
                            "%lf%n",
                            &parsed_double,
                            &read_chars);

  if (matched != 1 || read_chars != value_string.length())  {
    return false;
  }

  *value = TypedValue(DecimalLit::fromDouble(parsed_double));
  return true;
}

}  // namespace quickstep
