#ifndef DFSLEFTMOSTPLACEMENTFINDER_H
#define DFSLEFTMOSTPLACEMENTFINDER_H

#include "Placement/Placement/Placement.h"
#include "Solver/LeftMostPlacementFinder/ILeftMostPlacementFinder.h"

class DFSLeftmostPlacementFinder : public ILeftmostPlacementFinder {
public:
  DFSLeftmostPlacementFinder() = default;
  Placement find(const HintSet &hintSet, Line &line) override;

private:
  Placement dfsLeftmostPlacementFind(const HintSet &hintSet, Line &line);

  Placement dfsLeftmostPlacementFindRecursive(const HintSet &hintSet,
                                              Line &line,
                                              Placement &currentPlacement,
                                              int currentHintIndex);
};

#endif
