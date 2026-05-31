#ifndef VERSANO_CORE_IEXHAUSTIVEPLACEMENTPATTERNFINDER_H
#define VERSANO_CORE_IEXHAUSTIVEPLACEMENTPATTERNFINDER_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/ResultEnum/ExhaustivePlacementPatternFinderResult.h"

#include <vector>

namespace VersaNo::Solver {

template <typename TOrientation> class IExhaustivePlacementPatternFinder {
  public:
    IExhaustivePlacementPatternFinder() = default;
    virtual ExhaustivePlacementPatternFinderResult find(
      const Core::HintList &hintList,
      const Core::Line<TOrientation> &line,
      std::vector<Core::Placement<TOrientation>> &solutions) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_IEXHAUSTIVEPLACEMENTPATTERNFINDER_H