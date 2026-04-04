#ifndef IRIGHTMOSTPLACEMENTFINDER_H
#define IRIGHTMOSTPLACEMENTFINDER_H

#include "Core/Board/Line/Line.h"
#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Placement/Placement/Placement.h"
#include "Solver/IBoardUpdateHandler.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"

class IRightmostPlacementFinder {
  public:
    IRightmostPlacementFinder() = default;
    virtual PlacementFinderResult find(
      const HintSet &hintSet,
      Line &line,
      Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler) = 0;
};

#endif
