#include "Solver/Assumption/AssumptionSelector/LineIndexAssumptionSelector/LineIndexAssumptionSelector.h"

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include "Solver/ResultEnum/ExhaustivePlacementPatternFinderResult.h"
#include <cassert>

LineIndexAssumptionSelector::LineIndexAssumptionSelector(Orientation orientation)
    : orientation(orientation) {}

std::vector<std::unique_ptr<IAssumption>> LineIndexAssumptionSelector::select(
  const NonogramBoard &board, const AssumptionSelectionContext &context) {
    std::vector<std::unique_ptr<IAssumption>> assumptions;

    int currentIndex = context.depth;

    int lineCount = (orientation == Orientation::Row) ? board.getRowLength().getLength()
                                                      : board.getColumnLength().getLength();
    if (currentIndex >= lineCount) {
        assert(false);
    }

    if (orientation == Orientation::Row) {
        const RowIndex rowIndex(currentIndex);
        const Line &line = board.getRowLine(rowIndex);
        const HintSet &hintSet = board.getRowHintSetList()[rowIndex];

        std::vector<Placement> solutions;
        ExhaustivePlacementPatternFinderResult result = exhaustivePlacementPatternFinder.find(
          hintSet, line, solutions);

        for (const Placement &placement : solutions) {
            Line assumptionLine = Line(placement.getPlacement());
            assumptions.push_back(std::make_unique<LineAssumption>(rowIndex, assumptionLine));
        }
    } else {
        const ColumnIndex colIndex(currentIndex);
        const Line &line = board.getColumnLine(colIndex);
        const HintSet &hintSet = board.getColumnHintSetList()[colIndex];

        std::vector<Placement> solutions;
        ExhaustivePlacementPatternFinderResult result = exhaustivePlacementPatternFinder.find(
          hintSet, line, solutions);

        for (const Placement &placement : solutions) {
            Line assumptionLine = Line(placement.getPlacement());
            assumptions.push_back(std::make_unique<LineAssumption>(colIndex, assumptionLine));
        }
    }

    currentIndex++;
    return assumptions;
}