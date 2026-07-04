#ifndef VERSANO_CORE_BOARD_H
#define VERSANO_CORE_BOARD_H

#include "Core/Board/Board/IBoard.h"
#include "Core/Cell/CellColor/CellColor.h"
#include "Core/Cell/CellVector2D/CellVector2D.h"
#include "Core/Position/CellPosition/CellPosition.h"
#include "Core/Position/HintPosition/HintPosition.h"
#include "Core/Position/LinePosition/LinePosition.h"
#include "Core/Types/AppliedType/AppliedType.h"
#include <vector>

namespace VersaNo::Core {

class VectorBoard : public IBoard {
  private:
    RowLength rowLength;
    ColumnLength columnLength;
    CellVector2D board;

  public:
    VectorBoard(RowLength rowLength, ColumnLength columnLength);

    bool operator==(const VectorBoard &other) const;
    bool operator!=(const VectorBoard &other) const;

    // =========================================================================
    // | Getters                                                               |
    // =========================================================================
    RowLength getRowLength() const override;
    ColumnLength getColumnLength() const override;
    template <typename TOrientation> typename LineTraits<TOrientation>::Length getLength() const;

    Cell getCell(CellPosition coordinate) const override;

    Row getRow(RowIndex index) const override;
    Column getColumn(ColumnIndex index) const override;
    template <typename TOrientation>
    typename LineTraits<TOrientation>::Line
    getLine(typename LineTraits<TOrientation>::Index index) const;

    // =========================================================================
    // | Applyers                                                              |
    // =========================================================================
    void applyCell(CellPosition coordinate, const Cell &cell, bool overrideNone = false) override;

    void
    applyRow(LinePosition<RowOrientation> linePosition, const Row &row, bool overwriteNone) override;
    void applyColumn(
      LinePosition<ColumnOrientation> linePosition, const Column &column, bool overwriteNone) override;
    void applyRowPlacement(
      LinePosition<RowOrientation> linePosition, const RowPlacement &placement) override;
    void applyColumnPlacement(
      LinePosition<ColumnOrientation> linePosition, const ColumnPlacement &placement) override;

    template <typename TOrientation>
    void applyLine(
      typename LinePosition<TOrientation> linePosition,
      const typename LineTraits<TOrientation>::Line &line,
      bool overwriteNone);
    template <typename TOrientation>
    void applyPlacement(
      typename LinePosition<TOrientation> linePosition,
      const typename LineTraits<TOrientation>::Placement &placement);

    void applyRowHint(HintPosition<RowOrientation> hintPosition, HintNumber hintNumber) override;
    void applyColumnHint(HintPosition<ColumnOrientation> hintPosition, HintNumber hintNumber) override;
    template <typename TOrientation>
    void applyHint(typename HintPosition<TOrientation> hintPosition, HintNumber hintNumber);

    void applyBoard(const IBoard &board, bool overwriteNone) override;

    // =========================================================================
    // | Utilities                                                             |
    // =========================================================================
    bool isSolved() const override;

  public:
    bool isInRange(CellPosition coordinate) const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_BOARD_H