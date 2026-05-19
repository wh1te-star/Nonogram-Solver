#ifndef VERSANO_CORE_APPLIEDTYPE_H
#define VERSANO_CORE_APPLIEDTYPE_H

#include "Core/Cell/Cell/Cell.h"
#include "Core/Types/PrimitiveType/IntType/IntType.h"
#include "Core/Types/DomainType/IndexType/IndexType.h"
#include "Core/Types/DomainType/LengthType/LengthType.h"
#include "Core/Types/DomainType/PlacementType/PlacementType.h"
#include "Core/Types/DomainType/LineType/LineType.h"
#include "Core/Types/DomainType/HintListType/HintListType.h"
#include "Core/Types/DomainType/HintGroupType/HintGroupType.h"

namespace VersaNo::Core {

// ============================================================================
// Domain Tags & Enums
// ============================================================================

struct BoardTag {};
struct RowTag : BoardTag {};
struct ColumnTag : BoardTag {};
struct HintTag {};

enum class EOrientation { Row, Column };
struct RowOrientation {};
struct ColumnOrientation {};



// ============================================================================
// Row-Specific Scalar Types
// ============================================================================

struct RowLength : LengthType<RowLength, RowTag> {
    using LengthType::LengthType;
};

struct RowIndex : IndexType<RowIndex, RowTag, RowLength> {
    using IndexType::IndexType;
};



// ============================================================================
// Column-Specific Scalar Types
// ============================================================================

struct ColumnLength : LengthType<ColumnLength, ColumnTag> {
    using LengthType::LengthType;
};

struct ColumnIndex : IndexType<ColumnIndex, ColumnTag, ColumnLength> {
    using IndexType::IndexType;
};



// ============================================================================
// Hint & Logic Scalar Types
// ============================================================================

struct HintIndex : IndexType<HintIndex, HintTag> {
    using IndexType::IndexType;
};

struct HintNumber : IntType<HintNumber, HintTag> {
    using IntType::IntType;
};

struct PlacementCount : IntType<PlacementCount, HintTag> {
    using IntType::IntType;
};

using RowPlacementCountList = ListType<PlacementCount, RowIndex>;
using ColumnPlacementCountList = ListType<PlacementCount, ColumnIndex>;



// ============================================================================
// Composite Line Types (Container Wrappers)
// ============================================================================

using Row = Line<ColumnIndex>;
using RowPlacement = Placement<ColumnIndex>;

using Column = Line<RowIndex>;
using ColumnPlacement = Placement<RowIndex>;

using HintList = HintListType<HintNumber, HintIndex>;



// ============================================================================
// Hint Group Types (List of HintLists)
// ============================================================================

using RowHintGroup = HintGroupType<HintList, RowIndex>;

using ColumnHintGroup = HintGroupType<HintList, ColumnIndex>;




// ============================================================================
// Orientation Traits (Type Resolver)
// ============================================================================

template <typename TOrientation> struct LineTraits;

template <> struct LineTraits<RowOrientation> {
    using Index = RowIndex;
    using PeerIndex = ColumnIndex;
    using Length = RowLength;
    using PeerLength = ColumnLength;
    using Line = Row;
    using PeerLine = Column;
    using Placement = RowPlacement;
    using PeerPlacement = ColumnPlacement;
};

template <> struct LineTraits<ColumnOrientation> {
    using Index = ColumnIndex;
    using PeerIndex = RowIndex;
    using Length = ColumnLength;
    using PeerLength = RowLength;
    using Line = Column;
    using PeerLine = Row;
    using Placement = ColumnPlacement;
    using PeerPlacement = RowPlacement;
};


} // namespace VersaNo::Core

#endif // VERSANO_CORE_APPLIEDTYPE_H