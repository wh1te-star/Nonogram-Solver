#ifndef IRIGHTMOSTPLACEMENTFINDER_H
#define IRIGHTMOSTPLACEMENTFINDER_H

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Placement/Placement/Placement.h"

class IRightmostPlacementFinder {
public:
  IRightmostPlacementFinder() = default;
  virtual Placement find(
    const HintSet& hintSet,
    Line& line
  ) = 0;
};

#endif
