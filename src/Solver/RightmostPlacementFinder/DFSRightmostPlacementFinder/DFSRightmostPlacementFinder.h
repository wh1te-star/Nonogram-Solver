#ifndef VERSANO_CORE_DFSRIGHTMOSTPLACEMENTFINDER_H
#define VERSANO_CORE_DFSRIGHTMOSTPLACEMENTFINDER_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/AlgorithmProfiler/AlgorithmProfiler.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"
#include "Solver/RightmostPlacementFinder/IRightmostPlacementFinder.h"

namespace VersaNo::Solver {

class DFSRightmostPlacementFinder : public IRightmostPlacementFinder {
  private:
    Core::AlgorithmProfiler profiler;

  public:
    DFSRightmostPlacementFinder() = default;
    PlacementFinderResult find(
      const Core::HintList &hintList,
      Core::Line &line,
      Core::Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    PlacementFinderResult dfsRightmostPlacementFind(
      const Core::HintList &hintList,
      const Core::Line &line,
      Core::Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler);

    PlacementFinderResult dfsRightmostPlacementFindRecursive(
      const Core::HintList &hintList,
      const Core::Line &line,
      Core::Placement &currentPlacement,
      int currentHintIndex,
      Core::Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler);
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_DFSRIGHTMOSTPLACEMENTFINDER_H
