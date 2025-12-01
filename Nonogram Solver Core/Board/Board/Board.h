#ifndef BOARD_H
#define BOARD_H


#include <vector>
#include "RowLength.h"
#include "ColumnLength.h"
#include "CellVector2D.h"
#include "CellColor.h"
#include "Coordinate.h"
#include "ColumnIndex.h"
#include "RowIndex.h"
#include "Row.h"
#include "Column.h"
#include "Placement.h"
#include "RowPlacement.h"
#include "ColumnPlacement.h"

class Board {
private:
	RowLength rowLength;
	ColumnLength columnLength;
	CellVector2D board;

public:
	Board(RowLength rowLength, ColumnLength columnLength);

public:
	bool operator==(const Board& other) const;
	bool operator!=(const Board& other) const;

public:
	RowLength getRowLength() const;
	ColumnLength  getColumnLength() const;
	Cell getCell(Coordinate coordinate) const;
	Row getRowLine(RowIndex rowIndex) const;
	Column getColumnLine(ColumnIndex columnIndex) const;
	bool isInRange(Coordinate coordinate) const;
	bool isSolved() const;

public:
	void applyCell(Coordinate coordinate, const Cell& cell, bool overrideNone = false);
	void applyRow(RowIndex rowIndex, const Row& row, bool overwriteNone);
	void applyRow(RowIndex rowIndex, const RowPlacement& rowPlacement);
	void applyColumn(ColumnIndex columnIndex, const Column& column, bool overwriteNone);
	void applyColumn(ColumnIndex columnIndex, const ColumnPlacement& columnPlacement);
	void applyBoard(const Board& board, bool overwriteNone);
};


#endif
