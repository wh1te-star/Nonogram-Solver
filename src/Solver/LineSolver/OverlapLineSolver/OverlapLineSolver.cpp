#include "Solver/LineSolver/OverlapLineSolver/OverlapLineSolver.h"

#include "Solver/LeftmostPlacementFinder/DFSLeftmostPlacementFinder/DFSLeftmostPlacementFinder.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"
#include "Solver/RightmostPlacementFinder/DFSRightmostPlacementFinder/DFSRightmostPlacementFinder.h"

using namespace VersaN::Core;
namespace VersaN::Solver {

OverlapLineSolver::OverlapLineSolver(
  ILeftmostPlacementFinder &leftmostPlacementFinder,
  IRightmostPlacementFinder &rightmostPlacementFinder)
    : leftmostPlacementFinder(leftmostPlacementFinder)
    , rightmostPlacementFinder(rightmostPlacementFinder) {}

LineSolverResult OverlapLineSolver::solve(
  const HintSet &hintSet, Line &line, IBoardUpdateHandler &boardUpdateHandler) {
    return overlapLineSolve(hintSet, line, boardUpdateHandler);
}

LineSolverResult OverlapLineSolver::overlapLineSolve(
  const HintSet &hintSet, Line &line, IBoardUpdateHandler &boardUpdateHandler) {
    Placement leftmostPlacement = Placement("");
    Placement rightmostPlacement = Placement("");
    PlacementFinderResult leftmostPlacementFinderResult = leftmostPlacementFinder.find(
      hintSet, line, leftmostPlacement, boardUpdateHandler);
    PlacementFinderResult rightmostPlacementFinderResult = rightmostPlacementFinder.find(
      hintSet, line, rightmostPlacement, boardUpdateHandler);
    if (
      leftmostPlacementFinderResult == PlacementFinderResult::notFound ||
      rightmostPlacementFinderResult == PlacementFinderResult::notFound) {
        return LineSolverResult::HasContradiction;
    }

    std::vector<CellIndex> leftmostHintIndex = leftmostPlacement.getHintIndex();
    std::vector<CellIndex> rightmostHintIndex = rightmostPlacement.getHintIndex();

    Line determined(std::vector<Cell>(line.size(), Cell(CellColor::None)));
    for (int i = 0; i < leftmostHintIndex.front().getIndex(); i++) {
        CellIndex cellIndex = CellIndex(i);
        determined[cellIndex] = Cell(White);
    }
    for (int i = (rightmostHintIndex.back() + hintSet.getNumbers().back()).getIndex();
         i < line.size(); i++) {
        CellIndex cellIndex = CellIndex(i);
        determined[cellIndex] = Cell(White);
    }
    for (int hintIndex = 0; hintIndex < hintSet.size(); hintIndex++) {
        HintNumber hintNumber = hintSet[hintIndex];
        CellIndex leftStart = leftmostHintIndex[hintIndex];
        CellIndex leftEnd = leftStart + hintNumber - 1;
        CellIndex rightStart = rightmostHintIndex[hintIndex];
        CellIndex rightEnd = rightStart + hintNumber - 1;
        for (CellIndex cellIndex = rightStart; cellIndex <= leftEnd; cellIndex++) {
            determined[cellIndex] = Cell(Black);
        }

        if (leftStart == rightStart) {
            CellIndex leftAdjacent = leftStart - 1;
            CellIndex rightAdjacent = leftStart + hintNumber;
            if (leftAdjacent >= 0) {
                determined[leftAdjacent] = Cell(White);
            }
            if (rightAdjacent < line.size()) {
                determined[rightAdjacent] = Cell(White);
            }
        }
    }

    line.apply(determined);

    return LineSolverResult::Success;
}

} // namespace VersaN::Solver