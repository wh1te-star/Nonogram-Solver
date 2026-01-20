#include "Solver/LineSolver/OverlapLineSolver/OverlapLineSolver.h"

#include "Solver/LeftmostPlacementFinder/DFSLeftmostPlacementFinder/DFSLeftmostPlacementFinder.h"
#include "Solver/RightmostPlacementFinder/DFSRightmostPlacementFinder/DFSRightmostPlacementFinder.h"

OverlapLineSolver::OverlapLineSolver(
    ILeftmostPlacementFinder &leftmostPlacementFinder,
    IRightmostPlacementFinder &rightmostPlacementFinder)
    : leftmostPlacementFinder(leftmostPlacementFinder),
      rightmostPlacementFinder(rightmostPlacementFinder) {}

bool OverlapLineSolver::solve(const HintSet &hintSet, Line &line) {
  overlapLineSolve(hintSet, line);
  return false;
}

bool OverlapLineSolver::overlapLineSolve(const HintSet &hintSet, Line &line) {
  Placement leftmostPlacement = leftmostPlacementFinder.find(hintSet, line);
  Placement rightmostPlacement = rightmostPlacementFinder.find(hintSet, line);
  if (leftmostPlacement.size() == 0 || rightmostPlacement.size() == 0) {
    return true;
  }

  std::vector<CellIndex> leftmostHintIndex = leftmostPlacement.getHintIndex();
  std::vector<CellIndex> rightmostHintIndex = rightmostPlacement.getHintIndex();

  Line determined(std::vector<Cell>(line.size(), Cell(CellColor::None)));
  for (int i = 0; i < leftmostHintIndex.front().getIndex(); i++) {
    CellIndex cellIndex = CellIndex(i);
    determined[cellIndex] = Cell(White);
  }
  for (int i =
           (rightmostHintIndex.back() + hintSet.getNumbers().back()).getIndex();
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
    for (CellIndex cellIndex = leftStart; cellIndex <= leftEnd; cellIndex++) {
      if (rightStart <= cellIndex && cellIndex <= rightEnd) {
        determined[cellIndex] = Cell(Black);
      }
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

  // Must Fix, Must Fix, Must Fix, Must Fix, Must Fix, Must Fix, Must Fix, Must Fix, 
  line.apply()
  return false;
}