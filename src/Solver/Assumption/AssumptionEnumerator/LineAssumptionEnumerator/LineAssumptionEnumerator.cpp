#include "Solver/Assumption/AssumptionEnumerator/LineAssumptionEnumerator/LineAssumptionEnumerator.h"

#include "Core/Board/Board/Board.h"
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
    const auto *lineAssumptionPosition = dynamic_cast<const LineAssumptionPosition *>(
      &assumptionPosition);
    if (!lineAssumptionPosition) {
        assert(false && "Invalid assumption position type for LineAssumptionEnumerator");
        return {};
    }
    LinePosition linePosition = lineAssumptionPosition->getLinePosition();
    CellIndex cellIndex = linePosition.getCellIndex();
    Orientation orientation = linePosition.getOrientation();

    if (orientation == Orientation::Row) {
        LinePosition linePosition = lineAssumptionPosition->getLinePosition();
        RowIndex rowIndex = cellIndex.toRowIndex();
        Line line = nonogramBoard.getRowLine(rowIndex);
        HintList hintList = nonogramBoard.getRowHintGroup()[rowIndex];

        std::vector<Placement> solutions;
        ExhaustivePlacementPatternFinderResult result = exhaustivePlacementPatternFinder.find(
          hintList, line, solutions);

        std::vector<std::unique_ptr<IAssumption>> assumptions;
        assumptions.reserve(solutions.size());
        for (int i = 0; i < solutions.size(); i++) {
            assumptions.push_back(
              std::make_unique<LineAssumption>(linePosition, Line(solutions[i].getPlacement())));
        }
        return assumptions;
    } else {
        ColumnIndex columnIndex = cellIndex.toColumnIndex();
        Line line = nonogramBoard.getColumnLine(columnIndex);
        HintList hintList = nonogramBoard.getColumnHintGroup()[columnIndex];

        std::vector<Placement> solutions;
        ExhaustivePlacementPatternFinderResult result = exhaustivePlacementPatternFinder.find(
          hintList, line, solutions);

        std::vector<std::unique_ptr<IAssumption>> assumptions;
        assumptions.reserve(solutions.size());
        for (int i = 0; i < solutions.size(); i++) {
            assumptions.push_back(
              std::make_unique<LineAssumption>(linePosition, Line(solutions[i].getPlacement())));
        }
        return assumptions;
    }

    assert(false && "Failed to enumerate line assumptions");
    return {};
}

template class LineAssumptionEnumerator<Core::RowOrientation>;
template class LineAssumptionEnumerator<Core::ColumnOrientation>;

} // namespace VersaNo::Solver