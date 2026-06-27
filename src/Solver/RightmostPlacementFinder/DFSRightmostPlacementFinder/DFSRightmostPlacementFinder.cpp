#include "Solver/RightmostPlacementFinder/DFSRightmostPlacementFinder/DFSRightmostPlacementFinder.h"

#include <iostream>

using namespace VersaNo::Core;
namespace VersaNo::Solver {

template <typename TOrientation>
PlacementFinderResult DFSRightmostPlacementFinder<TOrientation>::find(
  const Core::HintList &hintList,
  typename Core::LineTraits<TOrientation>::Line &line,
  typename Core::LineTraits<TOrientation>::Placement &resultPlacement,
  Core::IBoardUpdateHandler &boardUpdateHandler) {
    using Traits = typename Core::LineTraits<TOrientation>;

    profiler.startMeasurement();

    return dfsRightmostPlacementFind(hintList, line, resultPlacement, boardUpdateHandler);
}

template <typename TOrientation>
PlacementFinderResult DFSRightmostPlacementFinder<TOrientation>::dfsRightmostPlacementFind(
  const Core::HintList &hintList,
  const typename Core::LineTraits<TOrientation>::Line &line,
  typename Core::LineTraits<TOrientation>::Placement &resultPlacement,
  Core::IBoardUpdateHandler &boardUpdateHandler) {
    using Traits = typename Core::LineTraits<TOrientation>;
    using Placement = typename Traits::Placement;

    Placement initialPlacement = Placement(std::vector<Cell>());

    int indexValue = hintList.size() == 0 ? -1 : static_cast<int>(hintList.size() - 1);
    HintIndex initialHintIndex = HintIndex(indexValue);

    return dfsRightmostPlacementFindRecursive(
      hintList, line, initialPlacement, initialHintIndex, resultPlacement, boardUpdateHandler);
}

template <typename TOrientation>
PlacementFinderResult DFSRightmostPlacementFinder<TOrientation>::dfsRightmostPlacementFindRecursive(
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
    if (currentHintIndex < HintIndex(0)) {
        Placement foundPlacement = currentPlacement;
        if (currentPlacement.size() < line.size()) {
            for (PeerIndex index :
                 PeerIndex::closedRangeDown((int)line.size() - (int)currentPlacement.size() - 1, 0)) {
                if (!line[index].canColor(White)) {
                    return PlacementFinderResult::notFound;
                }

                const Placement WhiteSpace = Placement(
                  std::vector<Cell>(1, Cell(CellColor::White)));
                foundPlacement = WhiteSpace + foundPlacement;
            }
        }
        resultPlacement = foundPlacement;
        return PlacementFinderResult::success;
    }

    // Try to place the current hint block at the rightmost possible position
    HintNumber hintNumber = hintList[currentHintIndex];
    PeerIndex currentBlockIndex = PeerIndex(
      (int)line.size() - (int)currentPlacement.size() - hintNumber.value);
    if (line.canPlaceBlock(currentBlockIndex, hintNumber)) {
        Placement previousPlacement = currentPlacement;

        Placement blockPlacement = Placement(
          std::vector<Cell>(hintNumber.value, Cell(CellColor::Black)));
        currentPlacement = blockPlacement + currentPlacement;
        if (currentPlacement.size() < line.size()) {

            const Placement WhiteSpace = Placement(std::vector<Cell>(1, Cell(CellColor::White)));
            currentPlacement = WhiteSpace + currentPlacement;
        }
        PlacementFinderResult result = dfsRightmostPlacementFindRecursive(
          hintList, line, currentPlacement, currentHintIndex - 1, resultPlacement,
          boardUpdateHandler);
        if (result == PlacementFinderResult::success) {
            return PlacementFinderResult::success;
        }

        currentPlacement = previousPlacement;
    }

    // Try to place a white space at the rightmost possible position
    PeerIndex currentAdjacentIndex = PeerIndex((int)line.size() - (int)currentPlacement.size() - 1);
    if (currentAdjacentIndex >= PeerIndex(0) && line[currentAdjacentIndex].canColor(White)) {
        Placement previousPlacement = currentPlacement;

        const Placement WhiteSpace = Placement(std::vector<Cell>(1, Cell(CellColor::White)));
        currentPlacement = WhiteSpace + currentPlacement;
        PlacementFinderResult result = dfsRightmostPlacementFindRecursive(
          hintList, line, currentPlacement, currentHintIndex, resultPlacement, boardUpdateHandler);
        if (result == PlacementFinderResult::success) {
            return PlacementFinderResult::success;
        }
        currentPlacement = previousPlacement;
    }

    return PlacementFinderResult::notFound;
}

template class DFSRightmostPlacementFinder<Core::RowOrientation>;
template class DFSRightmostPlacementFinder<Core::ColumnOrientation>;

} // namespace VersaNo::Solver