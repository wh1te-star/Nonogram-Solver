#ifndef VERSANO_CORE_ILINESOLVER_H
#define VERSANO_CORE_ILINESOLVER_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/NamespaceInterface/SolverInterface/BoardUpdateHandler.h"
#include "Solver/ResultEnum/LineSolverResult.h"

namespace VersaNo::Solver {

template <typename TOrientation> class ILineSolver {
  public:
    virtual ~ILineSolver() = default;
    virtual LineSolverResult solve(
      const Core::HintList &hintList,
      Core::Line<TOrientation> &line,
      IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_ILINESOLVER_H
