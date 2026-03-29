#include "Solver/Assumption/AssumptionSelector/PlacementCountAssumptionSelector/PlacementCountAssumptionSelector.h"

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"
#include "Solver/PlacementPatternCounter/IPlacementPatternCounter.h"
#include "Solver/ResultEnum/PlacementPatternCounterResult.h"
#include <cassert>

PlacementCountAssumptionSelector::PlacementCountAssumptionSelector(
  IPlacementPatternCounter &placementPatternCounter, const Board &board)
    : placementPatternCounter(placementPatternCounter)
    , rowPlacementCounts(
        std::vector<PlacementCount>(board.getRowLength().getLength(), PlacementCount(0)))
    , columnPlacementCounts(
        std::vector<PlacementCount>(board.getColumnLength().getLength(), PlacementCount(0))) {}

std::unique_ptr<IAssumptionPosition> PlacementCountAssumptionSelector::select(
  const NonogramBoard &board, const AssumptionSelectionContext &context) {

    // Todo: Implement this method to select the line with the fewest placements.
    return std::make_unique<LineAssumptionPosition>(Orientation::Row, RowIndex(0));
}