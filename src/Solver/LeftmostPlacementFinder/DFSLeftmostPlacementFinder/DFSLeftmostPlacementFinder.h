#ifndef DFSLEFTMOSTPLACEMENTFINDER_H
#define DFSLEFTMOSTPLACEMENTFINDER_H

#include "AlgorithmProfiler/AlgorithmProfiler.h"
#include "Placement/Placement/Placement.h"
#include "Solver/LeftMostPlacementFinder/ILeftMostPlacementFinder.h"

class DFSLeftmostPlacementFinder : public ILeftmostPlacementFinder {
  private:
    AlgorithmProfiler profiler;

  public:
    DFSLeftmostPlacementFinder() = default;
    PlacementFinderResult find(
      const HintSet &hintSet,
      Line &line,
      Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    PlacementFinderResult dfsLeftmostPlacementFind(
      const HintSet &hintSet,
      Line &line,
      Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler);

    PlacementFinderResult dfsLeftmostPlacementFindRecursive(
      const HintSet &hintSet,
      const Line &line,
      Placement &currentPlacement,
      int currentHintIndex,
      Placement &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler);
};

#endif
