#ifndef OVERLAPLINESOLVER_H
#define OVERLAPLINESOLVER_H

#include "Solver/LineSolver/ILineSolver.h"

class OverlapLineSolver : public ILineSolver{
public:
  OverlapLineSolver() = default;
  virtual bool solve(
    const HintSet& hintSet,
    Line& line
  ) = 0;

private:
  bool overlapLineSolve(
    const HintSet& hintSet,
    Line& line
  );
};

#endif