#ifndef LINEASSUMPTIONPOSITION_H
#define LINEASSUMPTIONPOSITION_H

#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Board/Orientation.h"
#include "Core/Index/Position/LinePosition/LinePosition.h"

class LineAssumptionPosition : public IAssumptionPosition {
private:
    LinePosition linePosition;

public:
    LineAssumptionPosition(LinePosition linePosition);
    virtual ~LineAssumptionPosition() = default;

    LinePosition getLinePosition() const;
};

#endif
