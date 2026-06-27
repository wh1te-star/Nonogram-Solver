#include "Solver/LineSolver/OverlapLineSolver/OverlapLineSolver.h"

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"
#include "Solver/LeftmostPlacementFinder/ILeftmostPlacementFinder.h"
#include "Solver/RightmostPlacementFinder/IRightmostPlacementFinder.h"

#include <vector>


namespace VersaNo::Solver {
using namespace VersaNo::Core;

template <typename TOrientation>
OverlapLineSolver<TOrientation>::OverlapLineSolver(
  ILeftmostPlacementFinder<TOrientation> &leftmostPlacementFinder,
  IRightmostPlacementFinder<TOrientation> &rightmostPlacementFinder)
    : leftmostPlacementFinder(leftmostPlacementFinder)
    , rightmostPlacementFinder(rightmostPlacementFinder) {}

template <typename TOrientation>
LineSolverResult OverlapLineSolver<TOrientation>::solve(
  const HintList &hintList,
  typename Core::LineTraits<TOrientation>::Line &line,
  IBoardUpdateHandler &boardUpdateHandler) {
    return overlapLineSolve(hintList, line, boardUpdateHandler);
}

template <typename TOrientation>
LineSolverResult OverlapLineSolver<TOrientation>::overlapLineSolve(
  const HintList &hintList,
  typename Core::LineTraits<TOrientation>::Line &line,
  IBoardUpdateHandler &boardUpdateHandler) {
    using Traits = typename Core::LineTraits<TOrientation>;
    using Index = typename Traits::Index;
    using PeerIndex = typename Traits::PeerIndex;
    using Line = typename Traits::Line;
    using Placement = typename Traits::Placement;

    Placement leftmostPlacement = Placement(std::vector<Cell>());
    Placement rightmostPlacement = Placement(std::vector<Cell>());
    PlacementFinderResult leftmostPlacementFinderResult = leftmostPlacementFinder.find(
      hintList, line, leftmostPlacement, boardUpdateHandler);
    PlacementFinderResult rightmostPlacementFinderResult = rightmostPlacementFinder.find(
      hintList, line, rightmostPlacement, boardUpdateHandler);
    if (
      leftmostPlacementFinderResult == PlacementFinderResult::notFound ||
      rightmostPlacementFinderResult == PlacementFinderResult::notFound) {
        return LineSolverResult::HasContradiction;
    }

    std::vector<PeerIndex> leftmostHintIndex = leftmostPlacement.getHintIndex();
    std::vector<PeerIndex> rightmostHintIndex = rightmostPlacement.getHintIndex();

    Line determined = Line(std::vector<Cell>(line.size(), Cell(CellColor::None)));
    for (PeerIndex index : PeerIndex::closedRangeUp(0, leftmostHintIndex.front().value - 1)) {
        determined[index] = Cell(CellColor::White);
    }
    for (PeerIndex index : PeerIndex::closedRangeUp(rightmostHintIndex.back().value + hintList.back().value, (int)line.size() - 1)) {
        determined[index] = Cell(CellColor::White);
    }
    for (HintIndex hintIndex : Core::HintIndex::closedRangeUp(0, (int)hintList.size() - 1)) {
        HintNumber hintNumber = hintList[hintIndex];
        PeerIndex leftStart = leftmostHintIndex[hintIndex.value];
        PeerIndex leftEnd = leftStart + hintNumber.value - 1;
        PeerIndex rightStart = rightmostHintIndex[hintIndex.value];
        PeerIndex rightEnd = rightStart + hintNumber.value - 1;
        for (PeerIndex index : PeerIndex::closedRangeUp(rightStart.value, leftEnd.value)) {
            determined[index] = Cell(CellColor::Black);
        }

        // If the leftmost and rightmost placements of a block are the same, mark the adjacent cells as white
        if (leftStart == rightStart) {
            PeerIndex leftAdjacent = leftStart - 1;
            PeerIndex rightAdjacent = leftStart + hintNumber.value;
            if (leftAdjacent >= PeerIndex(0)) {
                determined[leftAdjacent] = Cell(CellColor::White);
            }
            if (rightAdjacent.value < line.size()) {
                determined[rightAdjacent] = Cell(CellColor::White);
            }
        }
    }

    line.apply(determined);

    return LineSolverResult::Success;
}

template class OverlapLineSolver<Core::RowOrientation>;
template class OverlapLineSolver<Core::ColumnOrientation>;

} // namespace VersaNo::Solver