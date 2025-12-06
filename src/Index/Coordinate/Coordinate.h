#ifndef COORDINATE_H
#define COORDINATE_H

#include "Board/BoardLength/ColumnLength.h"
#include "Board/BoardLength/RowLength.h"
#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"

class Coordinate {
private:
  RowIndex rowIndex;
  ColumnIndex columnIndex;

public:
  explicit Coordinate(RowIndex rowIndex, ColumnIndex columnIndex);

public:
  const RowIndex &getRowIndex() const;
  const ColumnIndex &getColumnIndex() const;

public:
  bool operator==(const Coordinate &other) const;
  bool operator!=(const Coordinate &other) const;

public:
  Coordinate move(int rowShift, int columnShift) const;
  Coordinate move(RowLength rowShift, ColumnLength columnShift) const;
};

#endif
