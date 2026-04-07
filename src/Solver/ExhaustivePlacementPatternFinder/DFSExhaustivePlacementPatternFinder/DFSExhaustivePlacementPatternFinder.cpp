#include "Solver/ExhaustivePlacementPatternFinder/DFSExhaustivePlacementPatternFinder/DFSExhaustivePlacementPatternFinder.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

ExhaustivePlacementPatternFinderResult DFSExhaustivePlacementPatternFinder::find(
  const HintList &hintList, const Line &line, std::vector<Placement> &solutions) {
    return dfsExhaustivePlacementFind(hintList, line, solutions);
}

ExhaustivePlacementPatternFinderResult
DFSExhaustivePlacementPatternFinder::dfsExhaustivePlacementFind(
  const HintList &hintList, const Line &line, std::vector<Placement> &solutions) {
    Placement currentPlacement = Placement("");
    return dfsExhaustivePlacementFindRecursive(hintList, line, solutions, currentPlacement, 0);
}

ExhaustivePlacementPatternFinderResult
DFSExhaustivePlacementPatternFinder::dfsExhaustivePlacementFindRecursive(
  const HintList &hintList,
  const Line &line,
  std::vector<Placement> &solutions,
  Placement &currentPlacement,
  int currentHintIndex) {
    if (currentPlacement.size() > line.size()) {
        return ExhaustivePlacementPatternFinderResult::notFound;
    }
    if (currentHintIndex >= hintList.size()) {
        Placement foundPlacement = currentPlacement;
        for (CellIndex i = CellIndex(currentPlacement.size()); i < line.size(); i = i + 1) {
            if (!line[i].canColor(White)) {
                return ExhaustivePlacementPatternFinderResult::notFound;
            }
            foundPlacement = foundPlacement + Placement("W");
        }
        solutions.push_back(foundPlacement);
        return ExhaustivePlacementPatternFinderResult::success;
    }

    HintNumber hintNumber = hintList[currentHintIndex];
    CellIndex currentIndex = CellIndex(currentPlacement.size());
    if (line.canPlaceBlock(currentIndex, hintNumber)) {
        Placement previousPlacement = currentPlacement;
        currentPlacement = currentPlacement + Placement(hintNumber);
        if (currentPlacement.size() < line.size()) {
            currentPlacement = currentPlacement + Placement("W");
        }
        dfsExhaustivePlacementFindRecursive(
          hintList, line, solutions, currentPlacement, currentHintIndex + 1);
        currentPlacement = previousPlacement;
    }

    if (currentIndex < line.size() && line[currentIndex].canColor(White)) {
        Placement previousPlacement = currentPlacement;
        currentPlacement = currentPlacement + Placement("W");
        dfsExhaustivePlacementFindRecursive(
          hintList, line, solutions, currentPlacement, currentHintIndex);
        currentPlacement = previousPlacement;
    }

    return ExhaustivePlacementPatternFinderResult::success;
}

} // namespace VersaNo::Solver