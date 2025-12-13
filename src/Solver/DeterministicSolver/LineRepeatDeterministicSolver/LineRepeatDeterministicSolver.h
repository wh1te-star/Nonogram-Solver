#ifndef LINEREPEATDETERMINISTICSOLVER_H
#define LINEREPEATDETERMINISTICSOLVER_H

#include "Solver/DeterministicSolver/IDeterministicSolver.h"

class LineRepeatDeterministicSolver : public IDeterministicSolver {
public:
  LineRepeatDeterministicSolver();
  bool solve(
    NonogramBoard& nonogramBoard
  ) override;

private:
  bool lineRepeatDeterministicSolve(
    NonogramBoard& nonogramBoard
  );
};

#endif