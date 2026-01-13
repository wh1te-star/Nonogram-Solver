#include "Solver/Solver/BacktrackSolver/BacktrackSolver.h"

BacktrackSolver::BacktrackSolver(StopSignal &stopSignal, IDeterministicSolver &deterministicSolver)
    : stopSignal(stopSignal), deterministicSolver(deterministicSolver) {}

void BacktrackSolver::solve(
    SharedBacktrackBoard &sharedBacktrackBoard,
    BacktrackBoard &backtrackBoard
) {
  backtrackSolve(sharedBacktrackBoard, backtrackBoard);
}

void BacktrackSolver::backtrackSolve(
    SharedBacktrackBoard &sharedBacktrackBoard,
    BacktrackBoard &backtrackBoard
) {
  deterministicSolver.solve(sharedBacktrackBoard, backtrackBoard);
  backtrackSolveRecursive(sharedBacktrackBoard, backtrackBoard, 0);
}

void BacktrackSolver::backtrackSolveRecursive(
    SharedBacktrackBoard &sharedBacktrackBoard,
    BacktrackBoard &backtrackBoard,
    int depth
) {
  if (backtrackBoard.isSolved()) {
    solutions.push_back(backtrackBoard.getBoard());
    return;
  }

  for (CellChange assumption : getExhaustiveList()) {
    backtrackBoard.applyChange(assumption);

    bool hasContradiction = deterministicSolver.solve(backtrackBoard, 1);
    if (!hasContradiction) {
      backtrackSolveRecursive(sharedBacktrackBoard, backtrackBoard, depth + 1);
    }

    backtrackBoard.revertChange(assumption);
  }
}
