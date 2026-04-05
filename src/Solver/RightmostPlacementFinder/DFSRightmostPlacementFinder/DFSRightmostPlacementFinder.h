#ifndef VERSAN_CORE_DFSRIGHTMOSTPLACEMENTFINDER_H
#define VERSAN_CORE_DFSRIGHTMOSTPLACEMENTFINDER_H

#include "Core/AlgorithmProfiler/AlgorithmProfiler.h"
#include "Core/Placement/Placement/Placement.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"
#include "Solver/RightmostPlacementFinder/IRightmostPlacementFinder.h"

namespace VersaNo::Solver {

class DFSRightmostPlacementFinder : public IRightmostPlacementFinder {
  private:
    Core::AlgorithmProfiler profiler;

  public:
    DFSRightmostPlacementFinder() = default;
    PlacementFinderResult find(
      const Core::HintSet &hintSet,
      Core::Line &line,
      Core::Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    PlacementFinderResult dfsRightmostPlacementFind(
      const Core::HintSet &hintSet,
      const Core::Line &line,
      Core::Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler);

    PlacementFinderResult dfsRightmostPlacementFindRecursive(
      const Core::HintSet &hintSet,
      const Core::Line &line,
      Core::Placement &currentPlacement,
      int currentHintIndex,
      Core::Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler);
};

} // namespace VersaNo::Solver

#endif // VERSAN_CORE_DFSRIGHTMOSTPLACEMENTFINDER_H
