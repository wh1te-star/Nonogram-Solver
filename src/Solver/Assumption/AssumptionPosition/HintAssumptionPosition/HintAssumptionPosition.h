#ifndef HINTASSUMPTIONPOSITION_H
#define HINTASSUMPTIONPOSITION_H

#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Board/NonogramBoard/NonogramBoard.h"
#include "Board/Orientation.h"
#include "Index/Position/HintPosition/HintPosition.h"

class HintAssumptionPosition : public IAssumptionPosition {
private:
    HintPosition hintPosition;

public:
    HintAssumptionPosition(HintPosition hintPosition);
    virtual ~HintAssumptionPosition() = default;

    HintPosition getHintPosition() const;
};

#endif

