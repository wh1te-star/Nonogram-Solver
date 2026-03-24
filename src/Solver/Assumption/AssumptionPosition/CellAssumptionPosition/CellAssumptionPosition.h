#ifndef CELLASSUMPTIONPOSITION_H
#define CELLASSUMPTIONPOSITION_H

#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Board/NonogramBoard/NonogramBoard.h"
#include "Index/CellIndex/RowIndex.h"
#include "Index/CellIndex/ColumnIndex.h"

class CellAssumptionPosition : public IAssumptionPosition {
private:
    RowIndex row;
    ColumnIndex column;

public:
    CellAssumptionPosition(RowIndex row, ColumnIndex column);
    virtual ~CellAssumptionPosition() = default;

    RowIndex getRow() const;
    ColumnIndex getColumn() const;
};

#endif