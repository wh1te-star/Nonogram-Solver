#ifndef VERSANO_CORE_BACKTRACKSOLVER_H
#define VERSANO_CORE_BACKTRACKSOLVER_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Rendering/Shared/StopSignal/StopSignal.h"
#include "Solver/Assumption/AssumptionEnumerator/IAssumptionEnumerator.h"
#include "Solver/Assumption/AssumptionSelector/IAssumptionSelector.h"
#include "Solver/Assumption/BacktrackStack/BacktrackStack.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include "Solver/Solver/ISolver.h"

namespace VersaNo::Solver {

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

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_BACKTRACKSOLVER_H