#ifndef VERSANO_CORE_NONOGRAMBOARD_H
#define VERSANO_CORE_NONOGRAMBOARD_H

#include "Core/Board/Board/Board.h"
#include "Core/Types/AppliedType/AppliedType.h"

namespace VersaNo::Core {

class NonogramBoard {
  private:
    Board board;
    RowHintGroup rowHintGroup;
    ColumnHintGroup columnHintGroup;

  public:
    explicit NonogramBoard(Board board, RowHintGroup rowHintGroup, ColumnHintGroup columnHintGroup);

    // Board getters (method forwarding)
  public:
    RowLength getRowLength() const;
    ColumnLength getColumnLength() const;
    Board getBoard() const;
    Board &getBoard();
    Cell getCell(CellPosition cellPosition) const;
    template <typename TOrientation>
    typename LineTraits<TOrientation>::Line
    getLine(typename LineTraits<TOrientation>::Index index) const;

    // Nonogram Board specific getters
  public:
    RowHintGroup getRowHintGroup() const;
    ColumnHintGroup getColumnHintGroup() const;

    // Apply operations
  public:
    void applyCell(CellPosition coordinate, const Cell &cell, bool overrideNone = false);

    template <typename TOrientation>
    void applyLine(
      typename LinePosition<TOrientation> linePosition,
      const typename LineTraits<TOrientation>::Line &line,
      bool overwriteNone);
    template <typename TOrientation>
    void applyPlacement(
      typename LinePosition<TOrientation> linePosition,
      const typename LineTraits<TOrientation>::Placement &placement);

    template <typename TOrientation>
    void applyHint(typename HintPosition<TOrientation> hintPosition, HintNumber hintNumber);

    void applyBoard(const Board &board, bool overwriteNone);

    // Utility methods
  public:
    bool isInRange(CellPosition cellPosition) const;
    bool isSolved() const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_NONOGRAMBOARD_H
