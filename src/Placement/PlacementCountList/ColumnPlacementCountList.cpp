#include "Placement/PlacementCountList/ColumnPlacementCountList.h"

#include "Index/CellIndex/ColumnIndex.h"
#include "Placement/PlacementCount/PlacementCount.h"

ColumnPlacementCountList::ColumnPlacementCountList(
    std::vector<PlacementCount> placementCountList)
    : PlacementCountList(placementCountList) {}

const PlacementCount &
ColumnPlacementCountList::operator[](ColumnIndex index) const {
  return placementCountList[index.getIndex()];
}

PlacementCount &ColumnPlacementCountList::operator[](ColumnIndex index) {
  return placementCountList[index.getIndex()];
}
