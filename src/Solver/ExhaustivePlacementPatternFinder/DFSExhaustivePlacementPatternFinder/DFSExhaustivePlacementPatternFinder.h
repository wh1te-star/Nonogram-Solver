#ifndef DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H
#define DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Placement/Placement/Placement.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include <vector>

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
