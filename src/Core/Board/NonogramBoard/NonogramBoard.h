#ifndef VERSANO_CORE_NONOGRAMBOARD_H
#define VERSANO_CORE_NONOGRAMBOARD_H

#include "Core/Board/Board/IBoard.h"
#include "Core/Types/AppliedType/AppliedType.h"

namespace VersaNo::Core {

class NonogramBoard {
  private:
    IBoard &board;
    RowHintGroup rowHintGroup;
    ColumnHintGroup columnHintGroup;

  public:
    explicit NonogramBoard(
      IBoard &board, RowHintGroup rowHintGroup, ColumnHintGroup columnHintGroup);

    // =========================================================================
    // | Getters                                                               |
    // =========================================================================
  public:
    template <typename TOrientation> typename LineTraits<TOrientation>::Length getLength() const;
    IBoard getBoard() const;
    IBoard &getBoard();
    Cell getCell(CellPosition cellPosition) const;
    template <typename TOrientation>
    typename LineTraits<TOrientation>::Line
    getLine(typename LineTraits<TOrientation>::Index index) const;

    // Nonogram Board specific getters
  public:
    template <typename TOrientation>
    typename LineTraits<TOrientation>::HintGroup getHintGroup() const;

    // =========================================================================
    // | Applyers                                                              |
    // =========================================================================
  public:
    void applyCell(CellPosition coordinate, const Cell &cell, bool overrideNone = false);

    template <typename TOrientation>
    void applyLine(
      typename LinePosition<TOrientation> linePosition,
      const typename LineTraits<TOrientation>::Line &line,
      bool overwriteNone) const {}
    template <typename TOrientation>
    void applyPlacement(
      typename LinePosition<TOrientation> linePosition,
      const typename LineTraits<TOrientation>::Placement &placement);

    template <typename TOrientation>
    void applyHint(typename HintPosition<TOrientation> hintPosition, HintNumber hintNumber);

    void applyBoard(const IBoard &board, bool overwriteNone);

    // =========================================================================
    // | Utilities                                                             |
    // =========================================================================
  public:
    bool isInRange(CellPosition cellPosition) const;
    bool isSolved() const;
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_NONOGRAMBOARD_H
