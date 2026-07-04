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
    virtual ~IBoard() = default;

    // =========================================================================
    // | Getters                                                               |
    // =========================================================================
    virtual RowLength getRowLength() const = 0;
    virtual ColumnLength getColumnLength() const = 0;

    virtual Cell getCell(CellPosition coordinate) const = 0;

    virtual Row getRow(RowIndex index) const = 0;
    virtual Column getColumn(ColumnIndex index) const = 0;

    // =========================================================================
    // | Applyers                                                              |
    // =========================================================================
    virtual void applyCell(CellPosition coordinate, const Cell &cell, bool overrideNone = false) = 0;

    virtual void
    applyRow(LinePosition<RowOrientation> linePosition, const Row &row, bool overwriteNone) = 0;
    virtual void applyColumn(
      LinePosition<ColumnOrientation> linePosition, const Column &column, bool overwriteNone) = 0;

    virtual void applyRowPlacement(
      LinePosition<RowOrientation> linePosition, const RowPlacement &placement) = 0;
    virtual void applyColumnPlacement(
      LinePosition<ColumnOrientation> linePosition, const ColumnPlacement &placement) = 0;

    virtual void applyRowHint(HintPosition<RowOrientation> hintPosition, HintNumber hintNumber) = 0;
    virtual void applyColumnHint(HintPosition<ColumnOrientation> hintPosition, HintNumber hintNumber) = 0;

    virtual void applyBoard(const IBoard &board, bool overwriteNone) = 0;

    // =========================================================================
    // | Utilities                                                             |
    // =========================================================================
    virtual bool isSolved() const = 0;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_IBOARD_H
