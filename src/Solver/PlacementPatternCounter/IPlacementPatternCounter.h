#ifndef VERSANO_CORE_IPLACEMENTPATTERNCOUNTER_H
#define VERSANO_CORE_IPLACEMENTPATTERNCOUNTER_H

#include "Core/NamespaceInterface/SolverInterface/BoardUpdateHandler.h"
#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/ResultEnum/PlacementPatternCounterResult.h"

namespace VersaNo::Solver {

template <typename TOrientation> class IPlacementPatternCounter {
  public:
    IPlacementPatternCounter() = default;
    virtual PlacementPatternCounterResult count(
      const Core::HintList &hintList,
      Core::Line<TOrientation> &line,
      Core::PlacementCount &placementCount,
      Core::IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_IPLACEMENTPATTERNCOUNTER_H
