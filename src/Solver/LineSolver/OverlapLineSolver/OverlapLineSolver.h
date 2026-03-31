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
    OverlapLineSolver(
      ILeftmostPlacementFinder &leftmostPlacementFinder,
      IRightmostPlacementFinder &rightmostPlacementFinder);
    LineSolverResult
    solve(const HintSet &hintSet, Line &line, IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    LineSolverResult
    overlapLineSolve(const HintSet &hintSet, Line &line, IBoardUpdateHandler &boardUpdateHandler);
};

#endif