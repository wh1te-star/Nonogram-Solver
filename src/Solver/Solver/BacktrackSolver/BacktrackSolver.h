#ifndef BACKTRACKSOLVER_H
#define BACKTRACKSOLVER_H

#include "Solver/Solver/ISolver.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"

class BacktrackSolver : public ISolver {
private:
  IDeterministicSolver& deterministicSolver;

public:
  BacktrackSolver(IDeterministicSolver& deterministicSolver);
  void solve(
    SharedBacktrackBoard &sharedBacktrackBoard,
    BacktrackBoard &backtrackBoard
  ) override;

private:
  void backtrackSolve(
    SharedBacktrackBoard &sharedBacktrackBoard,
    BacktrackBoard &backtrackBoard
  );
  void backtrackSolveRecursive(
    SharedBacktrackBoard &sharedBacktrackBoard,
    BacktrackBoard& backtrackBoard,
    int depth
  );
};

#endif