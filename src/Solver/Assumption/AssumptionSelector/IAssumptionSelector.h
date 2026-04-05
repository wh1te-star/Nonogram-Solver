#ifndef VERSAN_CORE_IASSUMPTIONSELECTOR_H
#define VERSAN_CORE_IASSUMPTIONSELECTOR_H

#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionSelectionContext.h"

#include <memory>
#include <vector>

namespace VersaN::Core {
class NonogramBoard;
}

namespace VersaN::Solver {

class IAssumptionSelector {
  public:
    virtual ~IAssumptionSelector() = default;

    virtual std::unique_ptr<IAssumptionPosition>
    select(const Core::NonogramBoard &board, const AssumptionSelectionContext &context) = 0;
};

} // namespace VersaN::Solver

#endif // VERSAN_CORE_IASSUMPTIONSELECTOR_H