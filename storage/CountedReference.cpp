/**
 *   Temporary file for debugging.
 **/

#include "storage/CountedReference.hpp"

#include "threading/SpinSharedMutex.hpp"

namespace quickstep {


SpinSharedMutex<false> countedreference_print_mutex;
bool countedreference_print_stacktrace = false;

}  // namespace quickstep
