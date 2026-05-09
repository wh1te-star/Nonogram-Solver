#ifndef VERSANO_CORE_COLUMNPLACEMENTCOUNTLIST_H
#define VERSANO_CORE_COLUMNPLACEMENTCOUNTLIST_H

#include "Core/Types/AppliedType/AppliedType.h"

#include <vector>

namespace VersaNo::Core {

class ColumnPlacementCountList {
  private:
    std::vector<PlacementCount> placementCountList;

  public:
    explicit ColumnPlacementCountList(std::vector<PlacementCount> placementCountList);

  public:
    const std::vector<PlacementCount> &getPlacementCountList() const;

  public:
    bool operator==(const ColumnPlacementCountList &other) const;
    bool operator!=(const ColumnPlacementCountList &other) const;
    const PlacementCount &operator[](ColumnIndex index) const;
    PlacementCount &operator[](ColumnIndex index);
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_COLUMNPLACEMENTCOUNTLIST_H
