#include "Solver/LineSolver/OverlapLineSolver/OverlapLineSolver.h"

#include "Solver/LeftmostPlacementFinder/DFSLeftmostPlacementFinder/DFSLeftmostPlacementFinder.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"
#include "Solver/RightmostPlacementFinder/DFSRightmostPlacementFinder/DFSRightmostPlacementFinder.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

  template <typename TOrientation>
OverlapLineSolver<TOrientation>::OverlapLineSolver(
  ILeftmostPlacementFinder<TOrientation> &leftmostPlacementFinder,
  IRightmostPlacementFinder<TOrientation> &rightmostPlacementFinder)
    : leftmostPlacementFinder(leftmostPlacementFinder)
    , rightmostPlacementFinder(rightmostPlacementFinder) {}

template <typename TOrientation>
LineSolverResult OverlapLineSolver<TOrientation>::solve(
  const HintList &hintList, Line<TOrientation> &line, IBoardUpdateHandler &boardUpdateHandler) {
    return overlapLineSolve(hintList, line, boardUpdateHandler);
}

template <typename TOrientation>
LineSolverResult OverlapLineSolver<TOrientation>::overlapLineSolve(
  const HintList &hintList, Line<TOrientation> &line, IBoardUpdateHandler &boardUpdateHandler) {
    Placement<TOrientation> leftmostPlacement = Placement<TOrientation>("");
    Placement<TOrientation> rightmostPlacement = Placement<TOrientation>("");
    PlacementFinderResult leftmostPlacementFinderResult = leftmostPlacementFinder.find(
      hintList, line, leftmostPlacement, boardUpdateHandler);
    PlacementFinderResult rightmostPlacementFinderResult = rightmostPlacementFinder.find(
      hintList, line, rightmostPlacement, boardUpdateHandler);
    if (
      leftmostPlacementFinderResult == PlacementFinderResult::notFound ||
      rightmostPlacementFinderResult == PlacementFinderResult::notFound) {
        return LineSolverResult::HasContradiction;
    }

    std::vector<CellIndex> leftmostHintIndex = leftmostPlacement.getHintIndex();
    std::vector<CellIndex> rightmostHintIndex = rightmostPlacement.getHintIndex();

    Line<TOrientation> determined(std::vector<Cell<TOrientation>>(line.size(), Cell<TOrientation>(CellColor::None)));
    for (int i = 0; i < leftmostHintIndex.front().getIndex(); i++) {
        CellIndex cellIndex = CellIndex(i);
        determined[cellIndex] = Cell<TOrientation>(CellColor::White);
    }
    for (int i = (rightmostHintIndex.back() + hintList.getNumbers().back()).getIndex();
         i < line.size(); i++) {
        CellIndex cellIndex = CellIndex(i);
        determined[cellIndex] = Cell<TOrientation>(CellColor::White);
    }
    for (int hintIndex = 0; hintIndex < hintList.size(); hintIndex++) {
        HintNumber hintNumber = hintList[hintIndex];
        CellIndex leftStart = leftmostHintIndex[hintIndex];
        CellIndex leftEnd = leftStart + hintNumber - 1;
        CellIndex rightStart = rightmostHintIndex[hintIndex];
        CellIndex rightEnd = rightStart + hintNumber - 1;
        for (CellIndex cellIndex = rightStart; cellIndex <= leftEnd; cellIndex++) {
            determined[cellIndex] = Cell<TOrientation>(CellColor::Black);
        }

        if (leftStart == rightStart) {
            CellIndex leftAdjacent = leftStart - 1;
            CellIndex rightAdjacent = leftStart + hintNumber;
            if (leftAdjacent >= 0) {
                determined[leftAdjacent] = Cell<TOrientation>(CellColor::White);
            }
            if (rightAdjacent < line.size()) {
                determined[rightAdjacent] = Cell<TOrientation>(CellColor::White);
            }
        }
    }

    line.apply(determined);

    return LineSolverResult::Success;
}

} // namespace VersaNo::Solver