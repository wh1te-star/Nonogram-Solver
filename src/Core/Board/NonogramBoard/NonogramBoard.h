#ifndef VERSAN_CORE_NONOGRAMBOARD_H
#define VERSAN_CORE_NONOGRAMBOARD_H

#include "Core/Board/Board/Board.h"
#include "Core/Board/BoardLength/ColumnLength.h"
#include "Core/Board/BoardLength/RowLength.h"
#include "Core/Hint/HintSet/HintSet.h"
#include "Core/Hint/HintSetList/ColumnHintSetList.h"
#include "Core/Hint/HintSetList/RowHintSetList.h"

namespace VersaN::Core {

class NonogramBoard {
  private:
    Board board;
    RowHintSetList rowHintSetList;
    ColumnHintSetList columnHintSetList;

  public:
    explicit NonogramBoard(
      Board board, RowHintSetList rowHintSetList, ColumnHintSetList columnHintSetList);

  public:
    RowLength getRowLength() const;
    ColumnLength getColumnLength() const;
    Board getBoard() const;
    Board &getBoard();
    Cell getCell(CellPosition cellPosition) const;
    Row getRowLine(RowIndex rowIndex) const;
    Column getColumnLine(ColumnIndex columnIndex) const;
    bool isInRange(CellPosition cellPosition) const;
    bool isSolved() const;

  public:
    void applyCell(CellPosition cellPosition, const Cell &cell, bool overrideNone = false);
    void applyRow(RowIndex rowIndex, const Row &row, bool overwriteNone);
    void applyRow(RowIndex rowIndex, const RowPlacement &rowPlacement);
    void applyColumn(ColumnIndex columnIndex, const Column &column, bool overwriteNone);
    void applyColumn(ColumnIndex columnIndex, const ColumnPlacement &columnPlacement);
    void applyBoard(const Board &board, bool overwriteNone);

  public:
    RowHintSetList getRowHintSetList() const;
    ColumnHintSetList getColumnHintSetList() const;
};

} // namespace VersaN::Core

#endif // VERSAN_CORE_NONOGRAMBOARD_H
