#ifndef VERSANO_CORE_ROWHINTSETLIST_H
#define VERSANO_CORE_ROWHINTSETLIST_H

#include "Core/Board/BoardLength/ColumnLength.h"
#include "Core/Hint/HintGroup/HintGroup.h"
#include "Core/Hint/HintList/HintList.h"
#include "Core/Index/CellIndex/RowIndex.h"

namespace VersaNo::Core {

class RowHintGroup : public HintGroup {
  public:
    explicit RowHintGroup(std::vector<HintList> hintGroup);

  public:
    HintList operator[](RowIndex rowIndex) const;

  public:
    ColumnLength getMaxHintListLength() const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_ROWHINTSETLIST_H
