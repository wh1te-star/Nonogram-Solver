#ifndef VERSANO_CORE_DFSRIGHTMOSTPLACEMENTFINDER_H
#define VERSANO_CORE_DFSRIGHTMOSTPLACEMENTFINDER_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/AlgorithmProfiler/AlgorithmProfiler.h"
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
      Core::Line<TOrientation> &line,
      Core::Placement<TOrientation> &resultPlacement,
      Core::IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    PlacementFinderResult dfsRightmostPlacementFind(
      const Core::HintList &hintList,
      const Core::Line<TOrientation> &line,
      Core::Placement<TOrientation> &resultPlacement,
      Core::IBoardUpdateHandler &boardUpdateHandler);

    PlacementFinderResult dfsRightmostPlacementFindRecursive(
      const Core::HintList &hintList,
      const Core::Line<TOrientation> &line,
      Core::Placement<TOrientation> &currentPlacement,
      int currentHintIndex,
      Core::Placement<TOrientation> &resultPlacement,
      Core::IBoardUpdateHandler &boardUpdateHandler);
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_DFSRIGHTMOSTPLACEMENTFINDER_H
