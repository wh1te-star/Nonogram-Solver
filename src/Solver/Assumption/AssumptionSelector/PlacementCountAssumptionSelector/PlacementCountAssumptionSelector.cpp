#include "Solver/Assumption/AssumptionSelector/PlacementCountAssumptionSelector/PlacementCountAssumptionSelector.h"

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"
#include "Solver/PlacementPatternCounter/IPlacementPatternCounter.h"
#include "Solver/ResultEnum/PlacementPatternCounterResult.h"
#include <cassert>

PlacementCountAssumptionSelector::PlacementCountAssumptionSelector(
  IPlacementPatternCounter &placementPatternCounter, const Board &board)
    : placementPatternCounter(placementPatternCounter) {
    rowPlacementCounts = RowPlacementCountList(
      std::vector<PlacementCount>(board.getRowLength().getLength(), PlacementCount(0)));
    columnPlacementCounts = ColumnPlacementCountList(
      std::vector<PlacementCount>(board.getColumnLength().getLength(), PlacementCount(0)));
}

std::vector<std::unique_ptr<IAssumption>> PlacementCountAssumptionSelector::select(
  const NonogramBoard &board, const AssumptionSelectionContext &context) {
    std::vector<std::unique_ptr<IAssumption>> assumptions;
    return assumptions;
}