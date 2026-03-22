#include "Solver/Assumption/Assumption/AssumptionEnumerator/AssumptionEnumerator.h"

AssumptionEnumerator::AssumptionEnumerator(IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder)
    : exhaustivePlacementPatternFinder(exhaustivePlacementPatternFinder) {}

std::vector<std::unique_ptr<IAssumption>>
AssumptionEnumerator::enumerate(const Board &board, IAssumption assumption) {
    std::vector<std::unique_ptr<IAssumption>> assumptions;

    if (const LineAssumption *lineAssumption = dynamic_cast<const LineAssumption *>(&assumption)) {
        const Line &line = lineAssumption->getLine();
        const HintSet &hintSet = (lineAssumption->getOrientation() == Orientation::Row)
                                    ? board.getRowHintSetList()[lineAssumption->getIndex()]
                                    : board.getColumnHintSetList()[lineAssumption->getIndex()];

        std::vector<Placement> solutions;
        ExhaustivePlacementPatternFinderResult result = exhaustivePlacementPatternFinder.find(
          hintSet, line, solutions);

        for (const Placement &placement : solutions) {
            Line assumptionLine = Line(placement.getPlacement());
            assumptions.push_back(std::make_unique<LineAssumption>(
              lineAssumption->getIndex(), assumptionLine, lineAssumption->getOrientation()));
        }
    }

    return assumptions;
}