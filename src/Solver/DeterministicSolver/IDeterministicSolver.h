#ifndef IDETERMINISTICSOLVER_H
#define IDETERMINISTICSOLVER_H

#include "Shared/SharedDataAliases.h"
#include "Solver/DeterministicSolver/DeterministicSolverResult.h"

class IDeterministicSolver {
  public:
    virtual ~IDeterministicSolver() = default;
    virtual DeterministicSolverResult
    solve(ISender<NonogramBoard> &nonogramBoardSender, NonogramBoard &nonogramBoard) = 0;
};

#endif