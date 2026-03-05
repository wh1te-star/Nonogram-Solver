#ifndef IRIGHTMOSTPLACEMENTFINDER_H
#define IRIGHTMOSTPLACEMENTFINDER_H

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Placement/Placement/Placement.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"

class IRightmostPlacementFinder {
public:
  IRightmostPlacementFinder() = default;
  virtual PlacementFinderResult find(
    const HintSet& hintSet,
    Line& line,
    Placement& resultPlacement
  ) = 0;
};

#endif
