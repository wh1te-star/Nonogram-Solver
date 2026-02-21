#include "Solver/Assumption/Snapshot/PlacementCountSnapshot/PlacementCountSnapshot.h"

FullSnapshot::FullSnapshot(
    Board board,
    RowPlacementCountList rowPlacementCountList,
    ColumnPlacementCountList columnPlacementCountList)
    : board(std::move(board))
    , rowPlacementCountList(std::move(rowPlacementCountList))
    , columnPlacementCountList(std::move(columnPlacementCountList)) {}