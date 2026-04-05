#include "Core/Board/Board/Board.h"

#include "Core/Board/BoardLength/ColumnLength.h"
#include "Core/Board/BoardLength/RowLength.h"
#include "Core/Cell/Cell/Cell.h"
#include "Core/Cell/CellLocation/CellLocation.h"
#include "Core/Index/CellIndex/ColumnIndex.h"
#include "Core/Index/CellIndex/RowIndex.h"

#include <cassert>
#include <typeinfo>

namespace VersaN::Core {

Board::Board(RowLength rowLength, ColumnLength columnLength)
    : rowLength(std::move(rowLength)), columnLength(std::move(columnLength)) {
  board.resize(rowLength.getLength(),
               std::vector<Cell>(columnLength.getLength(), Cell()));
}

bool Board::operator==(const Board &other) const {
  return board == other.board;
}

bool Board::operator!=(const Board &other) const { return !(*this == other); }

RowLength Board::getRowLength() const { return rowLength; }

ColumnLength Board::getColumnLength() const { return columnLength; }

Cell Board::getCell(CellPosition cellPosition) const {
  assert(isInRange(cellPosition));
  RowIndex rowIndex = cellPosition.getRowIndex();
  ColumnIndex columnIndex = cellPosition.getColumnIndex();
  return board[rowIndex.getIndex()][columnIndex.getIndex()];
}

Row Board::getRowLine(RowIndex rowIndex) const {
  std::vector<Cell> row;
  for (ColumnIndex columnIndex :
       ColumnIndex::range(0, columnLength.getLength() - 1)) {
    CellPosition cellPosition = CellPosition(rowIndex, columnIndex);
    Cell cell = getCell(cellPosition);
    row.push_back(cell);
  }
  return Row(row);
}

Column Board::getColumnLine(ColumnIndex columnIndex) const {
  std::vector<Cell> column;
  for (RowIndex rowIndex : RowIndex::range(0, rowLength.getLength() - 1)) {
    CellPosition cellPosition = CellPosition(rowIndex, columnIndex);
    Cell cell = getCell(cellPosition);
    column.push_back(cell);
  }
  return Column(column);
}

bool Board::isInRange(CellPosition cellPosition) const {
  RowIndex rowIndex = cellPosition.getRowIndex();
  ColumnIndex columnIndex = cellPosition.getColumnIndex();
  if (columnIndex < ColumnLength(0) || columnLength <= columnIndex) {
    return false;
  }
  if (rowIndex < RowLength(0) || rowLength <= rowIndex) {
    return false;
  }
  return true;
}

bool Board::isSolved() const {
  for (std::vector<Cell> row : board) {
    for (Cell cell : row) {
      if (cell.getColor() == None) {
        return false;
      }
    }
  }
  return true;
}

void Board::applyCell(CellPosition cellPosition, const Cell &cell,
                      bool overwriteNone) {
  if (!isInRange(cellPosition)) {
    return;
  }
  if (!overwriteNone && cell.getColor() == None) {
    return;
  }

  RowIndex rowIndex = cellPosition.getRowIndex();
  ColumnIndex columnIndex = cellPosition.getColumnIndex();
  board[rowIndex.getIndex()][columnIndex.getIndex()] = cell;
}

void Board::applyRow(RowIndex rowIndex, const Row &row, bool overwriteNone) {
  assert(row.size() == columnLength.getLength());

  for (ColumnIndex columnIndex : ColumnIndex::range(0, row.size() - 1)) {
    CellPosition cellPosition = CellPosition(rowIndex, columnIndex);
    Cell cell = row[columnIndex];
    applyCell(cellPosition, cell, overwriteNone);
  }
}

void Board::applyRow(RowIndex rowIndex, const RowPlacement &rowPlacement) {
  assert(rowPlacement.size() == columnLength.getLength());

  for (ColumnIndex columnIndex :
       ColumnIndex::range(0, rowPlacement.size() - 1)) {
    CellPosition cellPosition = CellPosition(rowIndex, columnIndex);
    Cell cell = rowPlacement[columnIndex];
    applyCell(cellPosition, cell);
  }
}

void Board::applyColumn(ColumnIndex columnIndex, const Column &column,
                        bool overwriteNone) {
  assert(column.size() == rowLength.getLength());

  for (RowIndex rowIndex : RowIndex::range(0, column.size() - 1)) {
    CellPosition cellPosition = CellPosition(rowIndex, columnIndex);
    Cell cell = column[rowIndex];
    applyCell(cellPosition, cell, overwriteNone);
  }
}

void Board::applyColumn(ColumnIndex columnIndex,
                        const ColumnPlacement &columnPlacement) {
  assert(columnPlacement.size() == rowLength.getLength());

  for (RowIndex rowIndex : RowIndex::range(0, columnPlacement.size() - 1)) {
    CellPosition cellPosition = CellPosition(rowIndex, columnIndex);
    Cell cell = columnPlacement[rowIndex];
    applyCell(cellPosition, cell);
  }
}

void Board::applyBoard(const Board &board, bool overwriteNone) {
  for (RowIndex rowIndex : RowIndex::range(0, rowLength.getLength() - 1)) {
    Row rowLine = board.getRowLine(rowIndex);
    applyRow(rowIndex, rowLine, overwriteNone);
  }
}

} // namespace VersaN::Core