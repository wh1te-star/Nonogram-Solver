#include "Core/Placement/PlacementCountList/ColumnPlacementCountList.h"

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Placement/PlacementCount/PlacementCount.h"

namespace VersaNo::Core {

ColumnPlacementCountList::ColumnPlacementCountList(std::vector<PlacementCount> placementCountList)
    : PlacementCountList(placementCountList) {}

const PlacementCount &ColumnPlacementCountList::operator[](ColumnIndex index) const {
    return placementCountList[index.getIndex()];
}

PlacementCount &ColumnPlacementCountList::operator[](ColumnIndex index) {
    return placementCountList[index.getIndex()];
}

} // namespace VersaNo::Core