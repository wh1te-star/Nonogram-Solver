#ifndef IEXHAUSTIVEPLACEMENTPATTERNFINDER_H
#define IEXHAUSTIVEPLACEMENTPATTERNFINDER_H

#include "Core/Board/Line/Line.h"
#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Placement/Placement/Placement.h"
#include "Solver/ResultEnum/ExhaustivePlacementPatternFinderResult.h"
#include <vector>

class IExhaustivePlacementPatternFinder {
public:
  IExhaustivePlacementPatternFinder() = default;
  virtual ExhaustivePlacementPatternFinderResult find(const HintSet &hintSet, const Line &line, std::vector<Placement> &solutions) = 0;
};

#endif