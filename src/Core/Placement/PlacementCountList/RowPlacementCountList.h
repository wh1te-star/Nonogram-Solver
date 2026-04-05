#ifndef VERSAN_CORE_ROWPLACEMENTCOUNTLIST_H
#define VERSAN_CORE_ROWPLACEMENTCOUNTLIST_H

#include "Core/Index/CellIndex/RowIndex.h"
#include "Core/Placement/PlacementCount/PlacementCount.h"
#include "Core/Placement/PlacementCountList/PlacementCountList.h"

namespace VersaN::Core {

class RowPlacementCountList : public PlacementCountList {
  public:
    explicit RowPlacementCountList(std::vector<PlacementCount> placementCountList);

  public:
    const PlacementCount &operator[](RowIndex index) const;
    PlacementCount &operator[](RowIndex index);
};

} // namespace VersaN::Core

#endif // VERSAN_CORE_ROWPLACEMENTCOUNTLIST_H
