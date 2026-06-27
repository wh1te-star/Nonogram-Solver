#ifndef VERSANO_CORE_ILEFTMOSTPLACEMENTFINDER_H
#define VERSANO_CORE_ILEFTMOSTPLACEMENTFINDER_H

#include "Core/NamespaceInterface/SolverInterface/BoardUpdateHandler.h"
#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"


namespace VersaNo::Solver {

template <typename TOrientation> class ILeftmostPlacementFinder {
  public:
    ILeftmostPlacementFinder() = default;
    virtual PlacementFinderResult find(
      const Core::HintList &hintList,
      typename Core::LineTraits<TOrientation>::Line &line,
      typename Core::LineTraits<TOrientation>::Placement &resultPlacement,
      Core::IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_ILEFTMOSTPLACEMENTFINDER_H