/**
 *   Copyright 2011-2015 Quickstep Technologies LLC.
 *   Copyright 2015 Pivotal Software, Inc.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       https://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 **/

#ifndef QUICKSTEP_TYPES_OPERATIONS_COMPARISONS_COMPARISON_FACTORY_HPP_
#define QUICKSTEP_TYPES_OPERATIONS_COMPARISONS_COMPARISON_FACTORY_HPP_

#include "types/operations/comparisons/ComparisonID.hpp"
#include "utility/Macros.hpp"

namespace quickstep {

class Comparison;
namespace serialization { class Comparison; }

/** \addtogroup Types
 *  @{
 */

/**
 * @brief All-static factory object that provides access to Comparisons.
 **/
class ComparisonFactory {
 public:
  /**
   * @brief Convenience factory method to get a reference to a Comparison from
   *        that Comparison's ID.
   *
   * @param id The ID of the desired Comparison.
   * @return The Comparison corresponding to id.
   **/
  static const Comparison& GetComparison(const ComparisonID id);

  /**
   * @brief Get a reference to a Comparison from that Comparison's serialized
   *        Protocol Buffer representation.
   *
   * @param proto A serialized Protocol Buffer representation of a Comparison,
   *        originally generated by getProto().
   * @return The Comparison described by proto.
   **/
  static const Comparison& ReconstructFromProto(const serialization::Comparison &proto);

  /**
   * @brief Check whether a serialization::Comparison is fully-formed and
   *        all parts are valid.
   *
   * @param proto A serialized Protocol Buffer representation of a Comparison,
   *        originally generated by getProto().
   * @return Whether proto is fully-formed and valid.
   **/
  static bool ProtoIsValid(const serialization::Comparison &proto);

 private:
  ComparisonFactory();

  DISALLOW_COPY_AND_ASSIGN(ComparisonFactory);
};

/** @} */

}  // namespace quickstep

#endif  // QUICKSTEP_TYPES_OPERATIONS_COMPARISONS_COMPARISON_FACTORY_HPP_
