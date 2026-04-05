#ifndef VERSAN_CORE_IEXHAUSTIVEPLACEMENTPATTERNFINDER_H
#define VERSAN_CORE_IEXHAUSTIVEPLACEMENTPATTERNFINDER_H

#include "Core/Board/Line/Line.h"
#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Placement/Placement/Placement.h"
#include "Solver/ResultEnum/ExhaustivePlacementPatternFinderResult.h"

#include <vector>

namespace VersaNo::Solver {

class IExhaustivePlacementPatternFinder {
  public:
    IExhaustivePlacementPatternFinder() = default;
    virtual ExhaustivePlacementPatternFinderResult find(
      const Core::HintSet &hintSet,
      const Core::Line &line,
      std::vector<Core::Placement> &solutions) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSAN_CORE_IEXHAUSTIVEPLACEMENTPATTERNFINDER_H