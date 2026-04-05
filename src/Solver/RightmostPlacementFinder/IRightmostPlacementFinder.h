#ifndef VERSANO_CORE_IRIGHTMOSTPLACEMENTFINDER_H
#define VERSANO_CORE_IRIGHTMOSTPLACEMENTFINDER_H

#include "Core/Board/Line/Line.h"
#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Placement/Placement/Placement.h"
#include "Solver/IBoardUpdateHandler.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"

namespace VersaNo::Solver {

class IRightmostPlacementFinder {
  public:
    IRightmostPlacementFinder() = default;
    virtual PlacementFinderResult find(
      const Core::HintSet &hintSet,
      Core::Line &line,
      Core::Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_IRIGHTMOSTPLACEMENTFINDER_H
