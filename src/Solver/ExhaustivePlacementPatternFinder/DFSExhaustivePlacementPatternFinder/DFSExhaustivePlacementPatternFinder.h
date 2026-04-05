#ifndef VERSAN_CORE_DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H
#define VERSAN_CORE_DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H

#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Placement/Placement/Placement.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"

#include <vector>

namespace VersaN::Core {
class Line;
}

namespace VersaN::Solver {

class DFSExhaustivePlacementPatternFinder : public IExhaustivePlacementPatternFinder {
  public:
    DFSExhaustivePlacementPatternFinder() = default;
    virtual ExhaustivePlacementPatternFinderResult
    find(const Core::HintSet &hintSet, const Core::Line &line, std::vector<Core::Placement> &solutions) override;

  private:
    ExhaustivePlacementPatternFinderResult dfsExhaustivePlacementFind(
      const Core::HintSet &hintSet, const Core::Line &line, std::vector<Core::Placement> &solutions);

    ExhaustivePlacementPatternFinderResult dfsExhaustivePlacementFindRecursive(
      const Core::HintSet &hintSet,
      const Core::Line &line,
      std::vector<Core::Placement> &solutions,
      Core::Placement &currentPlacement,
      int currentHintIndex);
};

} // namespace VersaN::Solver

#endif // VERSAN_CORE_DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H
