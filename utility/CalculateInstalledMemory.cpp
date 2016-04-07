/**
 *   Copyright 2016 Pivotal Software, Inc.
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

#include "utility/CalculateInstalledMemory.hpp"
#include "utility/UtilityConfig.h"

#if defined(QUICKSTEP_HAVE_SYSCONF)
#include <unistd.h>
#elif defined(QUICKSTEP_HAVE_WINDOWS)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include "glog/logging.h"

namespace quickstep {
namespace utility {
namespace system {

  int calculateTotalMemoryInBytes(std::uint64_t &available_memory) {
#if defined(QUICKSTEP_HAVE_SYSCONF)
    std::uint64_t num_pages = static_cast<std::uint64_t>(sysconf(_SC_PHYS_PAGES));
    std::uint64_t page_size = static_cast<std::uint64_t>(sysconf(_SC_PAGE_SIZE));
    if (num_pages > 0 &&  page_size > 0) {
      available_memory = static_cast<std::uint64_t>(num_pages * page_size);
      LOG(INFO) << "Total memory is " << available_memory << " bytes\n";
      return 0;
    }
    LOG(INFO) << "Could not compute the available memory using sysconf\n";
    return -1;
#elif defined(QUICKSTEP_HAVE_WINDOWS)
    MEMORYSTATUSEX mem_status;
    mem_status.dwLength = sizeof(mem_status);
    GlobalMemoryStatusEx(&mem_status);
    if (mem_status.ullTotalPhys > 0) {
      available_memory = static_cast<std::uint64_t>(mem_status.ullTotalPhys);
      LOG(INFO) << "Total memory is " << available_memory << " bytes\n";
      return 0;
    }
    LOG(INFO) << "Could not compute the total installed memory using GlobalMemoryStatusEx\n";
    return -1;
#else
    // TODO(jmp): Expand to find other ways to calculate the installed memory.
#error "No implementation available to calculate the installed memory."
#endif
}

}  // namespace system
}  // namespace utility
}  // namespace quickstep
