#include "Algorithm/OverlapDeterminationAlgorithm/OverlapDeterminationAlgorithm.h"

#include "Algorithm/FindLeftMostPlacementAlgorithm/FindLeftMostPlacementAlgorithm.h"
#include "Algorithm/FindRightMostPlacementAlgorithm/FindRightMostPlacementAlgorithm.h"
#include "Board/Line/Line.h"

Line OverlapDeterminationAlgorithm::run(const Line &line,
                                        const HintSet &HintSet) {
  return determineByOverlap(line, HintSet);
}

Line OverlapDeterminationAlgorithm::determineByOverlap(const Line &line,
                                                       const HintSet &HintSet) {
}
