#include "Solver/Assumption/AssumptionSelector/PlacementCountAssumptionSelector/PlacementCountAssumptionSelector.h"

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"
#include "Solver/PlacementPatternCounter/IPlacementPatternCounter.h"
#include "Solver/ResultEnum/PlacementPatternCounterResult.h"

#include <cassert>

using namespace VersaNo::Core;
namespace VersaNo::Solver {

  template <typename TOrientation>
PlacementCountAssumptionSelector<TOrientation>::PlacementCountAssumptionSelector(
  IPlacementPatternCounter<TOrientation> &placementPatternCounter, const NonogramBoard &nonogramBoard)
    : placementPatternCounter(placementPatternCounter)
    , rowPlacementCounts(
        std::vector<PlacementCount>(nonogramBoard.getRowLength().getLength(), PlacementCount(0)))
    , columnPlacementCounts(
        std::vector<PlacementCount>(
          nonogramBoard.getColumnLength().getLength(), PlacementCount(0))) {}

  template <typename TOrientation>
std::unique_ptr<IAssumptionPosition> PlacementCountAssumptionSelector<TOrientation>::select(
  const Core::NonogramBoard &board, const AssumptionSelectionContext &context) {

    // Todo: Implement this method to select the line with the fewest placements.
    // LinePosition linePosition(Orientation::Row, RowIndex(0));
    // return std::make_unique<LineAssumptionPosition>(linePosition);
}

template class PlacementCountAssumptionSelector<Core::RowOrientation>;
template class PlacementCountAssumptionSelector<Core::ColumnOrientation>;

} // namespace VersaNo::Solver