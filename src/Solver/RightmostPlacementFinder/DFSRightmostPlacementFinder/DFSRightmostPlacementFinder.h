#ifndef DFSRIGHTMOSTPLACEMENTFINDER_H
#define DFSRIGHTMOSTPLACEMENTFINDER_H

#include "Placement/Placement/Placement.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"
#include "Solver/RightmostPlacementFinder/IRightmostPlacementFinder.h"
#include "AlgorithmProfiler/AlgorithmProfiler.h"

class DFSRightmostPlacementFinder : public IRightmostPlacementFinder {
  private:
    AlgorithmProfiler profiler;

  public:
    DFSRightmostPlacementFinder() = default;
    PlacementFinderResult
    find(const HintSet &hintSet, Line &line, Placement &resultPlacement, IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    PlacementFinderResult
    dfsRightmostPlacementFind(const HintSet &hintSet, const Line &line, Placement &resultPlacement, IBoardUpdateHandler &boardUpdateHandler);

    PlacementFinderResult dfsRightmostPlacementFindRecursive(
      const HintSet &hintSet,
      const Line &line,
      Placement &currentPlacement,
      int currentHintIndex,
      Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler);
};

#endif
