#ifndef DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H
#define DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Placement/Placement/Placement.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include <vector>

class DFSExhaustivePlacementPatternFinder
    : public IExhaustivePlacementPatternFinder {
public:
  DFSExhaustivePlacementPatternFinder() = default;
  virtual std::vector<Placement> find(const HintSet &hintSet,
                                      const Line &line) override;

private:
  void dfsExhaustivePlacementFind(const HintSet &hintSet, const Line &line,
                                  std::vector<Placement> &solutions);

  void dfsExhaustivePlacementFindRecursive(const HintSet &hintSet,
                                           const Line &line,
                                           std::vector<Placement> &solutions,
                                           Placement &currentPlacement,
                                           int currentHintIndex);
};

#endif
