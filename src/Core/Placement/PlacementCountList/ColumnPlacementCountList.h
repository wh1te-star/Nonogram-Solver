#ifndef VERSANO_CORE_COLUMNPLACEMENTCOUNTLIST_H
#define VERSANO_CORE_COLUMNPLACEMENTCOUNTLIST_H

#include "Core/Index/CellIndex/ColumnIndex.h"
#include "Core/Placement/PlacementCountList/PlacementCountList.h"

namespace VersaNo::Core {

class ColumnPlacementCountList : public PlacementCountList {
  public:
    explicit ColumnPlacementCountList(std::vector<PlacementCount> placementCountList);

  public:
    const PlacementCount &operator[](ColumnIndex index) const;
    PlacementCount &operator[](ColumnIndex index);
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_COLUMNPLACEMENTCOUNTLIST_H
