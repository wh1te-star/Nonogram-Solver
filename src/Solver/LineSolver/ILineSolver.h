#ifndef ILINESOLVER_H
#define ILINESOLVER_H

#include "Board/NonogramBoard/NonogramBoard.h"
#include "Solver/IBoardUpdateHandler.h"
#include "Solver/ResultEnum/LineSolverResult.h"

class ILineSolver {
  public:
    virtual ~ILineSolver() = default;
    virtual LineSolverResult
    solve(const HintSet &hintSet, Line &line, IBoardUpdateHandler &boardUpdateHandler) = 0;
};

#endif
