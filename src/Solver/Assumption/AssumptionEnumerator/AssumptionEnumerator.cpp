#include "Solver/Assumption/AssumptionEnumerator/AssumptionEnumerator.h"

#include "Board/Board/Board.h"
#include "Placement/Placement/Placement.h"
#include "Solver/Assumption/Assumption/CellAssumption/CellAssumption.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"
#include <cassert>

AssumptionEnumerator::AssumptionEnumerator(
  IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder)
    : exhaustivePlacementPatternFinder(exhaustivePlacementPatternFinder) {}

std::vector<std::unique_ptr<IAssumption>> AssumptionEnumerator::enumerate(
  const NonogramBoard &nonogramBoard, IAssumptionPosition assumptionPosition) {
    const auto *cellAssumptionPosition = dynamic_cast<const CellAssumptionPosition *>(
      &assumptionPosition);

    const auto *lineAssumptionPosition = dynamic_cast<const LineAssumptionPosition *>(
      &assumptionPosition);

    const auto *hintAssumptionPosition = dynamic_cast<const HintAssumptionPosition *>(
      &assumptionPosition);

    if (cellAssumptionPosition) {
        return enumerateCellAssumption(nonogramBoard, *cellAssumptionPosition);
    }

    if (lineAssumptionPosition) {
        return enumerateLineAssumption(nonogramBoard, *lineAssumptionPosition);
    }

    if (hintAssumptionPosition) {
        return enumerateHintAssumption(nonogramBoard, *hintAssumptionPosition);
    }

    assert(false && "Unknown assumption position type");
    return {};
}

std::vector<std::unique_ptr<IAssumption>> AssumptionEnumerator::enumerateCellAssumption(
  const NonogramBoard &nonogramBoard, const CellAssumptionPosition &cellAssumptionPosition) {
    std::vector<std::unique_ptr<IAssumption>> assumptions;
    assumptions.reserve(2);

    CellPosition coordinate{cellAssumptionPosition.getRow(), cellAssumptionPosition.getColumn()};

    assumptions[0] = std::make_unique<CellAssumption>(coordinate, Cell(White));
    assumptions[1] = std::make_unique<CellAssumption>(coordinate, Cell(Black));

    return assumptions;
}

std::vector<std::unique_ptr<IAssumption>> AssumptionEnumerator::enumerateLineAssumption(
  const NonogramBoard &nonogramBoard, const LineAssumptionPosition &lineAssumptionPosition) {
    if (lineAssumptionPosition.getOrientation() == Orientation::Row) {
        RowIndex rowIndex = lineAssumptionPosition.getIndex().toRowIndex();
        Line line = nonogramBoard.getRowLine(rowIndex);
        HintSet hintSet = nonogramBoard.getRowHintSetList()[rowIndex];

        std::vector<Placement> solutions;
        ExhaustivePlacementPatternFinderResult result = exhaustivePlacementPatternFinder.find(
          hintSet, line, solutions);

        if (result == ExhaustivePlacementPatternFinderResult::success) {
            std::vector<std::unique_ptr<IAssumption>> assumptions;
            assumptions.reserve(solutions.size());
            for(int i = 0; i < solutions.size(); i++) {
                assumptions[i] = std::make_unique<LineAssumption>(Orientation::Row, rowIndex, solutions[i]);
            }
            return assumptions;
        }
    } else {
        ColumnIndex columnIndex = lineAssumptionPosition.getIndex().toColumnIndex();
        Line line = nonogramBoard.getColumnLine(columnIndex);
        HintSet hintSet = nonogramBoard.getColumnHintSetList()[columnIndex];

        std::vector<Placement> solutions;
        ExhaustivePlacementPatternFinderResult result = exhaustivePlacementPatternFinder.find(
          hintSet, line, solutions);

        if (result == ExhaustivePlacementPatternFinderResult::success) {
            std::vector<std::unique_ptr<IAssumption>> assumptions;
            assumptions.reserve(solutions.size());
            for(int i = 0; i < solutions.size(); i++) {
                assumptions[i] = std::make_unique<LineAssumption>(Orientation::Column, columnIndex, solutions[i]);
            }
            return assumptions;
        }
    }

    assert(false && "Failed to enumerate line assumptions");
    return {};
}

std::vector<std::unique_ptr<IAssumption>> AssumptionEnumerator::enumerateHintAssumption(
  const NonogramBoard &nonogramBoard, const HintAssumptionPosition &hintAssumptionPosition) {
    //Implement later
    return {};
}