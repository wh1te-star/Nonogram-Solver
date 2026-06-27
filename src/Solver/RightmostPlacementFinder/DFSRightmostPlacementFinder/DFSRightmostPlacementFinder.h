#ifndef VERSANO_CORE_DFSRIGHTMOSTPLACEMENTFINDER_H
#define VERSANO_CORE_DFSRIGHTMOSTPLACEMENTFINDER_H

#include "Core/AlgorithmProfiler/AlgorithmProfiler.h"
#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/ResultEnum/PlacementFinderResult.h"
#include "Solver/RightmostPlacementFinder/IRightmostPlacementFinder.h"

namespace VersaNo::Solver {

template <typename TOrientation>
class DFSRightmostPlacementFinder : public IRightmostPlacementFinder<TOrientation> {
  private:
    Core::AlgorithmProfiler profiler;

  public:
    DFSRightmostPlacementFinder() = default;
    PlacementFinderResult find(
      const Core::HintList &hintList,
      typename Core::LineTraits<TOrientation>::Line &line,
      typename Core::LineTraits<TOrientation>::Placement &resultPlacement,
      Core::IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    PlacementFinderResult dfsRightmostPlacementFind(
      const Core::HintList &hintList,
      const typename Core::LineTraits<TOrientation>::Line &line,
      typename Core::LineTraits<TOrientation>::Placement &resultPlacement,
      Core::IBoardUpdateHandler &boardUpdateHandler);

    PlacementFinderResult dfsRightmostPlacementFindRecursive(
      const Core::HintList &hintList,
      const typename Core::LineTraits<TOrientation>::Line &line,
      typename Core::LineTraits<TOrientation>::Placement &currentPlacement,
      Core::HintIndex currentHintIndex,
      typename Core::LineTraits<TOrientation>::Placement &resultPlacement,
      Core::IBoardUpdateHandler &boardUpdateHandler);
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_DFSRIGHTMOSTPLACEMENTFINDER_H
