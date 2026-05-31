#ifndef VERSANO_CORE_OVERLAPLINESOLVER_H
#define VERSANO_CORE_OVERLAPLINESOLVER_H

#include "Solver/LeftmostPlacementFinder/ILeftmostPlacementFinder.h"
#include "Solver/LineSolver/ILineSolver.h"
#include "Solver/RightmostPlacementFinder/IRightmostPlacementFinder.h"

namespace VersaNo::Solver {

template <typename TOrientation> class OverlapLineSolver : public ILineSolver<TOrientation> {
  private:
    ILeftmostPlacementFinder<TOrientation> &leftmostPlacementFinder;
    IRightmostPlacementFinder<TOrientation> &rightmostPlacementFinder;

  public:
    OverlapLineSolver(
      ILeftmostPlacementFinder<TOrientation> &leftmostPlacementFinder,
      IRightmostPlacementFinder<TOrientation> &rightmostPlacementFinder);
    LineSolverResult solve(
      const Core::HintList &hintList,
      Core::Line<TOrientation> &line,
      IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    LineSolverResult overlapLineSolve(
      const Core::HintList &hintList,
      Core::Line<TOrientation> &line,
      IBoardUpdateHandler &boardUpdateHandler);
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_OVERLAPLINESOLVER_H