#include "ColumnPlacementCountList.h"

#include "PlacementCount.h"
#include "ColumnIndex.h"

ColumnPlacementCountList::ColumnPlacementCountList(std::vector<PlacementCount> placementCountList) :
	PlacementCountList(placementCountList) {}

const PlacementCount& ColumnPlacementCountList::operator[](ColumnIndex index) const {
    return placementCountList[index.getIndex()]; 
}

PlacementCount& ColumnPlacementCountList::operator[](ColumnIndex index) {
    return placementCountList[index.getIndex()]; 
}
