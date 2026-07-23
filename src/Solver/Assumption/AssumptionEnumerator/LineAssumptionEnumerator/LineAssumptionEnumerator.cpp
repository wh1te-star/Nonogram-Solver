#include "Solver/Assumption/AssumptionEnumerator/LineAssumptionEnumerator/LineAssumptionEnumerator.h"

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/Assumption/Assumption/CellAssumption/CellAssumption.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"

#include <cassert>

using namespace VersaNo::Core;
namespace VersaNo::Solver {

template <typename TOrientation>
LineAssumptionEnumerator<TOrientation>::LineAssumptionEnumerator(
  IExhaustivePlacementPatternFinder<TOrientation> &exhaustivePlacementPatternFinder)
    : exhaustivePlacementPatternFinder(exhaustivePlacementPatternFinder) {}

template <typename TOrientation>
std::vector<std::unique_ptr<IAssumption>> LineAssumptionEnumerator<TOrientation>::enumerate(
  const NonogramBoard &nonogramBoard, IAssumptionPosition &assumptionPosition) {
    using Traits = LineTraits<TOrientation>;
    using Index = typename Traits::Index;
    using Line = typename Traits::Line;
    using Placement = typename Traits::Placement;

    const auto *lineAssumptionPosition = dynamic_cast<const LineAssumptionPosition<TOrientation> *>(
      &assumptionPosition);
    if (!lineAssumptionPosition) {
        assert(false && "Invalid assumption position type for LineAssumptionEnumerator");
        return {};
    }
    LinePosition<TOrientation> linePosition = lineAssumptionPosition->getLinePosition();
    Index index = linePosition.getIndex();

    Line line = nonogramBoard.getLine<TOrientation>(index);
    HintList hintList = nonogramBoard.getHintGroup<TOrientation>()[index];

    std::vector<Placement> solutions;
    ExhaustivePlacementPatternFinderResult result = exhaustivePlacementPatternFinder.find(
      hintList, line, solutions);

    std::vector<std::unique_ptr<IAssumption>> assumptions;
    assumptions.reserve(solutions.size());
    for (int i = 0; i < solutions.size(); i++) {
        Line line = Line(solutions[i].list());
        assumptions.push_back(std::make_unique<LineAssumption<TOrientation>>(linePosition, line));
    }
    return assumptions;

    assert(false && "Failed to enumerate line assumptions");
    return {};
}

template class LineAssumptionEnumerator<Core::RowOrientation>;
template class LineAssumptionEnumerator<Core::ColumnOrientation>;

} // namespace VersaNo::Solver