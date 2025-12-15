#include "Solver/ExhaustivePlacementPatternFinder/DFSExhaustivePlacementPatternFinder/DFSExhaustivePlacementPatternFinder.h"

std::vector<Placement>
DFSExhaustivePlacementPatternFinder::find(const HintSet &hintSet,
                                          const Line &line) {
  std::vector<Placement> solutions;
  dfsExhaustivePlacementFind(hintSet, line, solutions);
  return solutions;
}

void DFSExhaustivePlacementPatternFinder::dfsExhaustivePlacementFind(
    const HintSet &hintSet, const Line &line,
    std::vector<Placement> &solutions) {
  Placement currentPlacement = Placement("");
  dfsExhaustivePlacementFindRecursive(hintSet, line, solutions,
                                      currentPlacement, 0);
}

void DFSExhaustivePlacementPatternFinder::dfsExhaustivePlacementFindRecursive(
    const HintSet &hintSet, const Line &line, std::vector<Placement> &solutions,
    Placement &currentPlacement, int currentHintIndex) {
  if (currentPlacement.size() > line.size()) {
    return;
  }
  if (currentHintIndex >= hintSet.size()) {
    Placement foundPlacement = currentPlacement;
    for (CellIndex i = CellIndex(currentPlacement.size()); i < line.size();
         i = i + 1) {
      if (!line[i].canColor(White)) {
        return;
      }
      foundPlacement = foundPlacement + Placement("W");
    }
    solutions.push_back(foundPlacement);
    return;
  }

  HintNumber hintNumber = hintSet[currentHintIndex];
  CellIndex currentIndex = CellIndex(currentPlacement.size());
  if (line.canPlaceBlock(currentIndex, hintNumber)) {
    Placement previousPlacement = currentPlacement;
    currentPlacement = currentPlacement + Placement(hintNumber);
    if (currentPlacement.size() < line.size()) {
      currentPlacement = currentPlacement + Placement("W");
    }
    dfsExhaustivePlacementFindRecursive(hintSet, line, solutions,
                                        currentPlacement, currentHintIndex + 1);
    currentPlacement = previousPlacement;
  }

  if (currentIndex < line.size() && line[currentIndex].canColor(White)) {
    Placement previousPlacement = currentPlacement;
    currentPlacement = currentPlacement + Placement("W");
    dfsExhaustivePlacementFindRecursive(hintSet, line, solutions,
                                        currentPlacement, currentHintIndex);
    currentPlacement = previousPlacement;
  }
}
