#ifndef VERSANO_CORE_IPLACEMENTPATTERNCOUNTER_H
#define VERSANO_CORE_IPLACEMENTPATTERNCOUNTER_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Hint/HintList/HintList.h"
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
      const Core::HintList &hintList,
      Core::Line &line,
      Core::PlacementCount &placementCount,
      IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_IPLACEMENTPATTERNCOUNTER_H
