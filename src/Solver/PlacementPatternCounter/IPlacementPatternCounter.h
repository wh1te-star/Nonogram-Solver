#ifndef VERSANO_CORE_IPLACEMENTPATTERNCOUNTER_H
#define VERSANO_CORE_IPLACEMENTPATTERNCOUNTER_H

#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Placement/PlacementCount/PlacementCount.h"
#include "Solver/IBoardUpdateHandler.h"
#include "Solver/ResultEnum/PlacementPatternCounterResult.h"

namespace VersaNo::Core {
class Line;
}

namespace VersaNo::Solver {

class IPlacementPatternCounter {
  public:
    IPlacementPatternCounter() = default;
    virtual PlacementPatternCounterResult count(
      const Core::HintSet &hintSet,
      Core::Line &line,
      Core::PlacementCount &placementCount,
      IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_IPLACEMENTPATTERNCOUNTER_H
