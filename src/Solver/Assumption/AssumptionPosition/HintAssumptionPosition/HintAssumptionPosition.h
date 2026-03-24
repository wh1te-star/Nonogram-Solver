#ifndef HINTASSUMPTIONPOSITION_H
#define HINTASSUMPTIONPOSITION_H

#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Board/NonogramBoard/NonogramBoard.h"
#include "Board/Orientation.h"
#include "Index/CellIndex/CellIndex.h"

class HintAssumptionPosition : public IAssumptionPosition {
private:
    Orientation orientation;
    CellIndex index;
    int hintIndex;

public:
    HintAssumptionPosition(Orientation orientation, CellIndex index, int hintIndex);
    virtual ~HintAssumptionPosition() = default;

    Orientation getOrientation() const;
    CellIndex getIndex() const;
    int getHintIndex() const;
};

#endif

