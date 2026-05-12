#ifndef VERSANO_CORE_APPLIEDTYPE_H
#define VERSANO_CORE_APPLIEDTYPE_H

#include "Core/Cell/Cell/Cell.h"
#include "Core/Types/PrimitiveType/IntType/IntType.h"
#include "Core/Types/DomainType/IndexType/IndexType.h"
#include "Core/Types/DomainType/LengthType/LengthType.h"
#include "Core/Types/DomainType/PlacementType/PlacementType.h"
#include "Core/Types/DomainType/LineType/LineType.h"
#include "Core/Types/DomainType/HintList/HintList.h"

namespace VersaNo::Core {


// Tags
struct BoardTag {};
struct RowTag : BoardTag {};
struct ColTag : BoardTag {};
struct HintTag {};

// Orientations (Row/Column)
enum class EOrientation { Row, Column };

struct RowOrientation {};
struct ColumnOrientation {};



// ========== Row Types ==========
struct RowLength : LengthType<RowLength, RowTag> {
    using LengthType::LengthType;
};
struct RowIndex : IndexType<RowIndex, RowTag, RowLength> {
    using IndexType::IndexType;
};
struct RowPlacement : Placement<ColumnIndex> {
    using Placement::Placement;
};
struct Row : Line<ColumnIndex> {
    using Line::Line;
};



// ========== Column Types ==========
struct ColumnLength : LengthType<ColumnLength, ColTag> {
    using LengthType::LengthType;
};
struct ColumnIndex : IndexType<ColumnIndex, ColTag, ColumnLength> {
    using IndexType::IndexType;
};
struct ColumnPlacement : Placement<RowIndex> {
    using Placement::Placement;
};
struct Column : Line<RowIndex> {
    using Line::Line;
};



// ========== Hint Types ==========
struct HintIndex : IndexType<HintIndex, HintTag> {
    using IndexType::IndexType;
};
struct HintNumber : IntType<HintNumber, HintTag> {
    using IntType::IntType;
};
using HintList = HintListType<HintNumber, HintIndex>;



// ========== Placement Type ==========
struct PlacementCount : IntType<PlacementCount, HintTag> {
    using IntType::IntType;
};



// ========== Orientations traits ==========
template <typename TOrientation> struct LineTraits;

template <> struct LineTraits<RowOrientation> {
    using Index = RowIndex;
    using PeerIndex = ColumnIndex;
    using Length = RowLength;
    using PeerLength = ColumnLength;
    using Line = Row;
    using Placement = RowPlacement;
};

template <> struct LineTraits<ColumnOrientation> {
    using Index = ColumnIndex;
    using PeerIndex = RowIndex;
    using Length = ColumnLength;
    using PeerLength = RowLength;
    using Line = Column;
    using Placement = ColumnPlacement;
};





} // namespace VersaNo::Core

#endif // VERSANO_CORE_APPLIEDTYPE_H