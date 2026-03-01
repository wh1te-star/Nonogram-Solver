#ifndef IASSUMPTIONSELECTOR_H
#define IASSUMPTIONSELECTOR_H

#include <vector>
#include <memory>
#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Board/NonogramBoard/NonogramBoard.h"

class IAssumptionSelector {
public:
    virtual ~IAssumptionSelector() = default;

    virtual std::vector<std::unique_ptr<IAssumption>> select(const NonogramBoard &board) = 0;
};


#endif