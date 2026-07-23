#include "Solver/Solver/BacktrackSolver/BacktrackSolver.h"

#include "Core/NamespaceInterface/SolverInterface/IBoardUpdateHandler.h"
#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionSelector/IAssumptionSelector.h"
#include "Solver/Assumption/AssumptionSelector/LineIndexAssumptionSelector/LineIndexAssumptionSelector.h"
#include "Solver/Assumption/Snapshot/PlacementCountSnapshot/PlacementCountSnapshot.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include "Solver/ResultEnum/DeterministicSolverResult.h"

#include <cassert>

using namespace VersaNo::Core;
using namespace VersaNo::Rendering;
namespace VersaNo::Solver {

BacktrackSolver::BacktrackSolver(
  StopSignal &stopSignal,
  IDeterministicSolver &deterministicSolver,
  IAssumptionSelector &assumptionSelector,
  IAssumptionEnumerator &assumptionEnumerator,
  BacktrackStack &backtrackStack)
    : stopSignal(stopSignal)
    , deterministicSolver(deterministicSolver)
    , assumptionSelector(assumptionSelector)
    , assumptionEnumerator(assumptionEnumerator)
    , backtrackStack(backtrackStack) {}

void BacktrackSolver::solve(
  NonogramBoard &nonogramBoard,
  std::vector<std::unique_ptr<const Core::IBoard>> &solutions,
  IBoardUpdateHandler &boardUpdateHandler) {
    backtrackSolve(nonogramBoard, solutions, boardUpdateHandler);
}

void BacktrackSolver::backtrackSolve(
  NonogramBoard &nonogramBoard,
  std::vector<std::unique_ptr<const Core::IBoard>> &solutions,
  IBoardUpdateHandler &boardUpdateHandler) {

    DeterministicSolverResult result = deterministicSolver.solve(nonogramBoard, boardUpdateHandler);
    if (result == DeterministicSolverResult::Solved) {
        solutions.push_back(nonogramBoard.getBoard().clone());
        return;
    }

    if (
      result != DeterministicSolverResult::HasContradiction &&
      result != DeterministicSolverResult::Stopped) {
        backtrackSolveRecursive(nonogramBoard, solutions, 0, boardUpdateHandler);
    }
}

void BacktrackSolver::backtrackSolveRecursive(
  NonogramBoard &nonogramBoard,
  std::vector<std::unique_ptr<const Core::IBoard>> &solutions,
  int depth,
  IBoardUpdateHandler &boardUpdateHandler) {

    if (stopSignal.shouldStop())
        return;

    std::unique_ptr<IAssumptionPosition> assumptionPosition = assumptionSelector.select(
      nonogramBoard, AssumptionSelectionContext{depth});
    for (const auto &assumption :
         assumptionEnumerator.enumerate(nonogramBoard, *assumptionPosition)) {
        if (stopSignal.shouldStop())
            return;

        backtrackStack.push(
          std::make_unique<PlacementCountSnapshot>(
            nonogramBoard.getBoard(),
            RowPlacementCountList(
              std::vector<PlacementCount>(
                nonogramBoard.getLength<RowOrientation>().value, PlacementCount(0))),
            ColumnPlacementCountList(
              std::vector<PlacementCount>(
                nonogramBoard.getLength<ColumnOrientation>().value, PlacementCount(0)))));
        assumption->applyTo(nonogramBoard);

        boardUpdateHandler.onBoardUpdate(
          nonogramBoard.getBoard(), nonogramBoard.getBoard(), nonogramBoard.getBoard());

        switch (deterministicSolver.solve(nonogramBoard, boardUpdateHandler)) {
        case DeterministicSolverResult::Solved:
            solutions.push_back(nonogramBoard.getBoard().clone());
            break;

        case DeterministicSolverResult::NoMoreProgress:
            backtrackSolveRecursive(nonogramBoard, solutions, depth + 1, boardUpdateHandler);
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

        boardUpdateHandler.onBoardUpdate(
          nonogramBoard.getBoard(), nonogramBoard.getBoard(), nonogramBoard.getBoard());
    }
}

} // namespace VersaNo::Solver