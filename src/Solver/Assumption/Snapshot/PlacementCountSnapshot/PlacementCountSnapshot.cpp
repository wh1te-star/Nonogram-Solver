#include "Solver/Assumption/Snapshot/PlacementCountSnapshot/PlacementCountSnapshot.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

PlacementCountSnapshot::PlacementCountSnapshot(
  Board board,
  RowPlacementCountList rowPlacementCountList,
  ColumnPlacementCountList columnPlacementCountList)
    : board(std::move(board))
    , rowPlacementCountList(std::move(rowPlacementCountList))
    , columnPlacementCountList(std::move(columnPlacementCountList)) {}

void PlacementCountSnapshot::restore(NonogramBoard &nonogramBoard) const {
    nonogramBoard.applyBoard(board, true);
}

} // namespace VersaNo::Solver