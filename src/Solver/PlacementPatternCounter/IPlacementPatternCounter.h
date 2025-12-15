#ifndef IPLACEMENTPATTERNCOUNTER_H
#define IPLACEMENTPATTERNCOUNTER_H

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Placement/PlacementCount/PlacementCount.h"

class IPlacementPatternCounter {
public:
  IPlacementPatternCounter() = default;
  virtual PlacementCount count(
    const HintSet& hintSet,
    Line& line
  ) = 0;
};

#endif

