/**
 *   Copyright 2016, Quickstep Research Group, Computer Sciences Department,
 *     University of Wisconsin—Madison.
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

#ifndef QUICKSTEP_CLI_PRINT_TO_SCREEN_HPP_
#define QUICKSTEP_CLI_PRINT_TO_SCREEN_HPP_

#include <cstdio>
#include <vector>

#include "storage/StorageBlockInfo.hpp"
#include "utility/Macros.hpp"

using std::size_t;

namespace quickstep {

class CatalogRelation;
class StorageManager;
class TupleStorageSubBlock;

/** \addtogroup CLI
 *  @{
 */

/**
 * @brief All static methods which print all of the tuples in a relation to
 *        a FILE* stream.
 **/
class PrintToScreen {
 public:
  static void PrintRelation(const CatalogRelation &relation,
                            StorageManager *storage_manager,
                            FILE *out);
  static void printHBar(const std::vector<std::size_t> &column_widths,
                        FILE *out);
 private:
  // Undefined default constructor. Class is all-static and should not be
  // instantiated.
  PrintToScreen();

  static void printTuple(const TupleStorageSubBlock &tuple_store,
                         const tuple_id tid,
                         const std::vector<std::size_t> &column_widths,
                         FILE *out);

  DISALLOW_COPY_AND_ASSIGN(PrintToScreen);
};

/** @} */

}  // namespace quickstep

#endif  // QUICKSTEP_CLI_PRINT_TO_SCREEN_HPP_
