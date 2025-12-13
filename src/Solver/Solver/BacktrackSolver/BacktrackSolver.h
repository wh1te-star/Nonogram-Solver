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
    NonogramBoard& nonogramBoard
  ) override;

private:
  void backtrackSolve(
    NonogramBoard& nonogramBoard
  );
  void backtrackSolveRecursive(
    NonogramBoard& nonogramBoard,
    int depth
  );
};

#endif