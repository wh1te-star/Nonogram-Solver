#ifndef ROWPLACEMENTCOUNTLIST_H
#define ROWPLACEMENTCOUNTLIST_H

#include "Core/Index/CellIndex/RowIndex.h"
#include "Core/Placement/PlacementCount/PlacementCount.h"
#include "Core/Placement/PlacementCountList/PlacementCountList.h"

class RowPlacementCountList : public PlacementCountList {
public:
  explicit RowPlacementCountList(
      std::vector<PlacementCount> placementCountList);

public:
  const PlacementCount &operator[](RowIndex index) const;
  PlacementCount &operator[](RowIndex index);
};

#endif
