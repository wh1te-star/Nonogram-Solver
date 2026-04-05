#ifndef VERSAN_CORE_IPLACEMENTPATTERNCOUNTER_H
#define VERSAN_CORE_IPLACEMENTPATTERNCOUNTER_H

#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Placement/PlacementCount/PlacementCount.h"
#include "Solver/IBoardUpdateHandler.h"
#include "Solver/ResultEnum/PlacementPatternCounterResult.h"

namespace VersaN::Core {
class Line;
}

namespace VersaN::Solver {

class IPlacementPatternCounter {
  public:
    IPlacementPatternCounter() = default;
    virtual PlacementPatternCounterResult count(
      const Core::HintSet &hintSet,
      Core::Line &line,
      Core::PlacementCount &placementCount,
      IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaN::Solver

#endif // VERSAN_CORE_IPLACEMENTPATTERNCOUNTER_H
