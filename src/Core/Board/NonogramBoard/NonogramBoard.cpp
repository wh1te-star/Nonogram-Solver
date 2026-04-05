#include "Core/Board/NonogramBoard/NonogramBoard.h"

namespace VersaN::Core {

NonogramBoard::NonogramBoard(
		Board board,
		RowHintSetList rowHintSetList,
		ColumnHintSetList columnHintSetList
) : board(std::move(board)),
    rowHintSetList(std::move(rowHintSetList)),
    columnHintSetList(std::move(columnHintSetList)) {}

RowLength NonogramBoard::getRowLength() const {
	return board.getRowLength();
}

ColumnLength NonogramBoard::getColumnLength() const {
	return board.getColumnLength();
}

Board NonogramBoard::getBoard() const {
	return board;
}

Board& NonogramBoard::getBoard() {
    return board;
}

Cell NonogramBoard::getCell(CellPosition cellPosition) const {
	return board.getCell(cellPosition);
}

Row NonogramBoard::getRowLine(RowIndex rowIndex) const {
	return board.getRowLine(rowIndex);
}

Column NonogramBoard::getColumnLine(ColumnIndex columnIndex) const {
	return board.getColumnLine(columnIndex);
}

bool NonogramBoard::isInRange(CellPosition cellPosition) const {
	return board.isInRange(cellPosition);
}

bool NonogramBoard::isSolved() const {
	return board.isSolved();
}

void NonogramBoard::applyCell(CellPosition cellPosition, const Cell& cell, bool overwriteNone) {
	board.applyCell(cellPosition, cell, overwriteNone);
}

void NonogramBoard::applyRow(RowIndex rowIndex, const Row& row, bool overwriteNone) {
	return board.applyRow(rowIndex, row, overwriteNone);
}

void NonogramBoard::applyRow(RowIndex rowIndex, const RowPlacement& rowPlacement) {
	return board.applyRow(rowIndex, rowPlacement);
}

void NonogramBoard::applyColumn(ColumnIndex columnIndex, const Column& column, bool overwriteNone) {
	return board.applyColumn(columnIndex, column, overwriteNone);
}

void NonogramBoard::applyColumn(ColumnIndex columnIndex, const ColumnPlacement& columnPlacement) {
	return board.applyColumn(columnIndex, columnPlacement);
}

void NonogramBoard::applyBoard(const Board& board, bool overwriteNone) {
	return this->board.applyBoard(board, overwriteNone);
}

RowHintSetList NonogramBoard::getRowHintSetList() const {
	return rowHintSetList;
}

ColumnHintSetList NonogramBoard::getColumnHintSetList() const {
	return columnHintSetList;
}

} // namespace VersaN::Core