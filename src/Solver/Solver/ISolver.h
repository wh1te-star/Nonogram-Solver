#ifndef ISOLVER_H
#define ISOLVER_H

#include "Board/NonogramBoard/NonogramBoard.h"
#include "Shared/SharedDataAliases.h"
#include "Solver/IBoardUpdateHandler.h"

class ISolver {
  public:
    virtual ~ISolver() = default;
    virtual void solve(
      NonogramBoard &nonogramBoard,
      std::vector<Board> &solutions,
      IBoardUpdateHandler &boardUpdateHandler) = 0;
};

#endif