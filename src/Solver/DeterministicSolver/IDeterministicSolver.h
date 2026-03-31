#ifndef IDETERMINISTICSOLVER_H
#define IDETERMINISTICSOLVER_H

#include "Shared/SharedDataAliases.h"
#include "Solver/ResultEnum/DeterministicSolverResult.h"
#include "Solver/IBoardUpdateHandler.h"

class IDeterministicSolver {
  public:
    virtual ~IDeterministicSolver() = default;
    virtual DeterministicSolverResult
    solve(NonogramBoard &nonogramBoard, IBoardUpdateHandler &boardUpdateHandler) = 0;
};

#endif