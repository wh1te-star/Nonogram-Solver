#ifndef LINEREPEATDETERMINISTICSOLVER_H
#define LINEREPEATDETERMINISTICSOLVER_H

#include "Board/BacktrackBoard/BacktrackBoard.h"
#include "Shared/StopSignal/IStopSignal.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFindAlgorithm.h"
#include "Solver/LineSolver/ILineSolver.h"

class LineRepeatDeterministicSolver : public IDeterministicSolver {
public:
  IStopSignal &stopSignal;
  IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder;
  IDeterministicSolver &deterministicSolver;
  ILineSolver &lineSolver;

  LineRepeatDeterministicSolver(
      IStopSignal &stopSignal,
      IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder,
      IDeterministicSolver &deterministicSolver, ILineSolver &lineSolver);
  bool solve(SharedBacktrackBoard &sharedBacktrackBoard,
             BacktrackBoard &backtrackBoard) override;

private:
  bool lineRepeatDeterministicSolve(SharedBacktrackBoard &sharedBacktrackBoard,
                                    BacktrackBoard &backtrackBoard);
};

#endif