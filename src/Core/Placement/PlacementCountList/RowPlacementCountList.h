#ifndef VERSANO_CORE_ROWPLACEMENTCOUNTLIST_H
#define VERSANO_CORE_ROWPLACEMENTCOUNTLIST_H

#include "Core/Index/CellIndex/RowIndex.h"
#include "Core/Placement/PlacementCount/PlacementCount.h"
#include "Core/Placement/PlacementCountList/PlacementCountList.h"

namespace VersaNo::Core {

class RowPlacementCountList : public PlacementCountList {
  public:
    explicit RowPlacementCountList(std::vector<PlacementCount> placementCountList);

  public:
    const PlacementCount &operator[](RowIndex index) const;
    PlacementCount &operator[](RowIndex index);
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_ROWPLACEMENTCOUNTLIST_H
