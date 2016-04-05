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

#ifndef QUICKSTEP_CLI_COMMAND_COMMAND_EXECUTOR_HPP_
#define QUICKSTEP_CLI_COMMAND_COMMAND_EXECUTOR_HPP_

#include <cstdio>
#include <string>

#include "parser/ParseStatement.hpp"
#include "utility/Macros.hpp"

using std::fprintf;
using std::fputc;
using std::size_t;
using std::string;

namespace quickstep {

class CatalogDatabase;
class CatalogAttribute;
class CatalogRelation;


/** \addtogroup CLI
 *  @{
 */

/**
 * @brief Execution handlers for various quickstep cli commands
 */
class CommandExecutor {
 public:
  /**
   * @brief Executes the command by calling the command handler.
   *        
   * @param statement The parsed statement from the cli.
   * @param catalog_database The catalog information about the current database.
   * @param out The stream where the output of the command has to be redirected to.      
   */
  static void executeCommand(const ParseStatement &statement,
                             const CatalogDatabase *catalog_database,
                             FILE *out);

 private:
  static const std::size_t kInitMaxColumnWidth;
  CommandExecutor();

  /**
   * @brief Command handler for the describe table command
   *        The command is invoked by \d in cli and takes a table name as argument.
   *        This displays the type information about the columns in the table
   *        information about indexes and partitioning.    
   *        
   * @param command The parsed command from the cli.
   * @param catalog_database The catalog information about the current database.
   * @param out The stream where the output of the command has to be redirected to.      
   */
  static void executeDescribeTable(const PtrVector<ParseString>* arguments,
                                   const CatalogDatabase *catalog_database,
                                   FILE *out);

  /**
   * @brief Command handler for the describe database command
   *        The command is invoked by \d or \dt in cli. This 
   *        lists all the tables in the database.
   *        
   * @param statement The parsed command from the cli.
   * @param catalog_database The catalog information about the current database.
   * @param out The stream where the output of the command has to be redirected to.      
   */
  static void executeDescribeDatabase(const PtrVector<ParseString>* arguments,
                                      const CatalogDatabase *catalog_database,
                                      FILE *out);

  DISALLOW_COPY_AND_ASSIGN(CommandExecutor);
};

/** @} */

}  // namespace quickstep

#endif  // QUICKSTEP_CLI_COMMAND_COMMAND_EXECUTOR_HPP_
