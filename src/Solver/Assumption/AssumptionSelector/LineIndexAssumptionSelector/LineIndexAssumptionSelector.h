#ifndef VERSANO_CORE_LINEINDEXASSUMPTIONSELECTOR_H
#define VERSANO_CORE_LINEINDEXASSUMPTIONSELECTOR_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionSelector/IAssumptionSelector.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"

namespace VersaNo::Solver {

class LineIndexAssumptionSelector : public IAssumptionSelector {
  private:
    Core::Orientation orientation;

  public:
    LineIndexAssumptionSelector(Core::Orientation orientation);
    std::unique_ptr<IAssumptionPosition>
    select(const Core::NonogramBoard &board, const AssumptionSelectionContext &context) override;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_LINEINDEXASSUMPTIONSELECTOR_H