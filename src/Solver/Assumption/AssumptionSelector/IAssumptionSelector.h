#ifndef IASSUMPTIONSELECTOR_H
#define IASSUMPTIONSELECTOR_H

#include "Board/NonogramBoard/NonogramBoard.h"
#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Solver/Assumption/AssumptionSelectionContext.h"
#include <memory>
#include <vector>

class IAssumptionSelector {
  public:
    virtual ~IAssumptionSelector() = default;

    virtual std::vector<std::unique_ptr<IAssumption>>
    select(const NonogramBoard &board, const AssumptionSelectionContext &context) = 0;
};

#endif