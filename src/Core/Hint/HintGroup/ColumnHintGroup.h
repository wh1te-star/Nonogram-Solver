#ifndef VERSANO_CORE_COLUMNHINTSETLIST_H
#define VERSANO_CORE_COLUMNHINTSETLIST_H

#include "Core/Board/BoardLength/RowLength.h"
#include "Core/Hint/HintGroup/HintGroup.h"
#include "Core/Index/CellIndex/ColumnIndex.h"

namespace VersaNo::Core {

class ColumnHintGroup : public HintGroup {
  public:
    explicit ColumnHintGroup(std::vector<HintList> hintGroup);

  public:
    HintList operator[](ColumnIndex columnIndex) const;

  public:
    RowLength getMaxHintListLength() const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_COLUMNHINTSETLIST_H
