#include "Solver/Assumption/Snapshot/PlacementCountSnapshot/PlacementCountSnapshot.h"

using namespace VersaN::Core;
namespace VersaN::Solver {

PlacementCountSnapshot::PlacementCountSnapshot(
    Board board,
    RowPlacementCountList rowPlacementCountList,
    ColumnPlacementCountList columnPlacementCountList)
    : board(std::move(board))
    , rowPlacementCountList(std::move(rowPlacementCountList))
    , columnPlacementCountList(std::move(columnPlacementCountList)) {}

void PlacementCountSnapshot::restore(NonogramBoard& nonogramBoard) const {
    nonogramBoard.applyBoard(board, true);
}

} // namespace VersaN::Solver