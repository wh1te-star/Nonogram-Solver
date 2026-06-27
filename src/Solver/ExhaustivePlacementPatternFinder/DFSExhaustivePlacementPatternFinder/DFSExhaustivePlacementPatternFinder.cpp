#include "Solver/ExhaustivePlacementPatternFinder/DFSExhaustivePlacementPatternFinder/DFSExhaustivePlacementPatternFinder.h"

#include "Core/Types/AppliedType/AppliedType.h"

#include <vector>

using namespace VersaNo::Core;
namespace VersaNo::Solver {

template <typename TOrientation>
ExhaustivePlacementPatternFinderResult DFSExhaustivePlacementPatternFinder<TOrientation>::find(
  const Core::HintList &hintList,
  const typename Core::LineTraits<TOrientation>::Line &line,
  std::vector<typename Core::LineTraits<TOrientation>::Placement> &solutions) {
    return dfsExhaustivePlacementFind(hintList, line, solutions);
}

template <typename TOrientation>
ExhaustivePlacementPatternFinderResult
DFSExhaustivePlacementPatternFinder<TOrientation>::dfsExhaustivePlacementFind(
  const Core::HintList &hintList,
  const typename Core::LineTraits<TOrientation>::Line &line,
  std::vector<typename Core::LineTraits<TOrientation>::Placement> &solutions) {
    typename Core::LineTraits<TOrientation>::Placement currentPlacement =
      typename Core::LineTraits<TOrientation>::Placement(std::vector<Cell>());
    return dfsExhaustivePlacementFindRecursive(
      hintList, line, solutions, currentPlacement, Core::HintIndex(0));
}

template <typename TOrientation>
ExhaustivePlacementPatternFinderResult
DFSExhaustivePlacementPatternFinder<TOrientation>::dfsExhaustivePlacementFindRecursive(
  const Core::HintList &hintList,
  const typename Core::LineTraits<TOrientation>::Line &line,
  std::vector<typename Core::LineTraits<TOrientation>::Placement> &solutions,
  typename Core::LineTraits<TOrientation>::Placement &currentPlacement,
  Core::HintIndex currentHintIndex) {
    using Traits = typename Core::LineTraits<TOrientation>;
    using Index = typename Traits::Index;
    using PeerIndex = typename Traits::PeerIndex;
    using Placement = typename Traits::Placement;

    if (currentPlacement.size() > line.size()) {
        return ExhaustivePlacementPatternFinderResult::notFound;
    }
    if (currentHintIndex.value >= hintList.size()) {
        Placement foundPlacement = currentPlacement;
        for (PeerIndex index :
             PeerIndex::closedRangeUp((int)currentPlacement.size(), (int)line.size() - 1)) {
            if (!line[index].canColor(White)) {
                return ExhaustivePlacementPatternFinderResult::notFound;
            }

            const Placement WhiteSpace = Placement(std::vector<Cell>(1, Cell(CellColor::White)));
            foundPlacement = foundPlacement + WhiteSpace;
        }
        solutions.push_back(foundPlacement);
        return ExhaustivePlacementPatternFinderResult::success;
    }

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
        dfsExhaustivePlacementFindRecursive(
          hintList, line, solutions, currentPlacement, currentHintIndex + 1);

        currentPlacement = previousPlacement;
    }

    if (currentIndex.value < line.size() && line[currentIndex].canColor(White)) {
        Placement previousPlacement = currentPlacement;

        const Placement WhiteSpace = Placement(std::vector<Cell>(1, Cell(CellColor::White)));
        currentPlacement = currentPlacement + WhiteSpace;
        dfsExhaustivePlacementFindRecursive(
          hintList, line, solutions, currentPlacement, currentHintIndex);

        currentPlacement = previousPlacement;
    }

    return ExhaustivePlacementPatternFinderResult::success;
}

template class DFSExhaustivePlacementPatternFinder<Core::RowOrientation>;
template class DFSExhaustivePlacementPatternFinder<Core::ColumnOrientation>;

} // namespace VersaNo::Solver