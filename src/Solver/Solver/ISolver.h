#ifndef ISOLVER_H
#define ISOLVER_H

#include "Board/NonogramBoard/NonogramBoard.h"
#include "Shared/SharedDataAliases.h"

class ISolver {
public:
  virtual ~ISolver() = default;
  virtual void solve(ISender<NonogramBoard> &nonogramBoardSender,
                     NonogramBoard &nonogramBoard,
                     std::vector<Board> &solutions) = 0;
};

#endif