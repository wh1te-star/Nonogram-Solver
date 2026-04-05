#ifndef VERSANO_CORE_ILEFTMOSTPLACEMENTFINDER_H
#define VERSANO_CORE_ILEFTMOSTPLACEMENTFINDER_H

#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Placement/Placement/Placement.h"
#include "Solver/IBoardUpdateHandler.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"
namespace VersaNo::Core {
class Line;
}

namespace VersaNo::Solver {

class ILeftmostPlacementFinder {
  public:
    ILeftmostPlacementFinder() = default;
    virtual PlacementFinderResult find(
      const Core::HintSet &hintSet,
      Core::Line &line,
      Core::Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_ILEFTMOSTPLACEMENTFINDER_H