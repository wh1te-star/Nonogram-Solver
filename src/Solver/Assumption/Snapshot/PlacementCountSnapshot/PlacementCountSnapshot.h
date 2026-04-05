#ifndef VERSAN_CORE_PLACEMENTCOUNTSNAPSHOT_H
#define VERSAN_CORE_PLACEMENTCOUNTSNAPSHOT_H

#include "Core/Board/Board/Board.h"
#include "Core/Placement/PlacementCountList/ColumnPlacementCountList.h"
#include "Core/Placement/PlacementCountList/PlacementCountList.h"
#include "Core/Placement/PlacementCountList/RowPlacementCountList.h"
#include "Solver/Assumption/Snapshot/ISnapshot.h"

namespace VersaN::Solver {

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

} // namespace VersaN::Solver

#endif // VERSAN_CORE_PLACEMENTCOUNTSNAPSHOT_H