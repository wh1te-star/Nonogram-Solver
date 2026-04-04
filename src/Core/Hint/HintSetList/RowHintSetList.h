#ifndef ROWHINTSETLIST_H
#define ROWHINTSETLIST_H

#include "Core/Board/BoardLength/ColumnLength.h"
#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Hint/HintSetList/HintSetList.h"
#include "Core/Index/CellIndex/RowIndex.h"

class RowHintSetList : public HintSetList {
public:
  explicit RowHintSetList(std::vector<HintSet> hintSetList);

public:
  HintSet operator[](RowIndex rowIndex) const;

public:
  ColumnLength getMaxHintSetLength() const;
};

#endif
