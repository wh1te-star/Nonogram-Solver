#include "Core/Hint/HintSetList/ColumnHintSetList.h"

#include "Core/Board/BoardLength/RowLength.h"
#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Index/CellIndex/ColumnIndex.h"

namespace VersaNo::Core {

ColumnHintSetList::ColumnHintSetList(std::vector<HintSet> hintSetList) : HintSetList(hintSetList) {}

HintSet ColumnHintSetList::operator[](ColumnIndex columnIndex) const {
    return hintSetList[columnIndex.getIndex()];
}

RowLength ColumnHintSetList::getMaxHintSetLength() const { return RowLength(getMaxItemCount()); }

} // namespace VersaNo::Core