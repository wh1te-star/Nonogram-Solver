#ifndef IDETERMINISTICSOLVER_H
#define IDETERMINISTICSOLVER_H

#include "Board/NonogramBoard/NonogramBoard.h"

class IDeterministicSolver {
public:
  virtual ~IDeterministicSolver() = default;
  virtual bool solve(
    NonogramBoard& nonogramBoard
  ) = 0;
};

#endif