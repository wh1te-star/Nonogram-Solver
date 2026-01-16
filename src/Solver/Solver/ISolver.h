#ifndef ISOLVER_H
#define ISOLVER_H

#include "Shared/SharedDataAliases.h"
#include "Board/BacktrackBoard/BacktrackBoard.h"

class ISolver {
public:
  virtual ~ISolver();
  virtual void solve(
    SharedBacktrackBoard &sharedBacktrackBoard,
    BacktrackBoard &backtrackBoard,
    std::vector<Board>& solutions 
  ) = 0;
};

#endif