#ifndef VERSANO_CORE_COLUMNHINTSETLIST_H
#define VERSANO_CORE_COLUMNHINTSETLIST_H

#include "Core/Board/BoardLength/RowLength.h"
#include "Core/Hint/HintSetList/HintSetList.h"
#include "Core/Index/CellIndex/ColumnIndex.h"

namespace VersaNo::Core {

class ColumnHintSetList : public HintSetList {
  public:
    explicit ColumnHintSetList(std::vector<HintSet> hintSetList);

  public:
    HintSet operator[](ColumnIndex columnIndex) const;

  public:
    RowLength getMaxHintSetLength() const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_COLUMNHINTSETLIST_H
