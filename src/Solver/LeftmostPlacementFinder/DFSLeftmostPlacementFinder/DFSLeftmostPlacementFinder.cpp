#include "Solver/LeftmostPlacementFinder/DFSLeftmostPlacementFinder/DFSLeftmostPlacementFinder.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

template <typename TOrientation>
PlacementFinderResult DFSLeftmostPlacementFinder<TOrientation>::find(
  const HintList &hintList,
  Line<TOrientation> &line,
  Placement<TOrientation> &resultPlacement,
  IBoardUpdateHandler &boardUpdateHandler) {
    profiler.startMeasurement();

    dfsLeftmostPlacementFind(hintList, line, resultPlacement, boardUpdateHandler);
    if (resultPlacement.size() > 0) {
        resultPlacement = resultPlacement;
        return PlacementFinderResult::success;
    }
    return PlacementFinderResult::notFound;
}

template <typename TOrientation>
PlacementFinderResult DFSLeftmostPlacementFinder<TOrientation>::dfsLeftmostPlacementFind(
  const HintList &hintList,
  Line<TOrientation> &line,
  Placement<TOrientation> &resultPlacement,
  IBoardUpdateHandler &boardUpdateHandler) {
    Placement<TOrientation> currentPlacement = Placement<TOrientation>("");

    return dfsLeftmostPlacementFindRecursive(
      hintList, line, currentPlacement, 0, resultPlacement, boardUpdateHandler);
}

template <typename TOrientation>
PlacementFinderResult DFSLeftmostPlacementFinder<TOrientation>::dfsLeftmostPlacementFindRecursive(
  const HintList &hintList,
  const Line<TOrientation> &line,
  Placement<TOrientation> &currentPlacement,
  int currentHintIndex,
  Placement<TOrientation> &resultPlacement,
  IBoardUpdateHandler &boardUpdateHandler) {
    if (profiler.isTimeLimitExceeded() || profiler.isStackUsageLimitExceeded()) {
        return PlacementFinderResult::notFound;
    }

    if (currentPlacement.size() > line.size()) {
        return PlacementFinderResult::notFound;
    }
    if (currentHintIndex >= hintList.size()) {
        Placement<TOrientation> foundPlacement = currentPlacement;
        if (currentPlacement.size() < line.size()) {
            for (CellIndex cellIndex : CellIndex::range(currentPlacement.size(), line.size() - 1)) {
                if (!line[cellIndex].canColor(White)) {
                    return PlacementFinderResult::notFound;
                }
                foundPlacement = foundPlacement + Placement<TOrientation>("W");
            }
        }
        resultPlacement = foundPlacement;
        return PlacementFinderResult::success;
    }

    HintNumber hintNumber = hintList[currentHintIndex];
    CellIndex currentIndex = CellIndex(currentPlacement.size());
    if (line.canPlaceBlock(currentIndex, hintNumber)) {
        Placement<TOrientation> previousPlacement = currentPlacement;
        currentPlacement = currentPlacement + Placement<TOrientation>(hintNumber);
        if (currentPlacement.size() < line.size()) {
            currentPlacement = currentPlacement + Placement<TOrientation>("W");
        }
        PlacementFinderResult result = dfsLeftmostPlacementFindRecursive(
          hintList, line, currentPlacement, currentHintIndex + 1, resultPlacement,
          boardUpdateHandler);
        if (result == PlacementFinderResult::success) {
            return PlacementFinderResult::success;
        }
        currentPlacement = previousPlacement;
    }

    if (currentIndex < line.size() && line[currentIndex].canColor(White)) {
        Placement<TOrientation> previousPlacement = currentPlacement;
        currentPlacement = currentPlacement + Placement<TOrientation>("W");
        PlacementFinderResult result = dfsLeftmostPlacementFindRecursive(
          hintList, line, currentPlacement, currentHintIndex, resultPlacement, boardUpdateHandler);
        if (result == PlacementFinderResult::success) {
            return PlacementFinderResult::success;
        }
        currentPlacement = previousPlacement;
    }

    return PlacementFinderResult::notFound;
}

template class DFSLeftmostPlacementFinder<Core::RowOrientation>;
template class DFSLeftmostPlacementFinder<Core::ColumnOrientation>;

} // namespace VersaNo::Solver