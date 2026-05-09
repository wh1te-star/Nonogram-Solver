#include "Core/Placement/PlacementCountList/ColumnPlacementCountList.h"

#include "Core/Types/AppliedType/AppliedType.h"

#include <algorithm>

namespace VersaNo::Core {

ColumnPlacementCountList::ColumnPlacementCountList(std::vector<PlacementCount> placementCountList)
    : placementCountList(placementCountList) {}

const std::vector<PlacementCount> &ColumnPlacementCountList::getPlacementCountList() const {
    return placementCountList;
}

bool ColumnPlacementCountList::operator==(const ColumnPlacementCountList &other) const {
    return placementCountList == other.placementCountList;
}

bool ColumnPlacementCountList::operator!=(const ColumnPlacementCountList &other) const {
    return !(*this == other);
}

const PlacementCount &ColumnPlacementCountList::operator[](ColumnIndex index) const {
    return placementCountList[index.value];
}

PlacementCount &ColumnPlacementCountList::operator[](ColumnIndex index) {
    return placementCountList[index.value];
}

} // namespace VersaNo::Core