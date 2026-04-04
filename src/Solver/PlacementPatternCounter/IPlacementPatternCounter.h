#ifndef IPLACEMENTPATTERNCOUNTER_H
#define IPLACEMENTPATTERNCOUNTER_H

#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Placement/PlacementCount/PlacementCount.h"
#include "Solver/ResultEnum/PlacementPatternCounterResult.h"
#include "Solver/IBoardUpdateHandler.h"
class Line;

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

