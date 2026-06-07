#ifndef VERSANO_CORE_LINEINDEXASSUMPTIONSELECTOR_H
#define VERSANO_CORE_LINEINDEXASSUMPTIONSELECTOR_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionSelector/IAssumptionSelector.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"

namespace VersaNo::Solver {

template <typename TOrientation>
class LineIndexAssumptionSelector : public IAssumptionSelector {
  public:
    LineIndexAssumptionSelector();
    std::unique_ptr<IAssumptionPosition>
    select(const Core::NonogramBoard &board, const AssumptionSelectionContext &context) override;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_LINEINDEXASSUMPTIONSELECTOR_H