#ifndef VERSAN_CORE_DFSLEFTMOSTPLACEMENTFINDER_H
#define VERSAN_CORE_DFSLEFTMOSTPLACEMENTFINDER_H

#include "Core/AlgorithmProfiler/AlgorithmProfiler.h"
#include "Core/Placement/Placement/Placement.h"
#include "Solver/LeftMostPlacementFinder/ILeftMostPlacementFinder.h"

namespace VersaN::Solver {

class DFSLeftmostPlacementFinder : public ILeftmostPlacementFinder {
  private:
    Core::AlgorithmProfiler profiler;

  public:
    DFSLeftmostPlacementFinder() = default;
    PlacementFinderResult find(
      const Core::HintSet &hintSet,
      Core::Line &line,
      Core::Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    PlacementFinderResult dfsLeftmostPlacementFind(
      const Core::HintSet &hintSet,
      Core::Line &line,
      Core::Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler);

    PlacementFinderResult dfsLeftmostPlacementFindRecursive(
      const Core::HintSet &hintSet,
      const Core::Line &line,
      Core::Placement &currentPlacement,
      int currentHintIndex,
      Core::Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler);
};

} // namespace VersaN::Solver

#endif // VERSAN_CORE_DFSLEFTMOSTPLACEMENTFINDER_H
