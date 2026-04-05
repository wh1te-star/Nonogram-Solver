#ifndef VERSAN_CORE_ILEFTMOSTPLACEMENTFINDER_H
#define VERSAN_CORE_ILEFTMOSTPLACEMENTFINDER_H

#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Placement/Placement/Placement.h"
#include "Solver/IBoardUpdateHandler.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"
namespace VersaN::Core {
class Line;
}

namespace VersaN::Solver {

class ILeftmostPlacementFinder {
  public:
    ILeftmostPlacementFinder() = default;
    virtual PlacementFinderResult find(
      const Core::HintSet &hintSet,
      Core::Line &line,
      Core::Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaN::Solver

#endif // VERSAN_CORE_ILEFTMOSTPLACEMENTFINDER_H