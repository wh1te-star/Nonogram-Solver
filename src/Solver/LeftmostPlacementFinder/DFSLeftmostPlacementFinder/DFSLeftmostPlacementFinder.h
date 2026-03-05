#ifndef DFSLEFTMOSTPLACEMENTFINDER_H
#define DFSLEFTMOSTPLACEMENTFINDER_H

#include "Placement/Placement/Placement.h"
#include "Solver/LeftMostPlacementFinder/ILeftMostPlacementFinder.h"

class DFSLeftmostPlacementFinder : public ILeftmostPlacementFinder {
  public:
    DFSLeftmostPlacementFinder() = default;
    PlacementFinderResult
    find(const HintSet &hintSet, Line &line, Placement &resultPlacement) override;

  private:
    PlacementFinderResult
    dfsLeftmostPlacementFind(const HintSet &hintSet, Line &line, Placement &resultPlacement);

    PlacementFinderResult dfsLeftmostPlacementFindRecursive(
      const HintSet &hintSet,
      const Line &line,
      Placement &currentPlacement,
      int currentHintIndex,
      Placement &resultPlacement);
};

#endif
