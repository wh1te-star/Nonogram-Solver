#ifndef IASSUMPTIONENUMERATOR_H
#define IASSUMPTIONENUMERATOR_H

#include "Board/Board/Board.h"
#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Solver/Assumption/AssumptionPosition/CellAssumptionPosition/CellAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/HintAssumptionPosition/HintAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include <vector>

class IAssumptionEnumerator {
public:
    virtual ~IAssumptionEnumerator() = default;
    virtual std::vector<std::unique_ptr<IAssumption>> enumerate(
        const NonogramBoard &nonogramBoard, IAssumptionPosition &assumptionPosition) = 0;
};

#endif