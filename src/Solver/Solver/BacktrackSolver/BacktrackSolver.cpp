#include "Solver/Solver/BacktrackSolver/BacktrackSolver.h"

BacktrackSolver::BacktrackSolver(
    IDeterministicSolver &deterministicSolver)
    : deterministicSolver(deterministicSolver) {}

void BacktrackSolver::solve(NonogramBoard &nonogramBoard) {
  backtrackSolve(nonogramBoard);
}

void BacktrackSolver::backtrackSolve(NonogramBoard &nonogramBoard) {
  deterministicSolver.solve(nonogramBoard);
  backtrackSolveRecursive(nonogramBoard);
}

void BacktrackSolver::backtrackSolveRecursive(
    NonogramBoard &nonogramBoard, int depth) {
  if (nonogramBoard.isSolved()) {
    solutions.push_back(nonogramBoard.getBoard());
    return;
  }

  for (CellChange assumption : getExhaustiveList()) {
    nonogramBoard.applyChange(assumption);

    bool hasContradiction = deterministicSolver.solve(nonogramBoard, 1);
    if (!hasContradiction) {
      backtrackSolveRecursive(nonogramBoard, depth + 1);
    }

    nonogramBoard.revertChange(assumption);
  }
}
