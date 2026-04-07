#include "Core/Hint/HintGroup/ColumnHintGroup.h"

#include "Core/Board/BoardLength/RowLength.h"
#include "Core/Hint/HintList/HintList.h"
#include "Core/Index/CellIndex/ColumnIndex.h"

namespace VersaNo::Core {

ColumnHintGroup::ColumnHintGroup(std::vector<HintList> hintGroup) : HintGroup(hintGroup) {}

HintList ColumnHintGroup::operator[](ColumnIndex columnIndex) const {
    return hintGroup[columnIndex.getIndex()];
}

RowLength ColumnHintGroup::getMaxHintListLength() const { return RowLength(getMaxItemCount()); }

} // namespace VersaNo::Core