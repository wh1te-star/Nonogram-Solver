#ifndef IPLACEMENTPATTERNCOUNTER_H
#define IPLACEMENTPATTERNCOUNTER_H

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Placement/PlacementCount/PlacementCount.h"
#include "Solver/ResultEnum/PlacementPatternCounterResult.h"
#include "Solver/IBoardUpdateHandler.h"

class IPlacementPatternCounter {
public:
  IPlacementPatternCounter() = default;
  virtual PlacementPatternCounterResult count(
    const HintSet& hintSet,
    Line& line,
    PlacementCount& placementCount,
    IBoardUpdateHandler& boardUpdateHandler
  ) = 0;
};

#endif

