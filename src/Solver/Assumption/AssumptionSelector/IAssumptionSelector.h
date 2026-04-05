#ifndef VERSANO_CORE_IASSUMPTIONSELECTOR_H
#define VERSANO_CORE_IASSUMPTIONSELECTOR_H

#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionSelectionContext.h"

#include <memory>
#include <vector>

namespace VersaNo::Core {
class NonogramBoard;
}

namespace VersaNo::Solver {

class IAssumptionSelector {
  public:
    virtual ~IAssumptionSelector() = default;

    virtual std::unique_ptr<IAssumptionPosition>
    select(const Core::NonogramBoard &board, const AssumptionSelectionContext &context) = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_IASSUMPTIONSELECTOR_H