#ifndef VERSANO_CORE_LINEASSUMPTIONENUMERATOR_H
#define VERSANO_CORE_LINEASSUMPTIONENUMERATOR_H

#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Solver/Assumption/AssumptionEnumerator/IAssumptionEnumerator.h"
#include "Solver/Assumption/AssumptionPosition/CellAssumptionPosition/CellAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/HintAssumptionPosition/HintAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"

#include <vector>

namespace VersaNo::Solver {

template <typename TOrientation> class LineAssumptionEnumerator : public IAssumptionEnumerator {
  private:
    IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder;

  public:
    LineAssumptionEnumerator(IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder);
    virtual ~LineAssumptionEnumerator() = default;

    virtual std::vector<std::unique_ptr<IAssumption>> enumerate(
      const Core::NonogramBoard &nonogramBoard, IAssumptionPosition &assumptionPosition) override;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_LINEASSUMPTIONENUMERATOR_H
