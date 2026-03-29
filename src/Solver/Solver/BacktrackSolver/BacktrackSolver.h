#ifndef BACKTRACKSOLVER_H
#define BACKTRACKSOLVER_H

#include "Shared/StopSignal/StopSignal.h"
#include "Solver/IBoardUpdateHandler.h"
#include "Solver/Assumption/AssumptionSelector/IAssumptionSelector.h"
#include "Solver/Assumption/AssumptionEnumerator/IAssumptionEnumerator.h"
#include "Solver/Assumption/BacktrackStack/BacktrackStack.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
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
      ISender<NonogramBoard> &nonogramBoardSender,
      NonogramBoard &nonogramBoard,
      std::vector<Board> &solutions) override;

  private:
    void backtrackSolve(
      ISender<NonogramBoard> &nonogramBoardSender,
      NonogramBoard &nonogramBoard,
      std::vector<Board> &solutions);
    void backtrackSolveRecursive(
      ISender<NonogramBoard> &nonogramBoardSender,
      NonogramBoard &nonogramBoard,
      std::vector<Board> &solutions,
      int depth);
};

#endif