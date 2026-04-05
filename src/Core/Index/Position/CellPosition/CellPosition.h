#ifndef VERSAN_CORE_CELLPOSITION_H
#define VERSAN_CORE_CELLPOSITION_H

#include "Core/Board/BoardLength/ColumnLength.h"
#include "Core/Board/BoardLength/RowLength.h"
#include "Core/Index/CellIndex/ColumnIndex.h"
#include "Core/Index/CellIndex/RowIndex.h"
#include "Core/Index/Position/IPosition.h"

namespace VersaN::Core {

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

} // namespace VersaN::Core

#endif // VERSAN_CORE_CELLPOSITION_H
