/**
 *   Copyright 2011-2015 Quickstep Technologies LLC.
 *   Copyright 2015-2016 Pivotal Software, Inc.
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

#include "cli/CommandExecutor.hpp"

#include <cstddef>
#include <cstdio>
#include <memory>
#include <string>
#include <vector>

#include "catalog/CatalogAttribute.hpp"
#include "catalog/CatalogDatabase.hpp"
#include "catalog/CatalogRelation.hpp"
#include "catalog/CatalogRelationSchema.hpp"
#include "cli/PrintToScreen.hpp"
#include "parser/ParseStatement.hpp"
#include "utility/PtrVector.hpp"
#include "utility/Macros.hpp"
#include "utility/SqlError.hpp"

#include "gflags/gflags.h"
#include "glog/logging.h"

using std::fprintf;
using std::fputc;
using std::fputs;
using std::size_t;
using std::vector;
using std::string;

namespace quickstep {

void CommandExecutor::executeCommand(const ParseStatement &statement,
                                     const CatalogDatabase *catalog_database,
                                     FILE *out) {
  const ParseCommand &command = static_cast<const ParseCommand &>(statement);
  const PtrVector<ParseString> *arguments = command.arguments();
  std::string command_str = command.command()->value();
  if (command_str.compare("\\dt") == 0) {
    executeDescribeDatabase(arguments, catalog_database, out);
  } else if (command_str.compare("\\d") == 0) {
    if (arguments->size() == 0) {
      executeDescribeDatabase(arguments, catalog_database, out);
    } else {
      executeDescribeTable(arguments, catalog_database, out);
    }
  } else {
    THROW_SQL_ERROR_AT(command.command()) << "Invalid Command";
  }
}

void CommandExecutor::executeDescribeDatabase(
    const PtrVector<ParseString> *arguments,
    const CatalogDatabase *catalog_database, FILE *out) {
  std::size_t relation_count = 0;
  // Column width initialized to 6 to take into account the header name
  // and the column value table
  int max_column_width = 6;
  const CatalogRelation *relation;
  if (arguments->size() == 0) {
    for (auto rel_it = catalog_database->begin();
         rel_it != catalog_database->end(); ++rel_it) {
      int column_width = static_cast<int>(rel_it->getName().length());
      max_column_width =
          max_column_width < column_width ? column_width : max_column_width;
      relation_count++;
    }
  } else {
    const ParseString &table_name = arguments->front();
    const std::string &table_name_val = table_name.value();
    relation = catalog_database->getRelationByName(table_name_val);
    int column_width = static_cast<int>(relation->getName().length());
    max_column_width =
        max_column_width < column_width ? column_width : max_column_width;
    relation_count++;
  }
  // only if we have relations
  if (relation_count > 0) {
    vector<int> column_widths;
    column_widths.reserve(relation_count);
    column_widths.push_back(max_column_width);
    column_widths.push_back(max_column_width);
    fputs("       List of relations\n\n", out);
    fprintf(out, "%-*s|", max_column_width, " Name");
    fprintf(out, "%-*s|", 6, " Type");
    fputc('\n', out);
    PrintToScreen::printHBar(column_widths, out);
    //  if there are no argument print the entire list of tables
    //  else print the particular table only
    if (arguments->size() == 0) {
      for (auto rel_it = catalog_database->begin();
           rel_it != catalog_database->end(); ++rel_it) {
        fprintf(out, " %-*s|", max_column_width, rel_it->getName().c_str());
        fprintf(out, " %-*s", max_column_width, "table");
        fputc('\n', out);
      }
    } else {
      fprintf(out, " %-*s|", max_column_width, relation->getName().c_str());
      fprintf(out, " %-*s", max_column_width, "table");
      fputc('\n', out);
    }
    fputc('\n', out);
  }
}

void CommandExecutor::executeDescribeTable(
    const PtrVector<ParseString> *arguments,
    const CatalogDatabase *catalog_database, FILE *out) {
  const ParseString &table_name = arguments->front();
  const std::string &table_name_val = table_name.value();
  const CatalogRelation *relation =
      catalog_database->getRelationByName(table_name_val);
  vector<int> column_widths;
  // initialize it to the number of columns that need to be printed
  column_widths.reserve(2);

  int max_column_width = 0;
  for (CatalogRelation::const_iterator attr_it = relation->begin();
       attr_it != relation->end(); ++attr_it) {
    // Printed column needs to be wide enough to print:
    //   1. The attribute name (in the printed "header").
    //   2. Any value of the attribute's Type.
    //   3. If the attribute's Type is nullable, the 4-character string "NULL".
    // We pick the largest of these 3 widths as the column width.
    int column_width = static_cast<int>(attr_it->getDisplayName().length());
    column_width = column_width < attr_it->getType().getPrintWidth()
                       ? attr_it->getType().getPrintWidth()
                       : column_width;
    column_width = attr_it->getType().isNullable() && (column_width < 4)
                       ? 4
                       : column_width;
    max_column_width =
        column_width > max_column_width ? column_width : max_column_width;
  }
  column_widths.push_back(max_column_width);
  column_widths.push_back(max_column_width);

  fprintf(out, "%*s \"%s\"", 6, "Table", table_name_val.c_str());
  fputc('\n', out);
  fprintf(out, "%-*s|", max_column_width, "Column");
  fprintf(out, "%-*s", max_column_width, "Type");
  fputc('\n', out);
  PrintToScreen::printHBar(column_widths, out);
  for (CatalogRelation::const_iterator attr_it = relation->begin();
       attr_it != relation->end(); ++attr_it) {
    fprintf(out, "%-*s|", max_column_width, attr_it->getDisplayName().c_str());
    fprintf(out, "%-*s", max_column_width,
            attr_it->getType().getName().c_str());
    fputc('\n', out);
  }
  // TODO(rogers): add partitioning information
  if (relation->hasIndexScheme()) {
    fputs("Indexes:", out);
    fputc('\n', out);
    const quickstep::IndexScheme &index_scheme = relation->getIndexScheme();
    for (auto index_it = index_scheme.begin(); index_it != index_scheme.end();
         ++index_it) {
      fprintf(out, "\"%-*s\" %s", static_cast<int>(index_it->first.length()),
              index_it->first.c_str(),
              index_it->second.IndexSubBlockType_Name(
                                  index_it->second.sub_block_type())
                  .c_str());
      fputc(' ', out);
      fputc('(', out);
      auto indexed_fields_it = index_it->second.indexed_attribute_ids().begin();
      ++indexed_fields_it;
      fprintf(out, "%s", relation->getAttributeById(*indexed_fields_it)
                               ->getDisplayName()
                               .c_str());
      for (;
           indexed_fields_it != index_it->second.indexed_attribute_ids().end();
           ++indexed_fields_it) {
        fprintf(out, ", %s", relation->getAttributeById(*indexed_fields_it)
                                 ->getDisplayName()
                                 .c_str());
      }
      fputc(')', out);
      fputc('\n', out);
    }
  }
}
}  // namespace quickstep

