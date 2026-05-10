#ifndef VERSANO_CORE_PLACEMENTCOUNTSNAPSHOT_H
#define VERSANO_CORE_PLACEMENTCOUNTSNAPSHOT_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Board/Board/Board.h"
#include "Core/Placement/PlacementCountList/ColumnPlacementCountList.h"
#include "Core/Placement/PlacementCountList/RowPlacementCountList.h"
#include "Solver/Assumption/Snapshot/ISnapshot.h"

namespace VersaNo::Solver {

class PlacementCountSnapshot : public ISnapshot {
  public:
    Core::Board board;
    Core::RowPlacementCountList rowPlacementCountList;
    Core::ColumnPlacementCountList columnPlacementCountList;

    PlacementCountSnapshot(
      Core::Board board,
      Core::RowPlacementCountList rowPlacementCountList,
      Core::ColumnPlacementCountList columnPlacementCountList);

    void restore(Core::NonogramBoard &nonogramBoard) const override;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_PLACEMENTCOUNTSNAPSHOT_H