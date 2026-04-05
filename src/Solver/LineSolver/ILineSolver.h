#ifndef VERSAN_CORE_ILINESOLVER_H
#define VERSAN_CORE_ILINESOLVER_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Solver/IBoardUpdateHandler.h"
#include "Solver/ResultEnum/LineSolverResult.h"

namespace VersaNo::Solver {

class ILineSolver {
  public:
    virtual ~ILineSolver() = default;
    virtual LineSolverResult solve(
      const Core::HintSet &hintSet, Core::Line &line, IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSAN_CORE_ILINESOLVER_H
