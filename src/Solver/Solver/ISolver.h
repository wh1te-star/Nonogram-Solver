#ifndef VERSANO_CORE_ISOLVER_H
#define VERSANO_CORE_ISOLVER_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/NamespaceInterface/SolverInterface/BoardUpdateHandler.h"
#include "Rendering/Shared/SharedDataAliases.h"

namespace VersaNo::Solver {

class ISolver {
  public:
    virtual ~ISolver() = default;
    virtual void solve(
      Core::NonogramBoard &nonogramBoard,
      std::vector<Core::Board> &solutions,
      Core::IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_ISOLVER_H