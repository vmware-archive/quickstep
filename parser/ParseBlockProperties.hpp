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

#ifndef QUICKSTEP_PARSER_PARSE_BLOCK_PROPERTIES_HPP_
#define QUICKSTEP_PARSER_PARSE_BLOCK_PROPERTIES_HPP_

#include <memory>
#include <string>
#include <vector>
#include <string>

#include "parser/ParseString.hpp"
#include "parser/ParseTreeNode.hpp"
#include "storage/StorageBlockInfo.hpp"
#include "types/Type.hpp"
#include "utility/Macros.hpp"
#include "utility/PtrList.hpp"

namespace quickstep {

/** \addtogroup Parser
 *  @{
 */

class ParseBlockPropertyItem : public ParseTreeNode {
 public:

  static const std::string AllString;

  enum Property {
    kCompress,
    kSort,
    kType
  };

  /**
   * @brief Constructor.
   *
   * @param line_number Line number of the first token of this node in the SQL statement.
   * @param column_number Column number of the first token of this node in the SQL statement.
   **/
  ParseBlockPropertyItem( int line_number, 
                          int column_number,
                          Property property,
                          ParseString* value)
                                  : ParseTreeNode(line_number, column_number),
                                    property_(property) {
    values_.reset(new PtrList<ParseString>);
    values_->push_back(value);
  }

  ParseBlockPropertyItem( int line_number, 
                          int column_number,
                          Property property,
                          PtrList<ParseString>* values)
                                  : ParseTreeNode(line_number, column_number),
                                    property_(property),
                                    values_(values) { }

  std::string getName() const override {
    return "BlockPropertyItem";
  }

  std::string getPropertyString() const {
    switch(property_) {
      case kCompress:
        return "compress";
      case kSort:
        return "sort";
      case kType:
        return "type";
      default:
        return "unknown";
    }
  }

  bool compressAll() const {
    return (property_ == kCompress && values_->begin()->value().compare(AllString) == 0);
  }

 protected:

  void getFieldStringItems(
      std::vector<std::string> *inline_field_names,
      std::vector<std::string> *inline_field_values,
      std::vector<std::string> *non_container_child_field_names,
      std::vector<const ParseTreeNode*> *non_container_child_fields,
      std::vector<std::string> *container_child_field_names,
      std::vector<std::vector<const ParseTreeNode*>> *container_child_fields) const override {

    inline_field_names->push_back("property");
    inline_field_values->push_back(getPropertyString());

    inline_field_names->push_back("value");
    if(values_->size() > 1) {
      std::string str("(");
      for(const ParseString& parseString : *values_) {
        str += parseString.value();
        str += ",";
      }
      str.erase(str.size() - 1, 1);
      str += ")";
      inline_field_values->push_back(str);
    } else {
      inline_field_values->push_back(values_->begin()->value());
    }
  }

 private:

  Property property_;
  std::unique_ptr<PtrList<ParseString>> values_;

  DISALLOW_COPY_AND_ASSIGN(ParseBlockPropertyItem);
};

/**
 * @brief Contains user-specified physical properties of a table's blocks.
 */
class ParseBlockProperties : public ParseTreeNode {
 public:

  /**
   * @brief Constructor.
   *
   * @param line_number Line number of the first token of this node in the SQL statement.
   * @param column_number Column number of the first token of this node in the SQL statement.
   **/
  ParseBlockProperties( int line_number, 
                        int column_number, 
                        PtrList<ParseBlockPropertyItem>* properties)
                                : ParseTreeNode(line_number, column_number),
                                  properties_(properties) { }

  std::string getName() const override {
    return "BlockProperties";
  }

 protected:
  void getFieldStringItems(
      std::vector<std::string> *inline_field_names,
      std::vector<std::string> *inline_field_values,
      std::vector<std::string> *non_container_child_field_names,
      std::vector<const ParseTreeNode*> *non_container_child_fields,
      std::vector<std::string> *container_child_field_names,
      std::vector<std::vector<const ParseTreeNode*>> *container_child_fields) const override {

    for(auto propertyItem = properties_->begin(); propertyItem != properties_->end(); ++propertyItem) {
      non_container_child_field_names->push_back(propertyItem->getName());
      non_container_child_fields->push_back(&*propertyItem);
    }
  }

 private:
  std::unique_ptr<PtrList<ParseBlockPropertyItem> > properties_;

  DISALLOW_COPY_AND_ASSIGN(ParseBlockProperties);
};

/** @} */

}  // namespace quickstep

#endif  /* QUICKSTEP_PARSER_PARSE_BLOCK_PROPERTIES_HPP_ */
