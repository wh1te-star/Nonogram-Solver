#ifndef PLACEMENTCOUNTSNAPSHOT_H
#define PLACEMENTCOUNTSNAPSHOT_H

#include "Solver/Assumption/Snapshot/ISnapshot.h"
#include "Board/Board/Board.h"
#include "Placement/PlacementCountList/PlacementCountList.h"
#include "Placement/PlacementCountList/RowPlacementCountList.h"
#include "Placement/PlacementCountList/ColumnPlacementCountList.h"

class FullSnapshot : public ISnapshot {
public:
    Board board;
    RowPlacementCountList rowCounts;
    ColumnPlacementCountList colCounts;

    FullSnapshot(Board b, RowPlacementCountList r, ColumnPlacementCountList c);
};

#endif