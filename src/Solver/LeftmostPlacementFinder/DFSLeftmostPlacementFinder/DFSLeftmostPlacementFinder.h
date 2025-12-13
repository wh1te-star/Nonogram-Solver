#ifndef DFSLEFTMOSTPLACEMENTFINDER_H
#define DFSLEFTMOSTPLACEMENTFINDER_H

#include "Placement/Placement/Placement.h"
#include "Solver/LeftMostPlacementFinder/ILeftMostPlacementFinder.h"

class DFSLeftmostPlacementFinder : public ILeftMostPlacementFinder {
public:
    enum class DFSResult {
        Found,
        NotFound
    };

public:
  DFSLeftmostPlacementFinder() = default;
  bool find(
    const HintSet& hintSet,
    Line& line
  ) override;

private:
  bool dfsLeftmostPlacementFind(
    const HintSet& hintSet,
    Line& line
  );

  bool dfsLeftmostPlacementFindRecursive(
    const HintSet& hintSet,
    Line& line,
    Placement &currentPlacement,
    int currentHintIndex
  );
};

#endif
