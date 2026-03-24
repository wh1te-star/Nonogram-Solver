#ifndef LINEASSUMPTIONPOSITION_H
#define LINEASSUMPTIONPOSITION_H

#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Board/NonogramBoard/NonogramBoard.h"
#include "Board/Orientation.h"
#include "Index/CellIndex/CellIndex.h"

class LineAssumptionPosition : public IAssumptionPosition {
private:
    Orientation orientation;
    CellIndex index;

public:
    LineAssumptionPosition(Orientation orientation, CellIndex index);
    virtual ~LineAssumptionPosition() = default;

    Orientation getOrientation() const;
    CellIndex getIndex() const;
};

#endif
