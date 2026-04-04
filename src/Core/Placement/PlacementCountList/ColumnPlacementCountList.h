#ifndef COLUMNPLACEMENTCOUNTLIST_H
#define COLUMNPLACEMENTCOUNTLIST_H

#include "Core/Index/CellIndex/ColumnIndex.h"
#include "Core/Placement/PlacementCountList/PlacementCountList.h"

class ColumnPlacementCountList : public PlacementCountList {
public:
  explicit ColumnPlacementCountList(
      std::vector<PlacementCount> placementCountList);

public:
  const PlacementCount &operator[](ColumnIndex index) const;
  PlacementCount &operator[](ColumnIndex index);
};

#endif
