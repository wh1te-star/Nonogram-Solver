#ifndef CELLASSUMPTIONPOSITION_H
#define CELLASSUMPTIONPOSITION_H

#include "Board/NonogramBoard/NonogramBoard.h"
#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"

class CellAssumptionPosition : public IAssumptionPosition {
  private:
    RowIndex row;
    ColumnIndex column;

  public:
    CellAssumptionPosition(RowIndex row, ColumnIndex column);
    virtual ~CellAssumptionPosition() = default;

    RowIndex getRowIndex() const;
    ColumnIndex getColumnIndex() const;
};

#endif