#include "Solver/Assumption/AssumptionSelector/LineIndexAssumptionSelector/LineIndexAssumptionSelector.h"

#include "Core/Board/Line/Line.h"
#include "Core/Hint/HintSet/HintSet.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include "Solver/ResultEnum/ExhaustivePlacementPatternFinderResult.h"

#include <cassert>

using namespace VersaN::Core;
namespace VersaN::Solver {

LineIndexAssumptionSelector::LineIndexAssumptionSelector(Orientation orientation)
    : orientation(orientation) {}

std::unique_ptr<IAssumptionPosition> LineIndexAssumptionSelector::select(
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
        LinePosition linePosition(orientation, rowIndex);
        return std::make_unique<LineAssumptionPosition>(linePosition);
    } else {
        const ColumnIndex columnIndex(currentIndex);
        LinePosition linePosition(orientation, columnIndex);
        return std::make_unique<LineAssumptionPosition>(linePosition);
    }
}

} // namespace VersaN::Solver