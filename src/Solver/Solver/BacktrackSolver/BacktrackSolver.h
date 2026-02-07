#ifndef BACKTRACKSOLVER_H
#define BACKTRACKSOLVER_H

#include "Shared/StopSignal/StopSignal.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include "Solver/Solver/ISolver.h"

class BacktrackSolver : public ISolver {
private:
  StopSignal &stopSignal;
  IDeterministicSolver &deterministicSolver;
  IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder;

public:
  BacktrackSolver(
      StopSignal &stopSignal, IDeterministicSolver &deterministicSolver,
      IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder);
  void solve(ISender<BacktrackBoard> &sharedBacktrackBoard,
             BacktrackBoard &backtrackBoard,
             std::vector<Board> &solutions) override;

private:
  void backtrackSolve(ISender<BacktrackBoard> &sharedBacktrackBoard,
                      BacktrackBoard &backtrackBoard,
                      std::vector<Board> &solutions);
  void backtrackSolveRecursive(ISender<BacktrackBoard> &sharedBacktrackBoard,
                               BacktrackBoard &backtrackBoard,
                               std::vector<Board> &solutions, int depth);
};

#endif