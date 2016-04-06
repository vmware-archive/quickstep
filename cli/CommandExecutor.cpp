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

#include "cli/CommandExecutor.hpp"

#include <algorithm>
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
using std::string;
using std::vector;

namespace quickstep {

const std::size_t  CommandExecutor::kInitMaxColumnWidth = 6;

void CommandExecutor::executeCommand(const ParseStatement &statement,
                                     const CatalogDatabase &catalog_database,
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
    const CatalogDatabase &catalog_database, FILE *out) {
  // Column width initialized to 6 to take into account the header name
  // and the column value table
  std::size_t max_column_width = CommandExecutor::kInitMaxColumnWidth;
  const CatalogRelation *relation;
  if (arguments->size() == 0) {
    for (const CatalogRelation &rel : catalog_database) {
      std::size_t column_width = rel.getName().length();
      max_column_width =
          max_column_width < column_width ? column_width : max_column_width;
    }
  } else {
    const ParseString &table_name = arguments->front();
    const std::string &table_name_val = table_name.value();
    relation = catalog_database.getRelationByName(table_name_val);

    if (relation == nullptr) {
     THROW_SQL_ERROR_AT(&(arguments->front())) << " Unrecognized relation "  <<table_name_val;
    }
    std::size_t column_width = relation->getName().length();
    max_column_width =
        max_column_width < column_width ? column_width : max_column_width;
  }
  // Only if we have relations work on the printing logic.
  if (catalog_database.size() > 0) {
    vector<std::size_t> column_widths;
    column_widths.push_back(max_column_width);
    column_widths.push_back(CommandExecutor::kInitMaxColumnWidth);
    fputs("       List of relations\n\n", out);
    fprintf(out, "%-*s|", static_cast<int>(max_column_width)+1, " Name");
    fprintf(out, "%-*s\n", static_cast<int>(CommandExecutor::kInitMaxColumnWidth), " Type");
    PrintToScreen::printHBar(column_widths, out);
    //  If there are no argument print the entire list of tables
    //  else print the particular table only.
    if (arguments->size() == 0) {
      for (const CatalogRelation &rel : catalog_database) {
        fprintf(out, " %-*s|", static_cast<int>(max_column_width), rel.getName().c_str());
        fprintf(out, " %-*s\n", static_cast<int>(CommandExecutor::kInitMaxColumnWidth), "table");
      }
    } else {
      fprintf(out, " %-*s|", static_cast<int>(max_column_width), relation->getName().c_str());
      fprintf(out, " %-*s\n", static_cast<int>(CommandExecutor::kInitMaxColumnWidth), "table");
    }
    fputc('\n', out);
  }
}

void CommandExecutor::executeDescribeTable(
    const PtrVector<ParseString> *arguments,
    const CatalogDatabase &catalog_database, FILE *out) {
  const ParseString &table_name = arguments->front();
  const std::string &table_name_val = table_name.value();
  const CatalogRelation *relation =
      catalog_database.getRelationByName(table_name_val);
  if (relation == nullptr) {
     THROW_SQL_ERROR_AT(&(arguments->front())) << " Unrecognized relation "  <<table_name_val;
  }
  vector<std::size_t> column_widths;
  std::size_t max_attr_column_width = CommandExecutor::kInitMaxColumnWidth;
  std::size_t max_type_column_width = CommandExecutor::kInitMaxColumnWidth-1;

  for (const CatalogAttribute &attr : *relation) {
    // Printed column needs to be wide enough to print:
    //   1. The attribute name (in the printed "header").
    //   2. Any value of the attribute's Type.
    std::size_t attr_column_width = attr.getDisplayName().length();
    std::size_t type_column_width = attr.getType().getName().length();
    max_attr_column_width = std::max(max_attr_column_width, attr_column_width);
    max_type_column_width = std::max(max_type_column_width, type_column_width);
  }
  column_widths.push_back(max_attr_column_width);
  column_widths.push_back(max_type_column_width);

  fprintf(out, "%*s \"%s\"\n", static_cast<int>(CommandExecutor::kInitMaxColumnWidth), "Table", table_name_val.c_str());
  fprintf(out, "%-*s|", static_cast<int>(max_attr_column_width)+1, " Column");
  fprintf(out, "%-*s", static_cast<int>(max_type_column_width)+1, " Type\n");
  PrintToScreen::printHBar(column_widths, out);
  for (const CatalogAttribute &attr : *relation) {
    fprintf(out, " %-*s|", static_cast<int>(max_attr_column_width),
            attr.getDisplayName().c_str());
    fprintf(out, " %-*s\n", static_cast<int>(max_type_column_width),
            attr.getType().getName().c_str());
  }
  // TODO(rogers): Add handlers for partitioning information.
  if (relation->hasIndexScheme()) {
    fputs("Indexes:\n", out);
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
      fprintf(out, "%s", relation->getAttributeById(index_it->second.indexed_attribute_ids(0))
                               ->getDisplayName()
                               .c_str());
      for (std::size_t i = 1; i < index_it->second.indexed_attribute_ids_size(); ++i) {
        fprintf(out, ", %s", relation->getAttributeById(index_it->second.indexed_attribute_ids(i))
                               ->getDisplayName()
                               .c_str());
      }
      fputc(')', out);
      fputc('\n', out);
    }
  }
}
}  // namespace quickstep

