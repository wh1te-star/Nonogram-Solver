#include "Solver/Solver/BacktrackSolver/BacktrackSolver.h"

#include "Placement/Placement/Placement.h"
#include "Solver/Assumption/AssumptionSelector/IAssumptionSelector.h"
#include "Solver/Assumption/AssumptionSelector/LineIndexAssumptionSelector/LineIndexAssumptionSelector.h"
#include "Solver/DeterministicSolver/DeterministicSolverResult.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include <cassert>

BacktrackSolver::BacktrackSolver(
  StopSignal &stopSignal,
  IDeterministicSolver &deterministicSolver,
  IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder)
    : stopSignal(stopSignal)
    , deterministicSolver(deterministicSolver)
    , exhaustivePlacementPatternFinder(exhaustivePlacementPatternFinder) {}

void BacktrackSolver::solve(
  ISender<NonogramBoard> &nonogramBoardSender,
  NonogramBoard &nonogramBoard,
  std::vector<Board> &solutions) {
    backtrackSolve(nonogramBoardSender, nonogramBoard, solutions);
}

void BacktrackSolver::backtrackSolve(
  ISender<NonogramBoard> &nonogramBoardSender,
  NonogramBoard &nonogramBoard,
  std::vector<Board> &solutions) {

    DeterministicSolverResult result = deterministicSolver.solve(
      nonogramBoardSender, nonogramBoard);
    if (result == DeterministicSolverResult::Solved) {
        solutions.push_back(nonogramBoard.getBoard());
        return;
    }

    if (
      result != DeterministicSolverResult::HasContradiction &&
      result != DeterministicSolverResult::Stopped) {
        backtrackSolveRecursive(nonogramBoardSender, nonogramBoard, solutions, 0);
    }
}

void BacktrackSolver::backtrackSolveRecursive(
  ISender<NonogramBoard> &nonogramBoardSender,
  NonogramBoard &nonogramBoard,
  std::vector<Board> &solutions,
  int depth) {

    if (stopSignal.shouldStop())
        return;
    if (nonogramBoardSender.isRequested()) {
        nonogramBoardSender.send(nonogramBoard);
    }

    IAssumptionSelector &assumptionSelector = LineIndexAssumptionSelector(
      exhaustivePlacementPatternFinder, Orientation::Row, depth);

    for (const auto &assumption : assumptionSelector.select(nonogramBoard)) {
        if (stopSignal.shouldStop())
            return;

        assumption->applyTo(nonogramBoard);

        switch (deterministicSolver.solve(nonogramBoardSender, nonogramBoard)) {
        case DeterministicSolverResult::Solved:
            solutions.push_back(nonogramBoard.getBoard());
            break;

        case DeterministicSolverResult::NoMoreProgress:
            backtrackSolveRecursive(nonogramBoardSender, nonogramBoard, solutions, depth + 1);
            break;

        case DeterministicSolverResult::HasContradiction:
            break;

        case DeterministicSolverResult::Stopped:
            return;

        default:
            assert(false);
            break;
        }

        //nonogramBoard.revert();
    }
}