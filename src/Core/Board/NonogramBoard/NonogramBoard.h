#ifndef VERSANO_CORE_NONOGRAMBOARD_H
#define VERSANO_CORE_NONOGRAMBOARD_H

#include "Core/Board/Board/IBoard.h"
#include "Core/Types/AppliedType/AppliedType.h"

namespace VersaNo::Core {

class NonogramBoard {
  private:
    std::shared_ptr<IBoard> board;
    RowHintGroup rowHintGroup;
    ColumnHintGroup columnHintGroup;

  public:
    explicit NonogramBoard(
      std::shared_ptr<IBoard> board, RowHintGroup rowHintGroup, ColumnHintGroup columnHintGroup);

    // =========================================================================
    // | Getters                                                               |
    // =========================================================================
    // Nonogram Board specific getters
  public:
    const IBoard &getBoard() const;
    IBoard &getBoard();
    RowHintGroup getRowHintGroup() const;
    ColumnHintGroup getColumnHintGroup() const;
    template <typename TOrientation>
    typename LineTraits<TOrientation>::HintGroup getHintGroup() const;

    // Board getter forwarders
  public:
    RowLength getRowLength() const;
    ColumnLength getColumnLength() const;
    template <typename TOrientation> typename LineTraits<TOrientation>::Length getLength() const;
    Cell getCell(CellPosition cellPosition) const;
    Row getRow(RowIndex index) const;
    Column getColumn(ColumnIndex index) const;
    template <typename TOrientation>
    typename LineTraits<TOrientation>::Line
    getLine(typename LineTraits<TOrientation>::Index index) const;

    // =========================================================================
    // | Applyers                                                              |
    // =========================================================================
  public:
    void applyCell(CellPosition coordinate, const Cell &cell, bool overrideNone = false);

    void applyRow(LinePosition<RowOrientation> linePosition, const Row &row, bool overwriteNone);
    void applyColumn(
      LinePosition<ColumnOrientation> linePosition, const Column &column, bool overwriteNone);
    template <typename TOrientation>
    void applyLine(
      typename LinePosition<TOrientation> linePosition,
      const typename LineTraits<TOrientation>::Line &line,
      bool overwriteNone);

    void
    applyRowPlacement(LinePosition<RowOrientation> linePosition, const RowPlacement &placement);
    void applyColumnPlacement(
      LinePosition<ColumnOrientation> linePosition, const ColumnPlacement &placement);
    template <typename TOrientation>
    void applyPlacement(
      typename LinePosition<TOrientation> linePosition,
      const typename LineTraits<TOrientation>::Placement &placement);

    void applyRowHint(HintPosition<RowOrientation> hintPosition, HintNumber hintNumber);
    void applyColumnHint(HintPosition<ColumnOrientation> hintPosition, HintNumber hintNumber);
    template <typename TOrientation>
    void applyHint(typename HintPosition<TOrientation> hintPosition, HintNumber hintNumber);

    void applyBoard(const IBoard &board, bool overwriteNone);

    // =========================================================================
    // | Utilities                                                             |
    // =========================================================================
  public:
    bool isSolved() const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_NONOGRAMBOARD_H
