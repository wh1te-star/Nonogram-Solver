#include "Solver/Solver/BacktrackSolver/BacktrackSolver.h"

#include "Placement/Placement/Placement.h"
#include "Solver/DeterministicSolver/DeterministicSolverResult.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include <cassert>

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
  
  DeterministicSolverResult result = deterministicSolver.solve(sharedBacktrackBoard, backtrackBoard);
  if (result == DeterministicSolverResult::Solved) {
    solutions.push_back(backtrackBoard.getBoard());
    return;
  }

  if (result != DeterministicSolverResult::HasContradiction && result != DeterministicSolverResult::Stopped) {
    backtrackSolveRecursive(sharedBacktrackBoard, backtrackBoard, solutions, 0);
  }
}

void BacktrackSolver::backtrackSolveRecursive(
    ISender<BacktrackBoard> &sharedBacktrackBoard,
    BacktrackBoard &backtrackBoard, std::vector<Board> &solutions, int depth) {
  
  if (stopSignal.shouldStop()) return;
  if (sharedBacktrackBoard.isRequested()) {
    sharedBacktrackBoard.send(backtrackBoard);
  }

  // Assumption selection: Row from top to bottom
  RowIndex rowIndex = RowIndex(depth);

  HintSet hintSet = backtrackBoard.getRowHintSetList()[rowIndex];
  Line line = backtrackBoard.getRowLine(rowIndex);

  // Assumption application: Try all possible placements for Lines
  for (Placement assumption : exhaustivePlacementPatternFinder.find(hintSet, line)) {
    if (stopSignal.shouldStop()) return;

    Board previousBoard = backtrackBoard.getBoard();
    backtrackBoard.applyRow(rowIndex, assumption.toRowPlacement());

    switch (deterministicSolver.solve(sharedBacktrackBoard, backtrackBoard)) {
      case DeterministicSolverResult::Solved:
        solutions.push_back(backtrackBoard.getBoard());
        break;

      case DeterministicSolverResult::NoMoreProgress:
        backtrackSolveRecursive(sharedBacktrackBoard, backtrackBoard, solutions, depth + 1);
        break;

      case DeterministicSolverResult::HasContradiction:
        break;

      case DeterministicSolverResult::Stopped:
        return;

      default:
        assert(false);
        break;
    }

    backtrackBoard.applyBoard(previousBoard, true);
  }
}