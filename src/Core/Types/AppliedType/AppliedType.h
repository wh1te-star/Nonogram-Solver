#ifndef VERSANO_CORE_APPLIEDTYPE_H
#define VERSANO_CORE_APPLIEDTYPE_H

namespace VersaNo::Core {

// Tags
struct BoardTag {};
struct RowTag : BoardTag {};
struct ColTag : BoardTag {};
struct HintTag {};

// Aliases
struct RowLength : LengthType<RowLength, RowTag> { using LengthType::LengthType; };
struct RowIndex  : IndexType<RowIndex, RowTag, RowLength> { using IndexType::IndexType; };

struct ColLength : LengthType<ColLength, ColTag> { using LengthType::LengthType; };
struct ColIndex  : IndexType<ColIndex, ColTag, ColLength> { using IndexType::IndexType; };

struct HintIndex  : IndexType<HintIndex, HintTag> { using IndexType::IndexType; };
struct HintNumber : LengthType<HintNumber, HintTag> { using LengthType::LengthType; };
struct PlacementCount : IntType<PlacementCount, HintTag> { using IntType::IntType; };

template <typename T>
using CellIndex = std::enable_if_t<std::is_base_of_v<BoardTag, typename T::TagType>, T>;

using RowLine = ListType<Cell, RowIndex>;
using ColLine = ListType<Cell, ColIndex>;
using HintList = ListType<HintNumber, HintIndex>;

} // namespace VersaNo::Core

#endif // VERSANO_CORE_APPLIEDTYPE_H