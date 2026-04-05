#ifndef VERSAN_CORE_DPPLACEMENTPATTERNCOUNTER_H
#define VERSAN_CORE_DPPLACEMENTPATTERNCOUNTER_H

#include "Solver/PlacementPatternCounter/IPlacementPatternCounter.h"

namespace VersaNo::Solver {

class DPPlacementPatternCounter : public IPlacementPatternCounter {
    const int MAX_COUNT = 1000000000;

  public:
    DPPlacementPatternCounter();
    DPPlacementPatternCounter(int MAX_COUNT);
    PlacementPatternCounterResult count(
      const Core::HintSet &hintSet,
      Core::Line &line,
      Core::PlacementCount &placementCount,
      IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    PlacementPatternCounterResult DPPlacementPatternCount(
      const Core::HintSet &hintSet,
      const Core::Line &line,
      Core::PlacementCount &placementCount,
      IBoardUpdateHandler &boardUpdateHandler);

    bool isSeparated(const Core::Line &line, const Core::CellIndex &prevCellIndex);

    bool isBlockFits(
      const Core::Line &line,
      const Core::CellIndex &blockStart,
      const Core::HintNumber &hintNumber);
};

} // namespace VersaNo::Solver

#endif // VERSAN_CORE_DPPLACEMENTPATTERNCOUNTER_H
