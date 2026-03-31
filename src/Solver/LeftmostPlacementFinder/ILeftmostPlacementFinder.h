#ifndef ILEFTMOSTPLACEMENTFINDER_H
#define ILEFTMOSTPLACEMENTFINDER_H

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Placement/Placement/Placement.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"
#include "Solver/IBoardUpdateHandler.h"

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