#include "Solver/RightmostPlacementFinder/DFSRightmostPlacementFinder/DFSRightmostPlacementFinder.h"

#include <iostream>

using namespace VersaNo::Core;
namespace VersaNo::Solver {

PlacementFinderResult DFSRightmostPlacementFinder::find(
  const HintList &hintList,
  Line &line,
  Placement &resultPlacement,
  IBoardUpdateHandler &boardUpdateHandler) {
    profiler.startMeasurement();

    PlacementFinderResult result = dfsRightmostPlacementFind(
      hintList, line, resultPlacement, boardUpdateHandler);
    return result;
}

PlacementFinderResult DFSRightmostPlacementFinder::dfsRightmostPlacementFind(
  const HintList &hintList,
  const Line &line,
  Placement &resultPlacement,
  IBoardUpdateHandler &boardUpdateHandler) {
    Placement currentPlacement = Placement("");
    return dfsRightmostPlacementFindRecursive(
      hintList, line, currentPlacement, hintList.size() - 1, resultPlacement, boardUpdateHandler);
}

PlacementFinderResult DFSRightmostPlacementFinder::dfsRightmostPlacementFindRecursive(
  const HintList &hintList,
  const Line &line,
  Placement &currentPlacement,
  int currentHintIndex,
  Placement &resultPlacement,
  IBoardUpdateHandler &boardUpdateHandler) {
    if (profiler.isTimeLimitExceeded() || profiler.isStackUsageLimitExceeded()) {
        return PlacementFinderResult::notFound;
    }

    if (currentPlacement.size() > line.size()) {
        return PlacementFinderResult::notFound;
    }
    if (currentHintIndex < 0) {
        Placement foundPlacement = currentPlacement;
        if (currentPlacement.size() < line.size()) {
            for (CellIndex cellIndex :
                 CellIndex::range(line.size() - currentPlacement.size() - 1, 0)) {
                if (!line[cellIndex].canColor(White)) {
                    return PlacementFinderResult::notFound;
                }
                foundPlacement = Placement("W") + foundPlacement;
            }
        }
        resultPlacement = foundPlacement;
        return PlacementFinderResult::success;
    }

    HintNumber hintNumber = hintList[currentHintIndex];
    CellIndex currentBlockIndex = CellIndex(
      line.size() - currentPlacement.size() - hintNumber.getNumber());
    if (line.canPlaceBlock(currentBlockIndex, hintNumber)) {
        Placement previousPlacement = currentPlacement;
        currentPlacement = Placement(hintNumber) + currentPlacement;
        if (currentPlacement.size() < line.size()) {
            currentPlacement = Placement("W") + currentPlacement;
        }
        PlacementFinderResult result = dfsRightmostPlacementFindRecursive(
          hintList, line, currentPlacement, currentHintIndex - 1, resultPlacement,
          boardUpdateHandler);
        if (result == PlacementFinderResult::success) {
            return PlacementFinderResult::success;
        }
        currentPlacement = previousPlacement;
    }

    CellIndex currentAdjacentIndex = CellIndex(line.size() - currentPlacement.size() - 1);
    if (currentAdjacentIndex >= 0 && line[currentAdjacentIndex].canColor(White)) {
        Placement previousPlacement = currentPlacement;
        currentPlacement = Placement("W") + currentPlacement;
        PlacementFinderResult result = dfsRightmostPlacementFindRecursive(
          hintList, line, currentPlacement, currentHintIndex, resultPlacement, boardUpdateHandler);
        if (result == PlacementFinderResult::success) {
            return PlacementFinderResult::success;
        }
        currentPlacement = previousPlacement;
    }

    return PlacementFinderResult::notFound;
}

} // namespace VersaNo::Solver