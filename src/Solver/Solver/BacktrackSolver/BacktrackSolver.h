#ifndef BACKTRACKSOLVER_H
#define BACKTRACKSOLVER_H

#include "Shared/StopSignal/StopSignal.h"
#include "Solver/Assumption/AssumptionEnumerator/IAssumptionEnumerator.h"
#include "Solver/Assumption/AssumptionSelector/IAssumptionSelector.h"
#include "Solver/Assumption/BacktrackStack/BacktrackStack.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include "Solver/IBoardUpdateHandler.h"
#include "Solver/Solver/ISolver.h"

class BacktrackSolver : public ISolver {
  private:
    StopSignal &stopSignal;
    IDeterministicSolver &deterministicSolver;
    IAssumptionSelector &assumptionSelector;
    IAssumptionEnumerator &assumptionEnumerator;
    BacktrackStack &backtrackStack;

  public:
    BacktrackSolver(
      StopSignal &stopSignal,
      IDeterministicSolver &deterministicSolver,
      IAssumptionSelector &assumptionSelector,
      IAssumptionEnumerator &assumptionEnumerator,
      BacktrackStack &backtrackStack);

    void solve(
      NonogramBoard &nonogramBoard,
      std::vector<Board> &solutions,
      IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    void backtrackSolve(
      NonogramBoard &nonogramBoard,
      std::vector<Board> &solutions,
      IBoardUpdateHandler &boardUpdateHandler);

    void backtrackSolveRecursive(
      NonogramBoard &nonogramBoard,
      std::vector<Board> &solutions,
      int depth,
      IBoardUpdateHandler &boardUpdateHandler);
};

#endif