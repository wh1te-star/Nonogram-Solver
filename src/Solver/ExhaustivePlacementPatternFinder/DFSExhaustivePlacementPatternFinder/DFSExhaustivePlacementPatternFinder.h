#ifndef VERSANO_CORE_DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H
#define VERSANO_CORE_DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include "Solver/ResultEnum/ExhaustivePlacementPatternFinderResult.h"

#include <vector>

namespace VersaNo::Solver {

template <typename TOrientation>
class DFSExhaustivePlacementPatternFinder : public IExhaustivePlacementPatternFinder<TOrientation> {
  public:
    DFSExhaustivePlacementPatternFinder() = default;
    virtual ExhaustivePlacementPatternFinderResult find(
      const Core::HintList &hintList,
      const typename Core::LineTraits<TOrientation>::Line &line,
      std::vector<typename Core::LineTraits<TOrientation>::Placement> &solutions) override;

  private:
    ExhaustivePlacementPatternFinderResult dfsExhaustivePlacementFind(
      const Core::HintList &hintList,
      const typename Core::LineTraits<TOrientation>::Line &line,
      std::vector<typename Core::LineTraits<TOrientation>::Placement> &solutions);

    ExhaustivePlacementPatternFinderResult dfsExhaustivePlacementFindRecursive(
      const Core::HintList &hintList,
      const typename Core::LineTraits<TOrientation>::Line &line,
      std::vector<typename Core::LineTraits<TOrientation>::Placement> &solutions,
      typename Core::LineTraits<TOrientation>::Placement &currentPlacement,
      Core::HintIndex currentHintIndex);
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H
