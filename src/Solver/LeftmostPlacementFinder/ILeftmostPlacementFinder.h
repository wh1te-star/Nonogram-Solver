#ifndef ILEFTMOSTPLACEMENTFINDER_H
#define ILEFTMOSTPLACEMENTFINDER_H

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Placement/Placement/Placement.h"

class ILeftmostPlacementFinder {
public:
  ILeftmostPlacementFinder() = default;
  virtual Placement find(const HintSet &hintSet, Line &line) = 0;
};

#endif