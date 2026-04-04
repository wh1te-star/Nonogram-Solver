#ifndef ILEFTMOSTPLACEMENTFINDER_H
#define ILEFTMOSTPLACEMENTFINDER_H

#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Placement/Placement/Placement.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"
#include "Solver/IBoardUpdateHandler.h"
class Line;

class ILeftmostPlacementFinder {
  public:
    ILeftmostPlacementFinder() = default;
    virtual PlacementFinderResult find(
      const HintSet &hintSet,
      Line &line,
      Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler) = 0;
};

#endif