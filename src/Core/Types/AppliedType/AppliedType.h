#ifndef VERSANO_CORE_APPLIEDTYPE_H
#define VERSANO_CORE_APPLIEDTYPE_H

#include "Core/Cell/Cell/Cell.h"

namespace VersaNo::Core {

// Tags
struct BoardTag {};
struct RowTag : BoardTag {};
struct ColTag : BoardTag {};
struct HintTag {};

// Aliases
struct RowLength : LengthType<RowLength, RowTag> {
    using LengthType::LengthType;
};
struct RowIndex : IndexType<RowIndex, RowTag, RowLength> {
    using IndexType::IndexType;
};

struct ColumnLength : LengthType<ColumnLength, ColTag> {
    using LengthType::LengthType;
};
struct ColumnIndex : IndexType<ColumnIndex, ColTag, ColumnLength> {
    using IndexType::IndexType;
};

struct HintIndex : IndexType<HintIndex, HintTag> {
    using IndexType::IndexType;
};
struct HintNumber : LengthType<HintNumber, HintTag> {
    using LengthType::LengthType;
};
struct PlacementCount : IntType<PlacementCount, HintTag> {
    using IntType::IntType;
};

struct AppliedType {
    using RowLength = VersaNo::Core::RowLength;
    using RowIndex = VersaNo::Core::RowIndex;
    using ColumnLength = VersaNo::Core::ColumnLength;
    using ColumnIndex = VersaNo::Core::ColumnIndex;
    using HintIndex = VersaNo::Core::HintIndex;
    using HintNumber = VersaNo::Core::HintNumber;
    using PlacementCount = VersaNo::Core::PlacementCount;
};


} // namespace VersaNo::Core

#endif // VERSANO_CORE_APPLIEDTYPE_H