#include "Solver/RightmostPlacementFinder/DFSRightmostPlacementFinder/DFSRightmostPlacementFinder.h"

#include <iostream>

Placement DFSRightmostPlacementFinder::find(const HintSet &hintSet,
                                            Line &line) {
  return dfsRightmostPlacementFind(hintSet, line);
}

Placement
DFSRightmostPlacementFinder::dfsRightmostPlacementFind(const HintSet &hintSet,
                                                       const Line &line) {
  Placement currentPlacement = Placement("");
  return dfsRightmostPlacementFindRecursive(hintSet, line, currentPlacement,
                                            hintSet.size() - 1);
}

Placement DFSRightmostPlacementFinder::dfsRightmostPlacementFindRecursive(
    const HintSet &hintSet, const Line &line, Placement &currentPlacement,
    int currentHintIndex) {
  if (currentPlacement.size() > line.size()) {
    return Placement("");
  }
  if (currentHintIndex < 0) {
    Placement foundPlacement = currentPlacement;
    if (currentPlacement.size() < line.size()) {
      for (CellIndex cellIndex :
           CellIndex::range(line.size() - currentPlacement.size() - 1, 0)) {
        if (!line[cellIndex].canColor(White)) {
          return Placement("");
        }
        foundPlacement = Placement("W") + foundPlacement;
      }
    }
    return foundPlacement;
  }

  HintNumber hintNumber = hintSet[currentHintIndex];
  CellIndex currentBlockIndex =
      CellIndex(line.size() - currentPlacement.size() - hintNumber.getNumber());
  if (line.canPlaceBlock(currentBlockIndex, hintNumber)) {
    Placement previousPlacement = currentPlacement;
    currentPlacement = Placement(hintNumber) + currentPlacement;
    if (currentPlacement.size() < line.size()) {
      currentPlacement = Placement("W") + currentPlacement;
    }
    Placement foundPlacement = dfsRightmostPlacementFindRecursive(
        hintSet, line, currentPlacement, currentHintIndex - 1);
    if (foundPlacement.size() != 0) {
      return foundPlacement;
    }
    currentPlacement = previousPlacement;
  }

  CellIndex currentAdjacentIndex =
      CellIndex(line.size() - currentPlacement.size() - 1);
  if (currentAdjacentIndex >= 0 && line[currentAdjacentIndex].canColor(White)) {
    Placement previousPlacement = currentPlacement;
    currentPlacement = Placement("W") + currentPlacement;
    Placement foundPlacement = dfsRightmostPlacementFindRecursive(
        hintSet, line, currentPlacement, currentHintIndex);
    if (foundPlacement.size() != 0) {
      return foundPlacement;
    }
    currentPlacement = previousPlacement;
  }

  return Placement("");
}