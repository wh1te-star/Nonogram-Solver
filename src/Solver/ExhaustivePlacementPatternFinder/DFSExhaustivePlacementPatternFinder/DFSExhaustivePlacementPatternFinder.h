#ifndef VERSANO_CORE_DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H
#define VERSANO_CORE_DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"

#include <vector>

namespace VersaNo::Solver {

template <typename TOrientation>
class DFSExhaustivePlacementPatternFinder : public IExhaustivePlacementPatternFinder<TOrientation> {
  public:
    DFSExhaustivePlacementPatternFinder() = default;
    virtual ExhaustivePlacementPatternFinderResult find(
      const Core::HintList &hintList,
      const Core::Line<TOrientation> &line,
      std::vector<Core::Placement<TOrientation>> &solutions) override;

  private:
    ExhaustivePlacementPatternFinderResult dfsExhaustivePlacementFind(
      const Core::HintList &hintList,
      const Core::Line<TOrientation> &line,
      std::vector<Core::Placement<TOrientation>> &solutions);

    ExhaustivePlacementPatternFinderResult dfsExhaustivePlacementFindRecursive(
      const Core::HintList &hintList,
      const Core::Line<TOrientation> &line,
      std::vector<Core::Placement<TOrientation>> &solutions,
      Core::Placement<TOrientation> &currentPlacement,
      int currentHintIndex);
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_DFSEXHAUSTIVEPLACEMENTPATTERNFINDER_H
