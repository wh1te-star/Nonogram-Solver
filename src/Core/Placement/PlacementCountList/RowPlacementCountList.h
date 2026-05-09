#ifndef VERSANO_CORE_ROWPLACEMENTCOUNTLIST_H
#define VERSANO_CORE_ROWPLACEMENTCOUNTLIST_H

#include "Core/Types/AppliedType/AppliedType.h"

#include <vector>

namespace VersaNo::Core {

class RowPlacementCountList {
  private:
    std::vector<PlacementCount> placementCountList;

  public:
    explicit RowPlacementCountList(std::vector<PlacementCount> placementCountList);

  public:
    const std::vector<PlacementCount> &getPlacementCountList() const;

  public:
    bool operator==(const RowPlacementCountList &other) const;
    bool operator!=(const RowPlacementCountList &other) const;
    const PlacementCount &operator[](RowIndex index) const;
    PlacementCount &operator[](RowIndex index);
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_ROWPLACEMENTCOUNTLIST_H
