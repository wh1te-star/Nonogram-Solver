#ifndef VERSAN_CORE_PLACEMENTCOUNTLIST_H
#define VERSAN_CORE_PLACEMENTCOUNTLIST_H

#include "Core/Placement/PlacementCount/PlacementCount.h"

#include <vector>

namespace VersaNo::Core {

class PlacementCountList {
  protected:
    std::vector<PlacementCount> placementCountList;

  protected:
    explicit PlacementCountList(std::vector<PlacementCount> placementCountList);

  public:
    virtual ~PlacementCountList() = default;

  public:
    const std::vector<PlacementCount> &getPlacementCountList() const;

  public:
    bool operator==(const PlacementCountList &other) const;
    bool operator!=(const PlacementCountList &other) const;
};

} // namespace VersaNo::Core

#endif // VERSAN_CORE_PLACEMENTCOUNTLIST_H
