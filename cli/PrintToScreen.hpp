/**
 *   Copyright 2011-2015 Quickstep Technologies LLC.
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

#ifndef QUICKSTEP_CLI_PRINT_TO_SCREEN_HPP_
#define QUICKSTEP_CLI_PRINT_TO_SCREEN_HPP_

#include <cstdio>
#include <vector>

#include "storage/StorageBlockInfo.hpp"
#include "utility/Macros.hpp"

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


	/**
	   * @brief Print all the tuples in the relation.
	   * @param out FILE pointer to print the tuples to.
	   **/ 
	  void printRelation(FILE *out);


  /**
     * @brief Print the header containing the column names to the relation.
     * @param out FILE pointer to print the header to.
     **/
    void printHeader(FILE *out) const;

    PrintToScreen(const CatalogRelation &relation,
                   StorageManager *storage_manager)
         : relation_(relation), storage_manager_(storage_manager) {
       computeColumnWidths();
     }

    /**
     * @brief Print the tuples in a block of a relation.
     * @param block Block ID whose tuples are to be printed.
     * @param out FILE pointer to print the tuples to.
     **/
    void printBlock(block_id block, FILE *out);


  void printHBar(const std::vector<int> &column_widths,
                        FILE *out);

  /**
   * @brief Get the total number of tuples in the given relation.
   *
   * @param relation The given relation.
   * @param storage_manager The storage manager.
   *
   * @return The total number of tuples in the relation.
   **/
  static std::size_t GetNumTuplesInRelation(const CatalogRelation &relation,
                                            StorageManager *storage_manager);

  /**
   * @brief Print the size of the output (i.e. number of rows in the relation).
   *
   * @param relation The given relation.
   * @param storage_manager The storage manager.
   * @param out The output stream.
   **/
  static void PrintOutputSize(const CatalogRelation &relation,
                              StorageManager *storage_manager,
                              FILE *out);

  /**
   * @brief Return the number of digits in a number
   *
   * @param number The input number.
   * @param out The number of digits in the input number.
   **/
  static int GetNumberOfDigits(int number);

 private:


  // Computes the widths of each column based on the types.
  void computeColumnWidths();

  void printHBar(FILE *out) const;

    // Print the tuple to output.
    void printTuple(const TupleStorageSubBlock &tuple_store,
                    const tuple_id tid,
                    FILE *out) const;

  const CatalogRelation &relation_;  // Relation to print.
  std::vector<int> column_widths_;  // Precomputed column-widths.
  StorageManager *storage_manager_;


  DISALLOW_COPY_AND_ASSIGN(PrintToScreen);
};

/** @} */

}  // namespace quickstep

#endif  // QUICKSTEP_CLI_PRINT_TO_SCREEN_HPP_
