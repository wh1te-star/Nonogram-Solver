#include "Solver/LeftmostPlacementFinder/DFSLeftmostPlacementFinder/DFSLeftmostPlacementFinder.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

template <typename TOrientation>
PlacementFinderResult DFSLeftmostPlacementFinder<TOrientation>::find(
  const Core::HintList &hintList,
  typename Core::LineTraits<TOrientation>::Line &line,
  typename Core::LineTraits<TOrientation>::Placement &resultPlacement,
  Core::IBoardUpdateHandler &boardUpdateHandler) {
    using Traits = typename Core::LineTraits<TOrientation>;

    profiler.startMeasurement();

    return dfsLeftmostPlacementFind(hintList, line, resultPlacement, boardUpdateHandler);
}

template <typename TOrientation>
PlacementFinderResult DFSLeftmostPlacementFinder<TOrientation>::dfsLeftmostPlacementFind(
  const Core::HintList &hintList,
  typename Core::LineTraits<TOrientation>::Line &line,
  typename Core::LineTraits<TOrientation>::Placement &resultPlacement,
  Core::IBoardUpdateHandler &boardUpdateHandler) {
    using Traits = typename Core::LineTraits<TOrientation>;
    using Placement = typename Traits::Placement;

    Placement initialPlacement = Placement(std::vector<Cell>());
    HintIndex initialHintIndex = HintIndex(0);

    return dfsLeftmostPlacementFindRecursive(
      hintList, line, initialPlacement, initialHintIndex, resultPlacement, boardUpdateHandler);
}

template <typename TOrientation>
PlacementFinderResult DFSLeftmostPlacementFinder<TOrientation>::dfsLeftmostPlacementFindRecursive(
  const Core::HintList &hintList,
  const typename Core::LineTraits<TOrientation>::Line &line,
  typename Core::LineTraits<TOrientation>::Placement &currentPlacement,
  Core::HintIndex currentHintIndex,
  typename Core::LineTraits<TOrientation>::Placement &resultPlacement,
  Core::IBoardUpdateHandler &boardUpdateHandler) {
    using Traits = typename Core::LineTraits<TOrientation>;
    using Index = typename Traits::Index;
    using PeerIndex = typename Traits::PeerIndex;
    using Placement = typename Traits::Placement;


    if (profiler.isTimeLimitExceeded() || profiler.isStackUsageLimitExceeded()) {
        return PlacementFinderResult::notFound;
    }

    if (currentPlacement.size() > line.size()) {
        return PlacementFinderResult::notFound;
    }
    if (currentHintIndex.value >= hintList.size()) {
        Placement foundPlacement = currentPlacement;
        if (currentPlacement.size() < line.size()) {
            for (PeerIndex cellIndex :
                 PeerIndex::closedRangeUp((int)currentPlacement.size(), (int)line.size() - 1)) {
                if (!line[cellIndex].canColor(White)) {
                    return PlacementFinderResult::notFound;
                }

                const Placement WhiteSpace = Placement(
                  std::vector<Cell>(1, Cell(CellColor::White)));
                foundPlacement = foundPlacement + WhiteSpace;
            }
        }
        resultPlacement = foundPlacement;
        return PlacementFinderResult::success;
    }

    // Try to place the current hint block at the leftmost possible position
    HintNumber hintNumber = hintList[currentHintIndex];
    PeerIndex currentIndex = PeerIndex((int)currentPlacement.size());
    if (line.canPlaceBlock(currentIndex, hintNumber)) {
        Placement previousPlacement = currentPlacement;
        Placement blockPlacement = Placement(
          std::vector<Cell>(hintNumber.value, Cell(CellColor::Black)));
        currentPlacement = currentPlacement + blockPlacement;
        if (currentPlacement.size() < line.size()) {

            const Placement WhiteSpace = Placement(std::vector<Cell>(1, Cell(CellColor::White)));
            currentPlacement = currentPlacement + WhiteSpace;
        }
        PlacementFinderResult result = dfsLeftmostPlacementFindRecursive(
          hintList, line, currentPlacement, currentHintIndex + 1, resultPlacement,
          boardUpdateHandler);
        if (result == PlacementFinderResult::success) {
            return PlacementFinderResult::success;
        }
        currentPlacement = previousPlacement;
    }

    // Try to place a white space at the leftmost possible position
    if (currentIndex.value < line.size() && line[currentIndex].canColor(White)) {
        Placement previousPlacement = currentPlacement;

        const Placement WhiteSpace = Placement(std::vector<Cell>(1, Cell(CellColor::White)));
        currentPlacement = currentPlacement + WhiteSpace;
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