#include "Core/Hint/HintGroup/HintGroup.h"

#include "Core/Hint/HintList/HintList.h"

#include <algorithm>

namespace VersaNo::Core {

HintGroup::HintGroup(std::vector<HintList> hintGroup) : hintGroup(hintGroup) {}

std::vector<HintList> HintGroup::getHintGroup() const { return hintGroup; }

bool HintGroup::operator==(const HintGroup &other) const { return hintGroup == other.hintGroup; }

bool HintGroup::operator!=(const HintGroup &other) const { return !(*this == other); }

const HintList &HintGroup::operator[](const CellIndex &index) const {
    return hintGroup[index.getIndex()];
}

size_t HintGroup::size() const { return hintGroup.size(); }

int HintGroup::getMaxItemCount() const {
    int maxSize = 0;
    for (const auto &HintList : hintGroup) {
        maxSize = std::max(maxSize, (int)HintList.size());
    }
    return maxSize;
}

} // namespace VersaNo::Core