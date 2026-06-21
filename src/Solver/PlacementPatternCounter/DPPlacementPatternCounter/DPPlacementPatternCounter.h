#ifndef VERSANO_CORE_DPPLACEMENTPATTERNCOUNTER_H
#define VERSANO_CORE_DPPLACEMENTPATTERNCOUNTER_H

#include "Solver/PlacementPatternCounter/IPlacementPatternCounter.h"

namespace VersaNo::Solver {

template <typename TOrientation>
class DPPlacementPatternCounter : public IPlacementPatternCounter<TOrientation> {
    const int MAX_COUNT = 1000000000;

  public:
    DPPlacementPatternCounter();
    DPPlacementPatternCounter(int MAX_COUNT);
    PlacementPatternCounterResult count(
      const Core::HintList &hintList,
      Core::Line<TOrientation> &line,
      Core::PlacementCount &placementCount,
      Core::IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    PlacementPatternCounterResult DPPlacementPatternCount(
      const Core::HintList &hintList,
      const Core::Line<TOrientation> &line,
      Core::PlacementCount &placementCount,
      Core::IBoardUpdateHandler &boardUpdateHandler);

    bool isSeparated(
      const Core::Line<typename Core::LineTraits<TOrientation>::PeerIndex> &line,
      const typename Core::LineTraits<TOrientation>::PeerIndex &prevCellIndex);

    bool isBlockFits(
      const Core::Line<typename Core::LineTraits<TOrientation>::PeerIndex> &line,
      const typename Core::LineTraits<TOrientation>::PeerIndex &blockStart,
      const Core::HintNumber &hintNumber);
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_DPPLACEMENTPATTERNCOUNTER_H
