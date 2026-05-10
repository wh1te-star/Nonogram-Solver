#ifndef VERSANO_CORE_IRIGHTMOSTPLACEMENTFINDER_H
#define VERSANO_CORE_IRIGHTMOSTPLACEMENTFINDER_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Hint/HintList/HintList.h"
#include "Solver/IBoardUpdateHandler.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"

namespace VersaNo::Solver {

class IRightmostPlacementFinder {
  public:
    IRightmostPlacementFinder() = default;
    virtual PlacementFinderResult find(
      const Core::HintList &hintList,
      Core::Line &line,
      Core::Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_IRIGHTMOSTPLACEMENTFINDER_H
