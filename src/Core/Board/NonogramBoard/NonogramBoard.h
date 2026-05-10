#ifndef VERSANO_CORE_NONOGRAMBOARD_H
#define VERSANO_CORE_NONOGRAMBOARD_H

#include "Core/Board/Board/Board.h"
#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Hint/HintGroup/ColumnHintGroup.h"
#include "Core/Hint/HintGroup/RowHintGroup.h"
#include "Core/Hint/HintList/HintList.h"

namespace VersaNo::Core {

class NonogramBoard {
  private:
    Board board;
    RowHintGroup rowHintGroup;
    ColumnHintGroup columnHintGroup;

  public:
    explicit NonogramBoard(Board board, RowHintGroup rowHintGroup, ColumnHintGroup columnHintGroup);

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
    RowHintGroup getRowHintGroup() const;
    ColumnHintGroup getColumnHintGroup() const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_NONOGRAMBOARD_H
