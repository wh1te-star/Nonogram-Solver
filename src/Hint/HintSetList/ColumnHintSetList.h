#ifndef COLUMNHINTSETLIST_H
#define COLUMNHINTSETLIST_H


#include "HintSetList.h"
#include "ColumnIndex.h"
#include "RowLength.h"

class ColumnHintSetList : public HintSetList {
public:
    explicit ColumnHintSetList(std::vector<HintSet> hintSetList);

public:
	HintSet operator[](ColumnIndex columnIndex) const;

public:
	RowLength getMaxHintSetLength() const;
};


#endif
