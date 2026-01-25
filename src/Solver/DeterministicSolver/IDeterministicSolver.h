#ifndef IDETERMINISTICSOLVER_H
#define IDETERMINISTICSOLVER_H

#include "Board/BacktrackBoard/BacktrackBoard.h"
#include "Shared/SharedDataAliases.h"
#include "Solver/DeterministicSolver/DeterministicSolverResult.h"

class IDeterministicSolver {
public:
  virtual ~IDeterministicSolver() = default;
  virtual DeterministicSolverResult
  solve(ISender<BacktrackBoard> &sharedBacktrackBoard,
        BacktrackBoard &backtrackBoard) = 0;
};

#endif