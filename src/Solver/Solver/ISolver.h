#ifndef ISOLVER_H
#define ISOLVER_H

#include "Board/NonogramBoard/NonogramBoard.h"

class ISolver {
public:
  virtual ~ISolver();
  virtual void solve(
    NonogramBoard& nonogramBoard
  ) = 0;
};

#endif