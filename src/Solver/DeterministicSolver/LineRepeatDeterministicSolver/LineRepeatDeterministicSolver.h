#ifndef LINEREPEATDETERMINISTICSOLVER_H
#define LINEREPEATDETERMINISTICSOLVER_H

#include "Board/BacktrackBoard/BacktrackBoard.h"
#include "Shared/StopSignal/StopSignal.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFindAlgorithm.h"
#include "Solver/LineSolver/ILineSolver.h"

class LineRepeatDeterministicSolver : public IDeterministicSolver {
public:
  StopSignal &stopSignal;
  IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder;
  IDeterministicSolver &deterministicSolver;
  ILineSolver &lineSolver;

  LineRepeatDeterministicSolver(
      StopSignal &stopSignal,
      IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder,
      IDeterministicSolver &deterministicSolver, ILineSolver &lineSolver);
  bool solve(SharedBacktrackBoard &sharedBacktrackBoard,
             BacktrackBoard &backtrackBoard) override;

private:
  bool lineRepeatDeterministicSolve(SharedBacktrackBoard &sharedBacktrackBoard,
                                    BacktrackBoard &backtrackBoard);
};

#endif