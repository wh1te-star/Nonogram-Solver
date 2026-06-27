#ifndef VERSANO_CORE_IRIGHTMOSTPLACEMENTFINDER_H
#define VERSANO_CORE_IRIGHTMOSTPLACEMENTFINDER_H

#include "Core/NamespaceInterface/SolverInterface/IBoardUpdateHandler.h"
#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"

namespace VersaNo::Solver {

template <typename TOrientation> class IRightmostPlacementFinder {
  public:
    IRightmostPlacementFinder() = default;
    virtual PlacementFinderResult find(
      const Core::HintList &hintList,
      typename Core::LineTraits<TOrientation>::Line &line,
      typename Core::LineTraits<TOrientation>::Placement &resultPlacement,
      Core::IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_IRIGHTMOSTPLACEMENTFINDER_H
