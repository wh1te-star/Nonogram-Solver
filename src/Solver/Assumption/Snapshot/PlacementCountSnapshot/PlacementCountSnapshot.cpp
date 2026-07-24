#include "Solver/Assumption/Snapshot/PlacementCountSnapshot/PlacementCountSnapshot.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

PlacementCountSnapshot::PlacementCountSnapshot(
  const std::shared_ptr<Core::IBoard> board,
  RowPlacementCountList rowPlacementCountList,
  ColumnPlacementCountList columnPlacementCountList)
    : board(board)
    , rowPlacementCountList(std::move(rowPlacementCountList))
    , columnPlacementCountList(std::move(columnPlacementCountList)) {}

void PlacementCountSnapshot::restore(NonogramBoard &nonogramBoard) const {
    nonogramBoard.applyBoard(*board, true);
}

} // namespace VersaNo::Solver