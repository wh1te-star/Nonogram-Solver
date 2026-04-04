#ifndef BOARD_H
#define BOARD_H

#include "Core/Board/BoardLength/ColumnLength.h"
#include "Core/Board/BoardLength/RowLength.h"
#include "Core/Board/Line/Column.h"
#include "Core/Board/Line/Row.h"
#include "Core/Cell/CellColor/CellColor.h"
#include "Core/Cell/CellVector2D/CellVector2D.h"
#include "Core/Index/CellIndex/ColumnIndex.h"
#include "Core/Index/CellIndex/RowIndex.h"
#include "Core/Index/Position/CellPosition/CellPosition.h"
#include "Core/Placement/Placement/ColumnPlacement.h"
#include "Core/Placement/Placement/Placement.h"
#include "Core/Placement/Placement/RowPlacement.h"
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
    Cell getCell(CellPosition coordinate) const;
    Row getRowLine(RowIndex rowIndex) const;
    Column getColumnLine(ColumnIndex columnIndex) const;
    bool isInRange(CellPosition coordinate) const;
    bool isSolved() const;

  public:
    void applyCell(CellPosition coordinate, const Cell &cell, bool overrideNone = false);
    void applyRow(RowIndex rowIndex, const Row &row, bool overwriteNone);
    void applyRow(RowIndex rowIndex, const RowPlacement &rowPlacement);
    void applyColumn(ColumnIndex columnIndex, const Column &column, bool overwriteNone);
    void applyColumn(ColumnIndex columnIndex, const ColumnPlacement &columnPlacement);
    void applyBoard(const Board &board, bool overwriteNone);
};

#endif
