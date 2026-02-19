#include "Solver/Assumption/Snapshot/PlacementCountSnapshot/PlacementCountSnapshot.h"

FullSnapshot::FullSnapshot(Board b, RowPlacementCountList r, ColumnPlacementCountList c)
    : board(std::move(b)), rowCounts(std::move(r)), colCounts(std::move(c)) {}