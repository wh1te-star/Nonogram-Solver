#ifndef VERSANO_CORE_OVERLAPLINESOLVER_H
#define VERSANO_CORE_OVERLAPLINESOLVER_H

#include "Core/Types/AppliedType/AppliedType.h"
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
      typename Core::LineTraits<TOrientation>::Line &line,
      Core::IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    LineSolverResult overlapLineSolve(
      const Core::HintList &hintList,
      typename Core::LineTraits<TOrientation>::Line &line,
      Core::IBoardUpdateHandler &boardUpdateHandler);
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_OVERLAPLINESOLVER_H