#ifndef ILEFTMOSTPLACEMENTFINDER_H
#define ILEFTMOSTPLACEMENTFINDER_H

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Placement/Placement/Placement.h"
#include <vector>

class IExhaustivePlacementPatternFinder {
public:
  IExhaustivePlacementPatternFinder() = default;
  virtual std::vector<Placement> find(const HintSet &hintSet, const Line &line) = 0;
};

#endif