#ifndef PLACEMENTCOUNTSNAPSHOT_H
#define PLACEMENTCOUNTSNAPSHOT_H

#include "Core/Board/Board/Board.h"
#include "Core/Placement/PlacementCountList/ColumnPlacementCountList.h"
#include "Core/Placement/PlacementCountList/PlacementCountList.h"
#include "Core/Placement/PlacementCountList/RowPlacementCountList.h"
#include "Solver/Assumption/Snapshot/ISnapshot.h"

class PlacementCountSnapshot : public ISnapshot {
  public:
    Board board;
    RowPlacementCountList rowPlacementCountList;
    ColumnPlacementCountList columnPlacementCountList;

    PlacementCountSnapshot(
        Board board,
        RowPlacementCountList rowPlacementCountList,
        ColumnPlacementCountList columnPlacementCountList);

    void restore(NonogramBoard& nonogramBoard) const override;
};

#endif