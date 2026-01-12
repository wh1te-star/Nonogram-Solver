#ifndef OVERLAPLINESOLVER_H
#define OVERLAPLINESOLVER_H

#include "Solver/LeftmostPlacementFinder/ILeftmostPlacementFinder.h"
#include "Solver/LineSolver/ILineSolver.h"
#include "Solver/RightmostPlacementFinder/IRightmostPlacementFinder.h"

class OverlapLineSolver : public ILineSolver {
private:
  ILeftmostPlacementFinder &leftmostPlacementFinder;
  IRightmostPlacementFinder &rightmostPlacementFinder;

public:
  OverlapLineSolver(ILeftmostPlacementFinder &leftmostPlacementFinder,
                    IRightmostPlacementFinder &rightmostPlacementFinder);
  bool solve(const HintSet &hintSet, Line &line) override;

private:
  bool overlapLineSolve(const HintSet &hintSet, Line &line);
};

#endif