#ifndef DPPLACEMENTPATTERNCOUNTER_H
#define DPPLACEMENTPATTERNCOUNTER_H

#include "Solver/PlacementPatternCounter/IPlacementPatternCounter.h"

class DPPlacementPatternCounter : public IPlacementPatternCounter {
  const int MAX_COUNT = 1000000000;
public:
  DPPlacementPatternCounter();
  DPPlacementPatternCounter(int MAX_COUNT);
  PlacementCount count(const HintSet &hintSet, Line &line) override;

private:
  PlacementCount DPPlacementPatternCount(const HintSet &hintSet,
                                         const Line &line);

  bool isSeparated(const Line &line, const CellIndex &prevCellIndex);

  bool isBlockFits(const Line &line, const CellIndex &blockStart,
                   const HintNumber &hintNumber);
};
#endif
