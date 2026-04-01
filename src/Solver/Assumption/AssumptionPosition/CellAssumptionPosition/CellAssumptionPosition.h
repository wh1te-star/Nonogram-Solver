#ifndef CELLASSUMPTIONPOSITION_H
#define CELLASSUMPTIONPOSITION_H

#include "Board/NonogramBoard/NonogramBoard.h"
#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"

class CellAssumptionPosition : public IAssumptionPosition {
  private:
    CellPosition cellPosition;

  public:
    CellAssumptionPosition(CellPosition cellPosition);
    virtual ~CellAssumptionPosition() = default;

    CellPosition getCellPosition() const;
};

#endif