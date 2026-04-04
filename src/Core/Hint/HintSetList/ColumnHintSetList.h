#ifndef COLUMNHINTSETLIST_H
#define COLUMNHINTSETLIST_H

#include "Core/Board/BoardLength/RowLength.h"
#include "Core/Hint/HintSetList/HintSetList.h"
#include "Core/Index/CellIndex/ColumnIndex.h"

class ColumnHintSetList : public HintSetList {
public:
  explicit ColumnHintSetList(std::vector<HintSet> hintSetList);

public:
  HintSet operator[](ColumnIndex columnIndex) const;

public:
  RowLength getMaxHintSetLength() const;
};

#endif
