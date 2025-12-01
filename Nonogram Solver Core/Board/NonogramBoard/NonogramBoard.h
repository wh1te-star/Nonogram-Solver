#ifndef NONOGRAMBOARD_H
#define NONOGRAMBOARD_H


#include "Board.h"
#include "RowLength.h"
#include "ColumnLength.h"
#include "ColumnHintSetList.h"
#include "RowHintSetList.h"
#include "HintSet.h"

class NonogramBoard {
private:
    Board board;
	RowHintSetList rowHintSetList;
	ColumnHintSetList columnHintSetList;

public:
    explicit NonogramBoard(
		Board board,
		RowHintSetList rowHintSetList,
		ColumnHintSetList columnHintSetList
	);

public:
	RowLength getRowLength() const;
	ColumnLength getColumnLength() const;
	Board getBoard() const;
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

public:
	RowHintSetList getRowHintSetList() const;
	ColumnHintSetList getColumnHintSetList() const;
};

#endif
