#include "Core/Placement/PlacementCountList/RowPlacementCountList.h"

#include "Core/Types/AppliedType/AppliedType.h"

#include <algorithm>

namespace VersaNo::Core {

RowPlacementCountList::RowPlacementCountList(std::vector<PlacementCount> placementCountList)
    : placementCountList(placementCountList) {}

const std::vector<PlacementCount> &RowPlacementCountList::getPlacementCountList() const {
    return placementCountList;
}

bool RowPlacementCountList::operator==(const RowPlacementCountList &other) const {
    return placementCountList == other.placementCountList;
}

bool RowPlacementCountList::operator!=(const RowPlacementCountList &other) const {
    return !(*this == other);
}

const PlacementCount &RowPlacementCountList::operator[](RowIndex index) const {
    return placementCountList[index.value];
}

PlacementCount &RowPlacementCountList::operator[](RowIndex index) {
    return placementCountList[index.value];
}

} // namespace VersaNo::Core