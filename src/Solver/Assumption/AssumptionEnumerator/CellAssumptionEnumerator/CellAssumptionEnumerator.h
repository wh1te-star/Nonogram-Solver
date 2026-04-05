#ifndef VERSAN_CORE_CELLASSUMPTIONENUMERATOR_H
#define VERSAN_CORE_CELLASSUMPTIONENUMERATOR_H

#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Solver/Assumption/AssumptionEnumerator/IAssumptionEnumerator.h"
#include "Solver/Assumption/AssumptionPosition/CellAssumptionPosition/CellAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/HintAssumptionPosition/HintAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"

#include <vector>

namespace VersaN::Solver {

class CellAssumptionEnumerator : public IAssumptionEnumerator {
  public:
    CellAssumptionEnumerator();
    virtual ~CellAssumptionEnumerator() = default;

    virtual std::vector<std::unique_ptr<IAssumption>>
    enumerate(const Core::NonogramBoard &nonogramBoard, IAssumptionPosition &assumptionPosition) override;
};

} // namespace VersaN::Solver

#endif // VERSAN_CORE_CELLASSUMPTIONENUMERATOR_H
