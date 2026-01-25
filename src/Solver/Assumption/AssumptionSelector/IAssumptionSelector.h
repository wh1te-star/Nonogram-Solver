#ifndef IASSUMPTIONSELECTOR_H
#define IASSUMPTIONSELECTOR_H

#include <vector>
#include <memory>
#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Board/BacktrackBoard/BacktrackBoard.h"

class IAssumptionSelector {
public:
    virtual ~IAssumptionSelector() = default;
    virtual std::vector<std::unique_ptr<IAssumption>> select(const BacktrackBoard& board) = 0;
};


#endif