#include "Solver/Solver/BacktrackSolver/BacktrackSolver.h"

#include "Placement/Placement/Placement.h"

BacktrackSolver::BacktrackSolver(
    StopSignal &stopSignal, IDeterministicSolver &deterministicSolver,
    IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder)
    : stopSignal(stopSignal), deterministicSolver(deterministicSolver),
      exhaustivePlacementPatternFinder(exhaustivePlacementPatternFinder) {}

void BacktrackSolver::solve(ISender<BacktrackBoard> &sharedBacktrackBoard,
                            BacktrackBoard &backtrackBoard,
                            std::vector<Board> &solutions) {
  backtrackSolve(sharedBacktrackBoard, backtrackBoard, solutions);
}

void BacktrackSolver::backtrackSolve(
    ISender<BacktrackBoard> &sharedBacktrackBoard,
    BacktrackBoard &backtrackBoard, std::vector<Board> &solutions) {
  deterministicSolver.solve(sharedBacktrackBoard, backtrackBoard);
  backtrackSolveRecursive(sharedBacktrackBoard, backtrackBoard, solutions, 0);
}

void BacktrackSolver::backtrackSolveRecursive(
    ISender<BacktrackBoard> &sharedBacktrackBoard,
    BacktrackBoard &backtrackBoard, std::vector<Board> &solutions, int depth) {
  if (backtrackBoard.isSolved()) {
    solutions.push_back(backtrackBoard.getBoard());
    return;
  }
  if (stopSignal.shouldStop()) {
    return;
  }
  if (sharedBacktrackBoard.isRequested()) {
    sharedBacktrackBoard.send(backtrackBoard);
  }

  RowIndex rowIndex = RowIndex(5);
  HintSet hintSet = backtrackBoard.getRowHintSetList()[rowIndex];
  Line line = backtrackBoard.getRowLine(rowIndex);
  for (Placement assumption :
       exhaustivePlacementPatternFinder.find(hintSet, line)) {
    Board previousBoard = backtrackBoard.getBoard();
    backtrackBoard.applyRow(rowIndex, assumption.toRowPlacement());

    bool hasContradiction =
        deterministicSolver.solve(sharedBacktrackBoard, backtrackBoard);
    if (!hasContradiction) {
      backtrackSolveRecursive(sharedBacktrackBoard, backtrackBoard, solutions,
                              depth + 1);
    }

    backtrackBoard.applyBoard(previousBoard, true);
  }
}
