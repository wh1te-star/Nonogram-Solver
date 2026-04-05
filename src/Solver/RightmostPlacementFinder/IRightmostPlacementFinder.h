#ifndef VERSAN_CORE_IRIGHTMOSTPLACEMENTFINDER_H
#define VERSAN_CORE_IRIGHTMOSTPLACEMENTFINDER_H

#include "Core/Board/Line/Line.h"
#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Placement/Placement/Placement.h"
#include "Solver/IBoardUpdateHandler.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"

namespace VersaN::Solver {

class IRightmostPlacementFinder {
  public:
    IRightmostPlacementFinder() = default;
    virtual PlacementFinderResult find(
      const Core::HintSet &hintSet,
      Core::Line &line,
      Core::Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaN::Solver

#endif // VERSAN_CORE_IRIGHTMOSTPLACEMENTFINDER_H
