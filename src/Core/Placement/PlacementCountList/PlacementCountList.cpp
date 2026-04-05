#include "Core/Placement/PlacementCountList/PlacementCountList.h"

#include <algorithm>
#include "Core/Placement/PlacementCount/PlacementCount.h"

namespace VersaN::Core {

PlacementCountList::PlacementCountList(std::vector<PlacementCount> placementCountList) :
	placementCountList(placementCountList) {}

const std::vector<PlacementCount>& PlacementCountList::getPlacementCountList() const {
	return placementCountList;
}

bool PlacementCountList::operator==(const PlacementCountList& other) const {
    return placementCountList == other.placementCountList;
}

bool PlacementCountList::operator!=(const PlacementCountList& other) const {
    return !(*this == other);
}

} // namespace VersaN::Core