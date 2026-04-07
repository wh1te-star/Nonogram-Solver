#ifndef VERSANO_CORE_OVERLAPLINESOLVER_H
#define VERSANO_CORE_OVERLAPLINESOLVER_H

#include "Solver/LeftmostPlacementFinder/ILeftmostPlacementFinder.h"
#include "Solver/LineSolver/ILineSolver.h"
#include "Solver/RightmostPlacementFinder/IRightmostPlacementFinder.h"

namespace VersaNo::Solver {

class OverlapLineSolver : public ILineSolver {
  private:
    ILeftmostPlacementFinder &leftmostPlacementFinder;
    IRightmostPlacementFinder &rightmostPlacementFinder;

  public:
    OverlapLineSolver(
      ILeftmostPlacementFinder &leftmostPlacementFinder,
      IRightmostPlacementFinder &rightmostPlacementFinder);
    LineSolverResult solve(
      const Core::HintList &hintList,
      Core::Line &line,
      IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    LineSolverResult overlapLineSolve(
      const Core::HintList &hintList, Core::Line &line, IBoardUpdateHandler &boardUpdateHandler);
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_OVERLAPLINESOLVER_H