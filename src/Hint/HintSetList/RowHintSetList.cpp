#include "RowHintSetList.h"

#include "HintSetList.h"
#include "ColumnLength.h"

RowHintSetList::RowHintSetList(std::vector<HintSet> hintSetList) :
	HintSetList(hintSetList) {}

HintSet RowHintSetList::operator[](RowIndex rowIndex) const {
	return hintSetList[rowIndex.getIndex()];
}

ColumnLength RowHintSetList::getMaxHintSetLength() const {
	return ColumnLength(getMaxItemCount());
}

