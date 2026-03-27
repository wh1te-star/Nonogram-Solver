#include "Solver/Solver/BacktrackSolver/BacktrackSolver.h"

#include "Placement/Placement/Placement.h"
#include "Placement/PlacementCountList/ColumnPlacementCountList.h"
#include "Placement/PlacementCountList/RowPlacementCountList.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionSelector/IAssumptionSelector.h"
#include "Solver/Assumption/AssumptionSelector/LineIndexAssumptionSelector/LineIndexAssumptionSelector.h"
#include "Solver/Assumption/Snapshot/PlacementCountSnapshot/PlacementCountSnapshot.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include "Solver/ResultEnum/DeterministicSolverResult.h"
#include <cassert>

BacktrackSolver::BacktrackSolver(
  StopSignal &stopSignal,
  IDeterministicSolver &deterministicSolver,
  IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder,
  IAssumptionSelector &assumptionSelector)
    : stopSignal(stopSignal)
    , deterministicSolver(deterministicSolver)
    , exhaustivePlacementPatternFinder(exhaustivePlacementPatternFinder)
    , assumptionSelector(assumptionSelector) {
      backtrackStack = BacktrackStack(assumptionSelector);
      assumptionEnumerator = AssumptionEnumerator(exhaustivePlacementPatternFinder);
    }

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

    IAssumptionPosition assumptionPosition = assumptionSelector.select(
      nonogramBoard, AssumptionSelectionContext{depth});
    for (const auto &assumption :
         assumptionEnumerator.enumerate(nonogramBoard.getBoard(), assumptionPosition)) {
        if (stopSignal.shouldStop())
            return;

        backtrackStack.push(
          std::make_unique<PlacementCountSnapshot>(
            nonogramBoard.getBoard(),
            RowPlacementCountList(
              std::vector<PlacementCount>(
                nonogramBoard.getRowLength().getLength(), PlacementCount(0))),
            ColumnPlacementCountList(
              std::vector<PlacementCount>(
                nonogramBoard.getColumnLength().getLength(), PlacementCount(0)))));
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

        backtrackStack.pop(nonogramBoard);
    }
}