#ifndef VERSANO_CORE_APPLIEDTYPE_H
#define VERSANO_CORE_APPLIEDTYPE_H

#include "Core/Cell/Cell/Cell.h"
#include "Core/Types/PrimitiveType/IntType/IntType.h"
#include "Core/Types/DomainType/IndexType/IndexType.h"
#include "Core/Types/DomainType/LengthType/LengthType.h"

namespace VersaNo::Core {


// Tags
struct BoardTag {};
struct RowTag : BoardTag {};
struct ColTag : BoardTag {};
struct HintTag {};

// Row Types
struct RowLength : LengthType<RowLength, RowTag> {
    using LengthType::LengthType;
};
struct RowIndex : IndexType<RowIndex, RowTag, RowLength> {
    using IndexType::IndexType;
};

// Column Types
struct ColumnLength : LengthType<ColumnLength, ColTag> {
    using LengthType::LengthType;
};
struct ColumnIndex : IndexType<ColumnIndex, ColTag, ColumnLength> {
    using IndexType::IndexType;
};

// Hint Types
struct HintIndex : IndexType<HintIndex, HintTag> {
    using IndexType::IndexType;
};
struct HintNumber : IntType<HintNumber, HintTag> {
    using IntType::IntType;
};

// Placement Type
struct PlacementCount : IntType<PlacementCount, HintTag> {
    using IntType::IntType;
};

// Orientations and their traits
enum class EOrientation { Row, Column };

struct RowOrientation {};
struct ColumnOrientation {};

template <typename TOrientation> struct LineTraits;

template <> struct LineTraits<RowOrientation> {
    using Index = RowIndex;
    using PeerIndex = ColumnIndex;
    using Length = RowLength;
    using PeerLength = ColumnLength;
};

template <> struct LineTraits<ColumnOrientation> {
    using Index = ColumnIndex;
    using PeerIndex = RowIndex;
    using Length = ColumnLength;
    using PeerLength = RowLength;
};


} // namespace VersaNo::Core

#endif // VERSANO_CORE_APPLIEDTYPE_H