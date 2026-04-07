#include "Core/Hint/HintGroup/RowHintGroup.h"

#include "Core/Board/BoardLength/ColumnLength.h"
#include "Core/Hint/HintGroup/HintGroup.h"

namespace VersaNo::Core {

RowHintGroup::RowHintGroup(std::vector<HintList> hintGroup) : HintGroup(hintGroup) {}

HintList RowHintGroup::operator[](RowIndex rowIndex) const {
    return hintGroup[rowIndex.getIndex()];
}

ColumnLength RowHintGroup::getMaxHintListLength() const { return ColumnLength(getMaxItemCount()); }

} // namespace VersaNo::Core