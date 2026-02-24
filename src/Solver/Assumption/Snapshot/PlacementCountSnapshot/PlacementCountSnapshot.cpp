#include "Solver/Assumption/Snapshot/PlacementCountSnapshot/PlacementCountSnapshot.h"

PlacementCountSnapshot::PlacementCountSnapshot(
    Board board,
    RowPlacementCountList rowPlacementCountList,
    ColumnPlacementCountList columnPlacementCountList)
    : board(std::move(board))
    , rowPlacementCountList(std::move(rowPlacementCountList))
    , columnPlacementCountList(std::move(columnPlacementCountList)) {}

void PlacementCountSnapshot::restore(Board& board) const {
    board.applyBoard(this->board, true);
}