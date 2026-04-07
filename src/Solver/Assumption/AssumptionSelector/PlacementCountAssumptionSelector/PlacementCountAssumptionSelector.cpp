#include "Solver/Assumption/AssumptionSelector/PlacementCountAssumptionSelector/PlacementCountAssumptionSelector.h"

#include "Core/Board/Line/Line.h"
#include "Core/Hint/HintList/HintList.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"
#include "Solver/PlacementPatternCounter/IPlacementPatternCounter.h"
#include "Solver/ResultEnum/PlacementPatternCounterResult.h"

#include <cassert>

using namespace VersaNo::Core;
namespace VersaNo::Solver {

PlacementCountAssumptionSelector::PlacementCountAssumptionSelector(
  IPlacementPatternCounter &placementPatternCounter, const NonogramBoard &nonogramBoard)
    : placementPatternCounter(placementPatternCounter)
    , rowPlacementCounts(
        std::vector<PlacementCount>(nonogramBoard.getRowLength().getLength(), PlacementCount(0)))
    , columnPlacementCounts(
        std::vector<PlacementCount>(
          nonogramBoard.getColumnLength().getLength(), PlacementCount(0))) {}

std::unique_ptr<IAssumptionPosition> PlacementCountAssumptionSelector::select(
  const Core::NonogramBoard &board, const AssumptionSelectionContext &context) {

    // Todo: Implement this method to select the line with the fewest placements.
    LinePosition linePosition(Orientation::Row, RowIndex(0));
    return std::make_unique<LineAssumptionPosition>(linePosition);
}

} // namespace VersaNo::Solver