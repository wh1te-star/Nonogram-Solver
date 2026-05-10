#ifndef VERSANO_CORE_IEXHAUSTIVEPLACEMENTPATTERNFINDER_H
#define VERSANO_CORE_IEXHAUSTIVEPLACEMENTPATTERNFINDER_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Hint/HintList/HintList.h"
#include "Solver/ResultEnum/ExhaustivePlacementPatternFinderResult.h"

#include <vector>

namespace VersaNo::Solver {

class IExhaustivePlacementPatternFinder {
  public:
    IExhaustivePlacementPatternFinder() = default;
    virtual ExhaustivePlacementPatternFinderResult find(
      const Core::HintList &hintList,
      const Core::Line &line,
      std::vector<Core::Placement> &solutions) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_IEXHAUSTIVEPLACEMENTPATTERNFINDER_H