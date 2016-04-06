/**
 *   Copyright 2015 Pivotal Software, Inc.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 **/

#ifndef QUICKSTEP_CALCULATE_INSTALLED_MEMORY_HPP_
#define QUICKSTEP_CALCULATE_INSTALLED_MEMORY_HPP_

#include <cstddef>
#include <functional>

namespace quickstep {
namespace utility {
namespace system {

  /**
   * @brief Compute the amount of (DRAM) memory installed on the machine.
   * @param available_memory return the available memory in bytes.
   * @return 0 on success, -1 otherwise.
   */
  int calculateAvailableMemoryInBytes(std::uint64_t& available_memory);

}  // namespace system
}  // namespace utility
}  // namespace quickstep

#endif  // QUICKSTEP_CALCULATE_INSTALLED_MEMORY_HPP_
