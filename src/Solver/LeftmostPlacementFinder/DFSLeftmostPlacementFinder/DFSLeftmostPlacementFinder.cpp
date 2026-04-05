#include "Solver/LeftmostPlacementFinder/DFSLeftmostPlacementFinder/DFSLeftmostPlacementFinder.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

PlacementFinderResult DFSLeftmostPlacementFinder::find(
  const HintSet &hintSet,
  Line &line,
  Placement &resultPlacement,
  IBoardUpdateHandler &boardUpdateHandler) {
    profiler.startMeasurement();

    dfsLeftmostPlacementFind(hintSet, line, resultPlacement, boardUpdateHandler);
    if (resultPlacement.size() > 0) {
        resultPlacement = resultPlacement;
        return PlacementFinderResult::success;
    }
    return PlacementFinderResult::notFound;
}
PlacementFinderResult DFSLeftmostPlacementFinder::dfsLeftmostPlacementFind(
  const HintSet &hintSet,
  Line &line,
  Placement &resultPlacement,
  IBoardUpdateHandler &boardUpdateHandler) {
    Placement currentPlacement = Placement("");

    return dfsLeftmostPlacementFindRecursive(
      hintSet, line, currentPlacement, 0, resultPlacement, boardUpdateHandler);
}

PlacementFinderResult DFSLeftmostPlacementFinder::dfsLeftmostPlacementFindRecursive(
  const HintSet &hintSet,
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
    if (currentHintIndex >= hintSet.size()) {
        Placement foundPlacement = currentPlacement;
        if (currentPlacement.size() < line.size()) {
            for (CellIndex cellIndex : CellIndex::range(currentPlacement.size(), line.size() - 1)) {
                if (!line[cellIndex].canColor(White)) {
                    return PlacementFinderResult::notFound;
                }
                foundPlacement = foundPlacement + Placement("W");
            }
        }
        resultPlacement = foundPlacement;
        return PlacementFinderResult::success;
    }

    HintNumber hintNumber = hintSet[currentHintIndex];
    CellIndex currentIndex = CellIndex(currentPlacement.size());
    if (line.canPlaceBlock(currentIndex, hintNumber)) {
        Placement previousPlacement = currentPlacement;
        currentPlacement = currentPlacement + Placement(hintNumber);
        if (currentPlacement.size() < line.size()) {
            currentPlacement = currentPlacement + Placement("W");
        }
        PlacementFinderResult result = dfsLeftmostPlacementFindRecursive(
          hintSet, line, currentPlacement, currentHintIndex + 1, resultPlacement,
          boardUpdateHandler);
        if (result == PlacementFinderResult::success) {
            return PlacementFinderResult::success;
        }
        currentPlacement = previousPlacement;
    }

    if (currentIndex < line.size() && line[currentIndex].canColor(White)) {
        Placement previousPlacement = currentPlacement;
        currentPlacement = currentPlacement + Placement("W");
        PlacementFinderResult result = dfsLeftmostPlacementFindRecursive(
          hintSet, line, currentPlacement, currentHintIndex, resultPlacement, boardUpdateHandler);
        if (result == PlacementFinderResult::success) {
            return PlacementFinderResult::success;
        }
        currentPlacement = previousPlacement;
    }

    return PlacementFinderResult::notFound;
}

} // namespace VersaNo::Solver