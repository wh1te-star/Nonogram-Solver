#ifndef BOARD_H
#define BOARD_H

#include "Board/BoardLength/ColumnLength.h"
#include "Board/BoardLength/RowLength.h"
#include "Board/Line/Column.h"
#include "Board/Line/Row.h"
#include "Cell/CellColor/CellColor.h"
#include "Cell/CellVector2D/CellVector2D.h"
#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"
#include "Index/Coordinate/Coordinate.h"
#include "Placement/Placement/ColumnPlacement.h"
#include "Placement/Placement/Placement.h"
#include "Placement/Placement/RowPlacement.h"
#include <vector>

class Board {
private:
  RowLength rowLength;
  ColumnLength columnLength;
  CellVector2D board;

public:
  Board(RowLength rowLength, ColumnLength columnLength);

public:
  bool operator==(const Board &other) const;
  bool operator!=(const Board &other) const;

public:
  RowLength getRowLength() const;
  ColumnLength getColumnLength() const;
  Cell getCell(Coordinate coordinate) const;
  Row getRowLine(RowIndex rowIndex) const;
  Column getColumnLine(ColumnIndex columnIndex) const;
  bool isInRange(Coordinate coordinate) const;
  bool isSolved() const;

public:
  void applyCell(Coordinate coordinate, const Cell &cell,
                 bool overrideNone = false);
  void applyRow(RowIndex rowIndex, const Row &row, bool overwriteNone);
  void applyRow(RowIndex rowIndex, const RowPlacement &rowPlacement);
  void applyColumn(ColumnIndex columnIndex, const Column &column,
                   bool overwriteNone);
  void applyColumn(ColumnIndex columnIndex,
                   const ColumnPlacement &columnPlacement);
  void applyBoard(const Board &board, bool overwriteNone);
};

#endif
