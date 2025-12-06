#include "Index/Coordinate/Coordinate.h"

#include "Board/BoardLength/ColumnLength.h"
#include "Board/BoardLength/RowLength.h"
#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"

Coordinate::Coordinate(RowIndex rowIndex, ColumnIndex columnIndex)
    : rowIndex(rowIndex), columnIndex(columnIndex) {}

const RowIndex &Coordinate::getRowIndex() const { return rowIndex; }

const ColumnIndex &Coordinate::getColumnIndex() const { return columnIndex; }

bool Coordinate::operator==(const Coordinate &other) const {
  return rowIndex == other.rowIndex && columnIndex == other.columnIndex;
}

bool Coordinate::operator!=(const Coordinate &other) const {
  return !(*this == other);
}

Coordinate Coordinate::move(int rowShift, int columnShift) const {
  return Coordinate(rowIndex + RowLength(rowShift),
                    columnIndex + ColumnLength(columnShift));
}

Coordinate Coordinate::move(RowLength rowShift,
                            ColumnLength columnShift) const {
  return Coordinate(rowIndex + rowShift, columnIndex + columnShift);
}
