#ifndef ROWHINTSETLIST_H
#define ROWHINTSETLIST_H


#include "ColumnLength.h"
#include "HintSet.h"
#include "HintSetList.h"
#include "RowIndex.h"

class RowHintSetList : public HintSetList {
public:
    explicit RowHintSetList(std::vector<HintSet> hintSetList);

public:
	HintSet operator[](RowIndex rowIndex) const;

public:
	ColumnLength getMaxHintSetLength() const;
};


#endif
