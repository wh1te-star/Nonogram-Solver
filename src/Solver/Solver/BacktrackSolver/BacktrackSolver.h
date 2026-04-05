#ifndef VERSAN_CORE_BACKTRACKSOLVER_H
#define VERSAN_CORE_BACKTRACKSOLVER_H

#include "Rendering/Shared/StopSignal/StopSignal.h"
#include "Solver/Assumption/AssumptionEnumerator/IAssumptionEnumerator.h"
#include "Solver/Assumption/AssumptionSelector/IAssumptionSelector.h"
#include "Solver/Assumption/BacktrackStack/BacktrackStack.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include "Solver/IBoardUpdateHandler.h"
#include "Solver/Solver/ISolver.h"

namespace VersaN::Solver {

class BacktrackSolver : public ISolver {
  private:
    Rendering::StopSignal &stopSignal;
    IDeterministicSolver &deterministicSolver;
    IAssumptionSelector &assumptionSelector;
    IAssumptionEnumerator &assumptionEnumerator;
    BacktrackStack &backtrackStack;

  public:
    BacktrackSolver(
      Rendering::StopSignal &stopSignal,
      IDeterministicSolver &deterministicSolver,
      IAssumptionSelector &assumptionSelector,
      IAssumptionEnumerator &assumptionEnumerator,
      BacktrackStack &backtrackStack);

    void solve(
      Core::NonogramBoard &nonogramBoard,
      std::vector<Core::Board> &solutions,
      IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    void backtrackSolve(
      Core::NonogramBoard &nonogramBoard,
      std::vector<Core::Board> &solutions,
      IBoardUpdateHandler &boardUpdateHandler);

    void backtrackSolveRecursive(
      Core::NonogramBoard &nonogramBoard,
      std::vector<Core::Board> &solutions,
      int depth,
      IBoardUpdateHandler &boardUpdateHandler);
};

} // namespace VersaN::Solver

#endif // VERSAN_CORE_BACKTRACKSOLVER_H