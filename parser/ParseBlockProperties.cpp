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

#include "parser/ParseBlockProperties.hpp"

#include <string>

namespace quickstep {

std::string ParseBlockPropertyItem::getPropertyString() const {
  switch (property_) {
    case Property::kCompress:
      return "compress";
    case Property::kSort:
      return "sort";
    case Property::kType:
      return "type";
    default:
      return "unknown";
  }
}

bool ParseBlockPropertyItem::compressAll() const {
  return property_ == Property::kCompress && compress_all_;
}

}  // namespace quickstep
