#ifndef VERSANO_CORE_PLACEMENTCOUNTASSUMPTIONSELECTOR_H
#define VERSANO_CORE_PLACEMENTCOUNTASSUMPTIONSELECTOR_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionSelector/IAssumptionSelector.h"
#include "Solver/PlacementPatternCounter/IPlacementPatternCounter.h"

#include <vector>

namespace VersaNo::Solver {

class PlacementCountAssumptionSelector : public IAssumptionSelector {
  private:
    IPlacementPatternCounter &placementPatternCounter;
    Core::RowPlacementCountList rowPlacementCounts;
    Core::ColumnPlacementCountList columnPlacementCounts;

  public:
    PlacementCountAssumptionSelector(
      IPlacementPatternCounter &placementPatternCounter, const Core::NonogramBoard &board);

    std::unique_ptr<IAssumptionPosition>
    select(const Core::NonogramBoard &board, const AssumptionSelectionContext &context) override;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_PLACEMENTCOUNTASSUMPTIONSELECTOR_H