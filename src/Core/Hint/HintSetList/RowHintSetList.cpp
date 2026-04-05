#include "Core/Hint/HintSetList/RowHintSetList.h"

#include "Core/Board/BoardLength/ColumnLength.h"
#include "Core/Hint/HintSetList/HintSetList.h"

namespace VersaNo::Core {

RowHintSetList::RowHintSetList(std::vector<HintSet> hintSetList) : HintSetList(hintSetList) {}

HintSet RowHintSetList::operator[](RowIndex rowIndex) const {
    return hintSetList[rowIndex.getIndex()];
}

ColumnLength RowHintSetList::getMaxHintSetLength() const { return ColumnLength(getMaxItemCount()); }

} // namespace VersaNo::Core