#ifndef LINEREPEATDETERMINISTICSOLVER_H
#define LINEREPEATDETERMINISTICSOLVER_H

#include "Board/BacktrackBoard/BacktrackBoard.h"
#include "Shared/StopSignal/StopSignal.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include "Solver/DeterministicSolver/DeterministicSolverResult.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFindAlgorithm.h"
#include "Solver/LineSolver/ILineSolver.h"

class LineRepeatDeterministicSolver : public IDeterministicSolver {
public:
  StopSignal &stopSignal;
  ILineSolver &lineSolver;

  LineRepeatDeterministicSolver(StopSignal &stopSignal,
                                ILineSolver &lineSolver);
  DeterministicSolverResult solve(ISender<BacktrackBoard> &sharedBacktrackBoard,
                                  BacktrackBoard &backtrackBoard) override;

private:
  DeterministicSolverResult
  lineRepeatDeterministicSolve(ISender<BacktrackBoard> &sharedBacktrackBoard,
                               BacktrackBoard &backtrackBoard);
};

#endif