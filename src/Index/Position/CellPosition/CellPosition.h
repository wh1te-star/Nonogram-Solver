#ifndef CELLPOSITION_H
#define CELLPOSITION_H

#include "Board/BoardLength/ColumnLength.h"
#include "Board/BoardLength/RowLength.h"
#include "Index/Position/IPosition.h"
#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"

class CellPosition : public IPosition {
  private:
    RowIndex rowIndex;
    ColumnIndex columnIndex;

  public:
    explicit CellPosition(RowIndex rowIndex, ColumnIndex columnIndex);

  public:
    const RowIndex &getRowIndex() const;
    const ColumnIndex &getColumnIndex() const;

  public:
    bool operator==(const CellPosition &other) const;
    bool operator!=(const CellPosition &other) const;

  public:
    CellPosition move(int rowShift, int columnShift) const;
    CellPosition move(RowLength rowShift, ColumnLength columnShift) const;
};

#endif
