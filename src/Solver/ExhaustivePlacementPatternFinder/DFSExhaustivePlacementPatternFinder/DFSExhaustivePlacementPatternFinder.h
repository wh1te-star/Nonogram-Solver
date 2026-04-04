#ifndef DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H
#define DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H

#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Placement/Placement/Placement.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include <vector>
class Line;

class DFSExhaustivePlacementPatternFinder : public IExhaustivePlacementPatternFinder {
  public:
    DFSExhaustivePlacementPatternFinder() = default;
    virtual ExhaustivePlacementPatternFinderResult
    find(const HintSet &hintSet, const Line &line, std::vector<Placement> &solutions) override;

  private:
    ExhaustivePlacementPatternFinderResult dfsExhaustivePlacementFind(
      const HintSet &hintSet, const Line &line, std::vector<Placement> &solutions);

    ExhaustivePlacementPatternFinderResult dfsExhaustivePlacementFindRecursive(
      const HintSet &hintSet,
      const Line &line,
      std::vector<Placement> &solutions,
      Placement &currentPlacement,
      int currentHintIndex);
};

#endif
