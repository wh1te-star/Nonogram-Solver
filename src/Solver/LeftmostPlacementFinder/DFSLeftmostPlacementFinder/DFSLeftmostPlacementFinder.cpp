#include "Solver/LeftmostPlacementFinder/DFSLeftmostPlacementFinder/DFSLeftmostPlacementFinder.h"

bool DFSLeftmostPlacementFinder::find(
    const HintSet &hintSet,
    Line &line) {
  return dfsLeftmostPlacementFind(hintSet, line);
}
bool DFSLeftmostPlacementFinder::dfsLeftmostPlacementFind(
    const HintSet &hintSet,
    Line &line) {
  Placement currentPlacement = Placement("");
  return getLeftMostPlacementRecursive(line, hintSet, currentPlacement, 0);
}

bool DFSLeftmostPlacementFinder::dfsLeftmostPlacementFindRecursive(
    const HintSet &hintSet, Line &line, Placement &currentPlacement,
    int currentHintIndex) {
  if (currentPlacement.size() > line.size()) {
    return false;
  }
  if (currentHintIndex >= hintSet.size()) {
    Placement foundPlacement = currentPlacement;
    if (currentPlacement.size() < line.size()) {
      for (CellIndex cellIndex :
           CellIndex::range(currentPlacement.size(), line.size() - 1)) {
        if (!line[cellIndex].canColor(White)) {
          return Placement("");
        }
        foundPlacement = foundPlacement + Placement("W");
      }
    }
    return foundPlacement;
  }

  HintNumber hintNumber = hintSet[currentHintIndex];
  CellIndex currentIndex = CellIndex(currentPlacement.size());
  if (line.canPlaceBlock(currentIndex, hintNumber)) {
    Placement previousPlacement = currentPlacement;
    currentPlacement = currentPlacement + Placement(hintNumber);
    if (currentPlacement.size() < line.size()) {
      currentPlacement = currentPlacement + Placement("W");
    }
    Placement foundPlacement = getLeftMostPlacementRecursive(
        line, hintSet, currentPlacement, currentHintIndex + 1);
    if (foundPlacement.size() != 0) {
      return foundPlacement;
    }
    currentPlacement = previousPlacement;
  }

  if (currentIndex < line.size() && line[currentIndex].canColor(White)) {
    Placement previousPlacement = currentPlacement;
    currentPlacement = currentPlacement + Placement("W");
    Placement foundPlacement = getLeftMostPlacementRecursive(
        line, hintSet, currentPlacement, currentHintIndex);
    if (foundPlacement.size() != 0) {
      return foundPlacement;
    }
    currentPlacement = previousPlacement;
  }

  return true;
}