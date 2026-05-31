#ifndef VERSANO_CORE_DFSLEFTMOSTPLACEMENTFINDER_H
#define VERSANO_CORE_DFSLEFTMOSTPLACEMENTFINDER_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/AlgorithmProfiler/AlgorithmProfiler.h"
#include "Solver/LeftMostPlacementFinder/ILeftMostPlacementFinder.h"

namespace VersaNo::Solver {

  template <typename TOrientation>
class DFSLeftmostPlacementFinder : public ILeftmostPlacementFinder<TOrientation> {
  private:
    Core::AlgorithmProfiler profiler;

  public:
    DFSLeftmostPlacementFinder() = default;
    PlacementFinderResult find(
      const Core::HintList &hintList,
      Core::Line<TOrientation> &line,
      Core::Placement<TOrientation> &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    PlacementFinderResult dfsLeftmostPlacementFind(
      const Core::HintList &hintList,
      Core::Line<TOrientation> &line,
      Core::Placement<TOrientation> &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler);

    PlacementFinderResult dfsLeftmostPlacementFindRecursive(
      const Core::HintList &hintList,
      const Core::Line<TOrientation> &line,
      Core::Placement<TOrientation> &currentPlacement,
      int currentHintIndex,
      Core::Placement<TOrientation> &resultPlacement,
      IBoardUpdateHandler &boardUpdateHandler);
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_DFSLEFTMOSTPLACEMENTFINDER_H
