#include "ColumnHintSetList.h"

#include "ColumnIndex.h"
#include "HintSet.h"
#include "RowLength.h"

ColumnHintSetList::ColumnHintSetList(std::vector<HintSet> hintSetList) :
	HintSetList(hintSetList) {}

HintSet ColumnHintSetList::operator[](ColumnIndex columnIndex) const {
	return hintSetList[columnIndex.getIndex()];
}

RowLength ColumnHintSetList::getMaxHintSetLength() const {
	return RowLength(getMaxItemCount());
}

