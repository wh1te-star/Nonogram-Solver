#include "Core/Hint/HintGroup/ColumnHintGroup.h"

#include "Core/Types/AppliedType/AppliedType.h"

namespace VersaNo::Core {

ColumnHintGroup::ColumnHintGroup(std::vector<HintList> hintGroup) : hintGroup(hintGroup) {}

std::vector<HintList> ColumnHintGroup::getHintGroup() const { return hintGroup; }

bool ColumnHintGroup::operator==(const ColumnHintGroup &other) const { return hintGroup == other.hintGroup; }

bool ColumnHintGroup::operator!=(const ColumnHintGroup &other) const { return !(*this == other); }

HintList ColumnHintGroup::operator[](ColumnIndex columnIndex) const {
    return hintGroup[columnIndex.value];
}

size_t ColumnHintGroup::size() const { return hintGroup.size(); }

RowLength ColumnHintGroup::getMaxHintListLength() const {
    int maxSize = 0;
    for (const HintList &hintList : hintGroup) {
        maxSize = std::max(maxSize, (int)hintList.size());
    }
    return RowLength(maxSize);
}


} // namespace VersaNo::Core