#include "Solver/Assumption/AssumptionSelector/LineIndexAssumptionSelector/LineIndexAssumptionSelector.h"

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include "Solver/ResultEnum/ExhaustivePlacementPatternFinderResult.h"
#include <cassert>

LineIndexAssumptionSelector::LineIndexAssumptionSelector(Orientation orientation)
    : orientation(orientation) {}

IAssumptionPosition LineIndexAssumptionSelector::select(
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
        return LineAssumptionPosition(orientation, rowIndex);
    } else {
        const ColumnIndex colIndex(currentIndex);
        return LineAssumptionPosition(orientation, colIndex);
    }
}