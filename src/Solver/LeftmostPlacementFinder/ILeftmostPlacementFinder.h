#ifndef ILEFTMOSTPLACEMENTFINDER_H
#define ILEFTMOSTPLACEMENTFINDER_H

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"

class ILeftMostPlacementFinder {
public:
  ILeftMostPlacementFinder() = default;
  virtual Placement find(
    const HintSet& hintSet,
    Line& line
  ) = 0;
};

#endif