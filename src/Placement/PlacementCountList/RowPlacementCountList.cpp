#include "RowPlacementCountList.h"

#include "PlacementCount.h"
#include "RowIndex.h"

RowPlacementCountList::RowPlacementCountList(std::vector<PlacementCount> placementCountList) :
	PlacementCountList(placementCountList) {}

const PlacementCount& RowPlacementCountList::operator[](RowIndex index) const {
    return placementCountList[index.getIndex()]; 
}

PlacementCount& RowPlacementCountList::operator[](RowIndex index) {
    return placementCountList[index.getIndex()]; 
}

