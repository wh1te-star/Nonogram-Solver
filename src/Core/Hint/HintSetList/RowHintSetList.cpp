#include "Hint/HintSetList/RowHintSetList.h"

#include "Board/BoardLength/ColumnLength.h"
#include "Hint/HintSetList/HintSetList.h"

RowHintSetList::RowHintSetList(std::vector<HintSet> hintSetList)
    : HintSetList(hintSetList) {}

HintSet RowHintSetList::operator[](RowIndex rowIndex) const {
  return hintSetList[rowIndex.getIndex()];
}

ColumnLength RowHintSetList::getMaxHintSetLength() const {
  return ColumnLength(getMaxItemCount());
}
