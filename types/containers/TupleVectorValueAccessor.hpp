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

#ifndef QUICKSTEP_TYPES_CONTAINERS_TUPLE_VECTOR_VALUE_ACCESSOR_HPP_
#define QUICKSTEP_TYPES_CONTAINERS_TUPLE_VECTOR_VALUE_ACCESSOR_HPP_

#include <cstddef>
#include <limits>
#include <utility>
#include <vector>

#include "catalog/CatalogTypedefs.hpp"
#include "storage/StorageBlockInfo.hpp"
#include "storage/ValueAccessor.hpp"
#include "types/TypedValue.hpp"
#include "types/containers/Tuple.hpp"
#include "utility/Macros.hpp"

#include "glog/logging.h"

namespace quickstep {

class TupleIdSequence;

/**
 * @brief Implementation of ValueAccessor as a vector of tuples.
 **/
class TupleVectorValueAccessor : public ValueAccessor {
 public:
  TupleVectorValueAccessor()
      : current_position_(std::numeric_limits<std::size_t>::max()) {
  }

  ~TupleVectorValueAccessor() override {
  }

  Implementation getImplementationType() const override {
    return Implementation::kTupleVector;
  }

  bool isTupleIdSequenceAdapter() const override {
    return false;
  }

  bool isOrderedTupleIdSequenceAdapter() const override {
    return false;
  }

  /**
   * @brief Adds a tuple into the value-accessor.
   *
   * @param tuple The tuple to be added to this value-accessor.
   **/
  void addTuple(Tuple &&tuple) {
    tuples_.emplace_back(std::move(tuple));
  }

  inline void beginIteration() {
    current_position_ = std::numeric_limits<std::size_t>::max();
  }

  inline bool iterationFinished() const {
    return current_position_ + 1 >= tuples_.size();
  }

  inline bool next() {
    ++current_position_;
    return current_position_ < tuples_.size();
  }

  inline void previous() {
    --current_position_;
  }

  inline tuple_id getCurrentPosition() const {
    return current_position_;
  }

  inline tuple_id getEndPosition() const {
    return tuples_.size();
  }

  inline tuple_id getNumTuples() const {
    return tuples_.size();
  }

  template <bool check_null = true>
  inline const void* getUntypedValue(const attribute_id attr_id) const {
    return getUntypedValueAtAbsolutePosition<check_null>(attr_id, current_position_);
  }

  inline TypedValue getTypedValue(const attribute_id attr_id) const {
    return getTypedValueAtAbsolutePosition(attr_id, current_position_);
  }

  template <bool check_null = true>
  inline const void* getUntypedValueAtAbsolutePosition(const attribute_id attr_id,
                                                       const tuple_id tid) const {
    DCHECK(tupleIdInRange(tid));
    return tuples_[tid].getAttributeValue(attr_id).getDataPtr();
  }

  inline TypedValue getTypedValueAtAbsolutePosition(const attribute_id attr_id,
                                                    const tuple_id tid) const {
    DCHECK(tupleIdInRange(tid));
    return tuples_[tid].getAttributeValue(attr_id).makeReferenceToThis();
  }

  inline Tuple* getTuple() const {
    return getTupleAtAbsolutePosition(current_position_);
  }

  inline Tuple* getTupleWithAttributes(const std::vector<attribute_id> &attributes) const {
    return getTupleAtAbsolutePositionWithAttributes(current_position_, attributes);
  }

  inline Tuple* getTupleAtAbsolutePosition(const tuple_id tid) const {
    DCHECK(tupleIdInRange(tid));
    return tuples_[tid].clone();
  }

  inline Tuple* getTupleAtAbsolutePositionWithAttributes(
      const tuple_id tid,
      const std::vector<attribute_id> &attributes) const {
    DCHECK(tupleIdInRange(tid));
    std::vector<TypedValue> values;
    for (const attribute_id attr_id : attributes) {
      values.emplace_back(getTypedValueAtAbsolutePosition(attr_id, tid));
    }
    return new Tuple(std::move(values));
  }

  inline TupleIdSequenceAdapterValueAccessor<TupleVectorValueAccessor>*
      createSharedTupleIdSequenceAdapter(const TupleIdSequence &id_sequence) {
    return new TupleIdSequenceAdapterValueAccessor<TupleVectorValueAccessor>(
        this,
        id_sequence,
        false);
  }

  inline OrderedTupleIdSequenceAdapterValueAccessor<TupleVectorValueAccessor>*
  createSharedOrderedTupleIdSequenceAdapter(const OrderedTupleIdSequence& id_sequence) {
    return new OrderedTupleIdSequenceAdapterValueAccessor<TupleVectorValueAccessor>(this, id_sequence, false);
  }

  inline const TupleIdSequence* getTupleIdSequence() const {
    return nullptr;
  }

  // Implementation of virtuals that pass-through to the inline
  // implementations.
  void beginIterationVirtual() override {
    beginIteration();
  }

  bool iterationFinishedVirtual() const override {
    return iterationFinished();
  }

  bool nextVirtual() override {
    return next();
  }

  void previousVirtual() override {
    previous();
  }

  tuple_id getCurrentPositionVirtual() const override {
    return getCurrentPosition();
  }

  tuple_id getEndPositionVirtual() const override {
    return getEndPosition();
  }

  tuple_id getNumTuplesVirtual() const override {
    return getNumTuples();
  }

  const void* getUntypedValueVirtual(const attribute_id attr_id) const override {
    return getUntypedValue(attr_id);
  }

  TypedValue getTypedValueVirtual(const attribute_id attr_id) const override {
    return getTypedValue(attr_id);
  }

  const void* getUntypedValueAtAbsolutePositionVirtual(
      const attribute_id attr_id,
      const tuple_id tid) const override {
    return getUntypedValueAtAbsolutePosition(attr_id, tid);
  }

  TypedValue getTypedValueAtAbsolutePositionVirtual(
      const attribute_id attr_id,
      const tuple_id tid) const override {
    return getTypedValueAtAbsolutePosition(attr_id, tid);
  }

  Tuple* getTupleVirtual() const override {
    return getTuple();
  }

  Tuple* getTupleWithAttributesVirtual(
      const std::vector<attribute_id> &attributes) const override {
    return getTupleWithAttributes(attributes);
  }

  ValueAccessor* createSharedTupleIdSequenceAdapterVirtual(
      const TupleIdSequence &id_sequence) override {
    return createSharedTupleIdSequenceAdapter(id_sequence);
  }

  const TupleIdSequence* getTupleIdSequenceVirtual() const override {
    return getTupleIdSequence();
  }

 private:
  inline bool tupleIdInRange(const tuple_id tid) const {
    return (tid >= 0) && (static_cast<std::size_t>(tid) < tuples_.size());
  }

  std::vector<Tuple> tuples_;
  std::size_t current_position_;

  DISALLOW_COPY_AND_ASSIGN(TupleVectorValueAccessor);
};

}  // namespace quickstep

#endif  // QUICKSTEP_TYPES_CONTAINERS_TUPLE_VECTOR_VALUE_ACCESSOR_HPP_
