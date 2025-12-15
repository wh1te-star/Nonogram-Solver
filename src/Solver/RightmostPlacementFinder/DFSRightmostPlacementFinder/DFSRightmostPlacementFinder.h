#ifndef DFSRIGHTMOSTPLACEMENTFINDER_H
#define DFSRIGHTMOSTPLACEMENTFINDER_H

#include "Placement/Placement/Placement.h"
#include "Solver/RightmostPlacementFinder/IRightmostPlacementFinder.h"

class DFSRightmostPlacementFinder : public IRightmostPlacementFinder {
public:
  DFSRightmostPlacementFinder() = default;
  Placement find(
    const HintSet& hintSet,
    Line& line
  ) override;

private:
  Placement dfsRightmostPlacementFind(
    const HintSet& hintSet,
    const Line& line
  );

  Placement dfsRightmostPlacementFindRecursive(
    const HintSet& hintSet,
    const Line& line,
    Placement &currentPlacement,
    int currentHintIndex
  );
};

#endif
