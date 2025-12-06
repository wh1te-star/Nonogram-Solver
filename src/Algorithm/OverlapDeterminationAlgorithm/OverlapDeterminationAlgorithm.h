#ifndef OVERLAPPATTERNCOUNTALGORITHM_H
#define OVERLAPPATTERNCOUNTALGORITHM_H

#include "Board/Line/Column.h"
#include "Cell/Cell/Cell.h"
#include "Hint/HintSet/HintSet.h"
#include "Placement/Placement/ColumnPlacement.h"
#include <vector>

class OverlapDeterminationAlgorithm {
public:
  static Line run(const Line &line, const HintSet &HintSet);

  static Line determineByOverlap(const Line &line, const HintSet &HintSet);
};

#endif
