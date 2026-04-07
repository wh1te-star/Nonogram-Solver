#ifndef VERSANO_CORE_DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H
#define VERSANO_CORE_DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H

#include "Core/Hint/HintList/HintList.h"
#include "Core/Placement/Placement/Placement.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"

#include <vector>

namespace VersaNo::Core {
class Line;
}

namespace VersaNo::Solver {

class DFSExhaustivePlacementPatternFinder : public IExhaustivePlacementPatternFinder {
  public:
    DFSExhaustivePlacementPatternFinder() = default;
    virtual ExhaustivePlacementPatternFinderResult find(
      const Core::HintList &hintList,
      const Core::Line &line,
      std::vector<Core::Placement> &solutions) override;

  private:
    ExhaustivePlacementPatternFinderResult dfsExhaustivePlacementFind(
      const Core::HintList &hintList,
      const Core::Line &line,
      std::vector<Core::Placement> &solutions);

    ExhaustivePlacementPatternFinderResult dfsExhaustivePlacementFindRecursive(
      const Core::HintList &hintList,
      const Core::Line &line,
      std::vector<Core::Placement> &solutions,
      Core::Placement &currentPlacement,
      int currentHintIndex);
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H
