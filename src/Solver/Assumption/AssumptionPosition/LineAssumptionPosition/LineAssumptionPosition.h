#ifndef LINEASSUMPTIONPOSITION_H
#define LINEASSUMPTIONPOSITION_H

#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Board/NonogramBoard/NonogramBoard.h"
#include "Board/Orientation.h"
#include "Index/Position/LinePosition/LinePosition.h"

class LineAssumptionPosition : public IAssumptionPosition {
private:
    LinePosition linePosition;

public:
    LineAssumptionPosition(LinePosition linePosition);
    virtual ~LineAssumptionPosition() = default;

    LinePosition getLinePosition() const;
};

#endif
