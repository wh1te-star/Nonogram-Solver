#ifndef ILINESOLVER_H
#define ILINESOLVER_H

#include "Board/NonogramBoard/NonogramBoard.h"

class ILineSolver {
public:
  virtual ~ILineSolver();
  virtual bool solve(
    const HintSet& hintSet,
    Line& line
  ) = 0;
};

#endif
