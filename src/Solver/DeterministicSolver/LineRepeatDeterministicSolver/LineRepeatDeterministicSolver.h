#ifndef LINEREPEATDETERMINISTICSOLVER_H
#define LINEREPEATDETERMINISTICSOLVER_H

#include "Board/NonogramBoard/NonogramBoard.h"
#include "Shared/StopSignal/StopSignal.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include "Solver/LineSolver/ILineSolver.h"
#include "Solver/ResultEnum/DeterministicSolverResult.h"

class LineRepeatDeterministicSolver : public IDeterministicSolver {
  public:
    StopSignal &stopSignal;
    ILineSolver &lineSolver;

    LineRepeatDeterministicSolver(StopSignal &stopSignal, ILineSolver &lineSolver);
    DeterministicSolverResult
    solve(NonogramBoard &nonogramBoard, IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    DeterministicSolverResult lineRepeatDeterministicSolve(
      NonogramBoard &nonogramBoard, IBoardUpdateHandler &boardUpdateHandler);
};

#endif