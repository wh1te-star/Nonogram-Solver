#ifndef VERSANO_CORE_IDETERMINISTICSOLVER_H
#define VERSANO_CORE_IDETERMINISTICSOLVER_H

#include "Rendering/Shared/SharedDataAliases.h"
#include "Solver/IBoardUpdateHandler.h"
#include "Solver/ResultEnum/DeterministicSolverResult.h"

namespace VersaNo::Solver {

class IDeterministicSolver {
  public:
    virtual ~IDeterministicSolver() = default;
    virtual DeterministicSolverResult
    solve(Core::NonogramBoard &nonogramBoard, IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_IDETERMINISTICSOLVER_H