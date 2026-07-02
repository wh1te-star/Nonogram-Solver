#ifndef VERSANO_CORE_IBOARD_H
#define VERSANO_CORE_IBOARD_H

#include "Core/Cell/CellColor/CellColor.h"
#include "Core/Cell/CellVector2D/CellVector2D.h"
#include "Core/Position/CellPosition/CellPosition.h"
#include "Core/Position/HintPosition/HintPosition.h"
#include "Core/Position/LinePosition/LinePosition.h"
#include "Core/Types/AppliedType/AppliedType.h"
#include <vector>

namespace VersaNo::Core {

class IBoard {
  public:
    RowLength getRowLength() const = 0;
    ColumnLength getColumnLength() const = 0;
    Cell getCell(CellPosition coordinate) const = 0;

    Row getRow(RowIndex index) const = 0;
    Column getColumn(ColumnIndex index) const = 0;

    void applyCell(CellPosition coordinate, const Cell &cell, bool overrideNone = false) = 0;

    void
    applyRow(LinePosition<RowOrientation> linePosition, const Row &row, bool overwriteNone) = 0;
    void applyColumn(
      LinePosition<ColumnOrientation> linePosition, const Column &column, bool overwriteNone) = 0;

    void applyRowPlacement(
      LinePosition<RowOrientation> linePosition, const Row::Placement &placement) = 0;
    void applyColumnPlacement(
      LinePosition<ColumnOrientation> linePosition, const Column::Placement &placement) = 0;

    void applyHint(HintPosition<RowOrientation> hintPosition, HintNumber hintNumber) = 0;
    void applyHint(HintPosition<ColumnOrientation> hintPosition, HintNumber hintNumber) = 0;

    void applyBoard(const IBoard &board, bool overwriteNone) = 0;

    bool isSolved() const = 0;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_IBOARD_H
