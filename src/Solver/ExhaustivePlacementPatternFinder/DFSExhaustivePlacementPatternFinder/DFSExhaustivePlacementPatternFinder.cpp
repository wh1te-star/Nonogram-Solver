#include "Solver/ExhaustivePlacementPatternFinder/DFSExhaustivePlacementPatternFinder/DFSExhaustivePlacementPatternFinder.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

template <typename TOrientation>
ExhaustivePlacementPatternFinderResult DFSExhaustivePlacementPatternFinder<TOrientation>::find(
  const HintList &hintList, const Line<TOrientation> &line, std::vector<Placement<TOrientation>> &solutions) {
    return dfsExhaustivePlacementFind(hintList, line, solutions);
}

template <typename TOrientation>
ExhaustivePlacementPatternFinderResult
DFSExhaustivePlacementPatternFinder<TOrientation>::dfsExhaustivePlacementFind(
  const HintList &hintList, const Line<TOrientation> &line, std::vector<Placement<TOrientation>> &solutions) {
    Placement<TOrientation> currentPlacement = Placement<TOrientation>("");
    return dfsExhaustivePlacementFindRecursive(hintList, line, solutions, currentPlacement, 0);
}

template <typename TOrientation>
ExhaustivePlacementPatternFinderResult
DFSExhaustivePlacementPatternFinder<TOrientation>::dfsExhaustivePlacementFindRecursive(
  const HintList &hintList,
  const Line<TOrientation> &line,
  std::vector<Placement<TOrientation>> &solutions,
  Placement<TOrientation> &currentPlacement,
  int currentHintIndex) {
    if (currentPlacement.size() > line.size()) {
        return ExhaustivePlacementPatternFinderResult::notFound;
    }
    if (currentHintIndex >= hintList.size()) {
        Placement<TOrientation> foundPlacement = currentPlacement;
        for (CellIndex i = CellIndex(currentPlacement.size()); i < line.size(); i = i + 1) {
            if (!line[i].canColor(White)) {
                return ExhaustivePlacementPatternFinderResult::notFound;
            }
            foundPlacement = foundPlacement + Placement<TOrientation>("W");
        }
        solutions.push_back(foundPlacement);
        return ExhaustivePlacementPatternFinderResult::success;
    }

    HintNumber hintNumber = hintList[currentHintIndex];
    CellIndex currentIndex = CellIndex(currentPlacement.size());
    if (line.canPlaceBlock(currentIndex, hintNumber)) {
        Placement<TOrientation> previousPlacement = currentPlacement;
        currentPlacement = currentPlacement + Placement<TOrientation>(hintNumber);
        if (currentPlacement.size() < line.size()) {
            currentPlacement = currentPlacement + Placement<TOrientation>("W");
        }
        dfsExhaustivePlacementFindRecursive(
          hintList, line, solutions, currentPlacement, currentHintIndex + 1);
        currentPlacement = previousPlacement;
    }

    if (currentIndex < line.size() && line[currentIndex].canColor(White)) {
        Placement<TOrientation> previousPlacement = currentPlacement;
        currentPlacement = currentPlacement + Placement<TOrientation>("W");
        dfsExhaustivePlacementFindRecursive(
          hintList, line, solutions, currentPlacement, currentHintIndex);
        currentPlacement = previousPlacement;
    }

    return ExhaustivePlacementPatternFinderResult::success;
}

template class DFSExhaustivePlacementPatternFinder<Core::RowOrientation>;
template class DFSExhaustivePlacementPatternFinder<Core::ColumnOrientation>;

} // namespace VersaNo::Solver