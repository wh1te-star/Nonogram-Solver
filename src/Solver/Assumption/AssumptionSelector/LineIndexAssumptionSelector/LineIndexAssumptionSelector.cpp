#include "Solver/Assumption/AssumptionSelector/LineIndexAssumptionSelector/LineIndexAssumptionSelector.h"

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include <cassert>

LineIndexAssumptionSelector::LineIndexAssumptionSelector(
    IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder,
    Orientation orientation, int currentIndex)
    : exhaustivePlacementPatternFinder(exhaustivePlacementPatternFinder),
      orientation(orientation), currentIndex(currentIndex) {}

std::vector<std::unique_ptr<IAssumption>>
LineIndexAssumptionSelector::select(const BacktrackBoard &board) {
  std::vector<std::unique_ptr<IAssumption>> assumptions;

  int lineCount = (orientation == Orientation::Row)
                      ? board.getRowLength().getLength()
                      : board.getColumnLength().getLength();
  if (currentIndex >= lineCount) {
    assert(false);
  }
  if (orientation == Orientation::Row) {
    const RowIndex rowIndex(currentIndex);
    const Line &line = board.getRowLine(rowIndex);
    const HintSet &hintSet = board.getRowHintSetList()[rowIndex];

    auto placements = exhaustivePlacementPatternFinder.find(hintSet, line);

    for (const Placement &placement : placements) {
      Line assumptionLine = Line(placement.getPlacement());
      assumptions.push_back(
          std::make_unique<LineAssumption>(rowIndex, assumptionLine));
    }
  } else {
    const ColumnIndex colIndex(currentIndex);
    const Line &line = board.getColumnLine(colIndex);
    const HintSet &hintSet = board.getColumnHintSetList()[colIndex];

    auto placements = exhaustivePlacementPatternFinder.find(hintSet, line);

    for (const Placement &placement : placements) {
      Line assumptionLine = Line(placement.getPlacement());
      assumptions.push_back(
          std::make_unique<LineAssumption>(colIndex, assumptionLine));
    }
  }

  currentIndex++;
  return assumptions;
}