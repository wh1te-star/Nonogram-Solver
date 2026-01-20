#ifndef IDETERMINISTICSOLVER_H
#define IDETERMINISTICSOLVER_H

#include "Shared/SharedDataAliases.h"
#include "Board/BacktrackBoard/BacktrackBoard.h"

class IDeterministicSolver {
public:
  virtual ~IDeterministicSolver() = default;
  virtual bool solve(ISender<BacktrackBoard> &sharedBacktrackBoard,
                     BacktrackBoard &backtrackBoard) = 0;
};

#endif