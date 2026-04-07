#include "Core/Board/NonogramBoard/NonogramBoard.h"

namespace VersaNo::Core {

NonogramBoard::NonogramBoard(
  Board board, RowHintGroup rowHintGroup, ColumnHintGroup columnHintGroup)
    : board(std::move(board))
    , rowHintGroup(std::move(rowHintGroup))
    , columnHintGroup(std::move(columnHintGroup)) {}

RowLength NonogramBoard::getRowLength() const { return board.getRowLength(); }

ColumnLength NonogramBoard::getColumnLength() const { return board.getColumnLength(); }

Board NonogramBoard::getBoard() const { return board; }

Board &NonogramBoard::getBoard() { return board; }

Cell NonogramBoard::getCell(CellPosition cellPosition) const { return board.getCell(cellPosition); }

Row NonogramBoard::getRowLine(RowIndex rowIndex) const { return board.getRowLine(rowIndex); }

Column NonogramBoard::getColumnLine(ColumnIndex columnIndex) const {
    return board.getColumnLine(columnIndex);
}

bool NonogramBoard::isInRange(CellPosition cellPosition) const {
    return board.isInRange(cellPosition);
}

bool NonogramBoard::isSolved() const { return board.isSolved(); }

void NonogramBoard::applyCell(CellPosition cellPosition, const Cell &cell, bool overwriteNone) {
    board.applyCell(cellPosition, cell, overwriteNone);
}

void NonogramBoard::applyRow(RowIndex rowIndex, const Row &row, bool overwriteNone) {
    return board.applyRow(rowIndex, row, overwriteNone);
}

void NonogramBoard::applyRow(RowIndex rowIndex, const RowPlacement &rowPlacement) {
    return board.applyRow(rowIndex, rowPlacement);
}

void NonogramBoard::applyColumn(ColumnIndex columnIndex, const Column &column, bool overwriteNone) {
    return board.applyColumn(columnIndex, column, overwriteNone);
}

void NonogramBoard::applyColumn(ColumnIndex columnIndex, const ColumnPlacement &columnPlacement) {
    return board.applyColumn(columnIndex, columnPlacement);
}

void NonogramBoard::applyBoard(const Board &board, bool overwriteNone) {
    return this->board.applyBoard(board, overwriteNone);
}

RowHintGroup NonogramBoard::getRowHintGroup() const { return rowHintGroup; }

ColumnHintGroup NonogramBoard::getColumnHintGroup() const { return columnHintGroup; }

} // namespace VersaNo::Core