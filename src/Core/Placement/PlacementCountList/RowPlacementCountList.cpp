#include "Core/Placement/PlacementCountList/RowPlacementCountList.h"

#include "Core/Index/CellIndex/RowIndex.h"
#include "Core/Placement/PlacementCount/PlacementCount.h"

namespace VersaN::Core {

RowPlacementCountList::RowPlacementCountList(
    std::vector<PlacementCount> placementCountList)
    : PlacementCountList(placementCountList) {}

const PlacementCount &RowPlacementCountList::operator[](RowIndex index) const {
  return placementCountList[index.getIndex()];
}

PlacementCount &RowPlacementCountList::operator[](RowIndex index) {
  return placementCountList[index.getIndex()];
}

} // namespace VersaN::Core