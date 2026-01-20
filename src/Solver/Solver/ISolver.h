#ifndef ISOLVER_H
#define ISOLVER_H

#include "Board/BacktrackBoard/BacktrackBoard.h"
#include "Shared/SharedDataAliases.h"

class ISolver {
public:
  virtual ~ISolver() = default;
  virtual void solve(ISender<BacktrackBoard> &sharedBacktrackBoard,
                     BacktrackBoard &backtrackBoard,
                     std::vector<Board> &solutions) = 0;
};

#endif