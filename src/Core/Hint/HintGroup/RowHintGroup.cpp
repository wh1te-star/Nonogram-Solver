#include "Core/Hint/HintGroup/RowHintGroup.h"

#include "Core/Types/AppliedType/AppliedType.h"

namespace VersaNo::Core {

RowHintGroup::RowHintGroup(std::vector<HintList> hintGroup) : hintGroup(hintGroup) {}

std::vector<HintList> RowHintGroup::getHintGroup() const { return hintGroup; }

bool RowHintGroup::operator==(const RowHintGroup &other) const { return hintGroup == other.hintGroup; }

bool RowHintGroup::operator!=(const RowHintGroup &other) const { return !(*this == other); }

HintList RowHintGroup::operator[](RowIndex rowIndex) const {
    return hintGroup[rowIndex.value];
}

size_t RowHintGroup::size() const { return hintGroup.size(); }

ColumnLength RowHintGroup::getMaxHintListLength() const {
    int maxSize = 0;
    for (const HintList &hintList : hintGroup) {
        maxSize = std::max(maxSize, (int)hintList.size());
    }
    return ColumnLength(maxSize);
}


} // namespace VersaNo::Core