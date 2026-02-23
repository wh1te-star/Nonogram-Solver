#ifndef PLACEMENTCOUNTSNAPSHOT_H
#define PLACEMENTCOUNTSNAPSHOT_H

#include "Board/Board/Board.h"
#include "Placement/PlacementCountList/ColumnPlacementCountList.h"
#include "Placement/PlacementCountList/PlacementCountList.h"
#include "Placement/PlacementCountList/RowPlacementCountList.h"
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
};

#endif