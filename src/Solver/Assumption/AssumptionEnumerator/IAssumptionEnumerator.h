#ifndef VERSAN_CORE_IASSUMPTIONENUMERATOR_H
#define VERSAN_CORE_IASSUMPTIONENUMERATOR_H

#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Solver/Assumption/AssumptionPosition/CellAssumptionPosition/CellAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/HintAssumptionPosition/HintAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"

#include <vector>

namespace VersaN::Solver {

class IAssumptionEnumerator {
  public:
    virtual ~IAssumptionEnumerator() = default;
    virtual std::vector<std::unique_ptr<IAssumption>>
    enumerate(const Core::NonogramBoard &nonogramBoard, IAssumptionPosition &assumptionPosition) = 0;
};

} // namespace VersaN::Solver

#endif // VERSAN_CORE_IASSUMPTIONENUMERATOR_H