#ifndef IASSUMPTIONSELECTOR_H
#define IASSUMPTIONSELECTOR_H

#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionSelectionContext.h"
#include <memory>
#include <vector>
class NonogramBoard;

class IAssumptionSelector {
  public:
    virtual ~IAssumptionSelector() = default;

    virtual std::unique_ptr<IAssumptionPosition>
    select(const NonogramBoard &board, const AssumptionSelectionContext &context) = 0;
};

#endif