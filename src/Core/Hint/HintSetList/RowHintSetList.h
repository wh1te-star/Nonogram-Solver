#ifndef VERSAN_CORE_ROWHINTSETLIST_H
#define VERSAN_CORE_ROWHINTSETLIST_H

#include "Core/Board/BoardLength/ColumnLength.h"
#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Hint/HintSetList/HintSetList.h"
#include "Core/Index/CellIndex/RowIndex.h"

namespace VersaNo::Core {

class RowHintSetList : public HintSetList {
  public:
    explicit RowHintSetList(std::vector<HintSet> hintSetList);

  public:
    HintSet operator[](RowIndex rowIndex) const;

  public:
    ColumnLength getMaxHintSetLength() const;
};

} // namespace VersaNo::Core

#endif // VERSAN_CORE_ROWHINTSETLIST_H
