#include "Core/Board/NonogramBoard/NonogramBoard.h"

namespace VersaNo::Core {

NonogramBoard::NonogramBoard(
  Board board, RowHintGroup rowHintGroup, ColumnHintGroup columnHintGroup)
    : board(std::move(board))
    , rowHintGroup(std::move(rowHintGroup))
    , columnHintGroup(std::move(columnHintGroup)) {}

template <typename TOrientation>
typename LineTraits<TOrientation>::Length NonogramBoard::getLength() const {
    return board.getLength<TOrientation>();
}

Board NonogramBoard::getBoard() const { return board; }

Board &NonogramBoard::getBoard() { return board; }

Cell NonogramBoard::getCell(CellPosition cellPosition) const { return board.getCell(cellPosition); }

template <typename TOrientation>
typename LineTraits<TOrientation>::Line
NonogramBoard::getLine(typename LineTraits<TOrientation>::Index index) const {
    return board.getLine<TOrientation>(index);
}

template <>
typename LineTraits<RowOrientation>::HintGroup NonogramBoard::getHintGroup<RowOrientation>() const {
    return rowHintGroup;
}

template <>
typename LineTraits<ColumnOrientation>::HintGroup
NonogramBoard::getHintGroup<ColumnOrientation>() const {
    return columnHintGroup;
}

void NonogramBoard::applyCell(CellPosition cellPosition, const Cell &cell, bool overwriteNone) {
    board.applyCell(cellPosition, cell, overwriteNone);
}

template <typename TOrientation>
void NonogramBoard::applyLine(
  typename LinePosition<TOrientation> linePosition,
  const typename LineTraits<TOrientation>::Line &line,
  bool overwriteNone) {
    return board.applyLine<TOrientation>(linePosition, line, overwriteNone);
}

template <typename TOrientation>
void NonogramBoard::applyPlacement(
  typename LinePosition<TOrientation> linePosition,
  const typename LineTraits<TOrientation>::Placement &placement) {
    return board.applyPlacement<TOrientation>(linePosition, placement);
}

template <typename TOrientation>
void NonogramBoard::applyHint(
  typename HintPosition<TOrientation> hintPosition, HintNumber hintNumber) {
    return board.applyHint<TOrientation>(hintPosition, hintNumber);
}

void NonogramBoard::applyBoard(const Board &board, bool overwriteNone) {
    return this->board.applyBoard(board, overwriteNone);
}

bool NonogramBoard::isInRange(CellPosition cellPosition) const {
    return board.isInRange(cellPosition);
}

bool NonogramBoard::isSolved() const { return board.isSolved(); }

// =========================================================================
// | Explicit instantiations                                               |
// =========================================================================
template RowLength NonogramBoard::getLength<RowOrientation>() const;
template ColumnLength NonogramBoard::getLength<ColumnOrientation>() const;
template RowHintGroup NonogramBoard::getHintGroup<RowOrientation>() const;
template ColumnHintGroup NonogramBoard::getHintGroup<ColumnOrientation>() const;

template typename LineTraits<RowOrientation>::Line
  NonogramBoard::getLine<RowOrientation>(typename LineTraits<RowOrientation>::Index) const;
template typename LineTraits<ColumnOrientation>::Line
  NonogramBoard::getLine<ColumnOrientation>(typename LineTraits<ColumnOrientation>::Index) const;
template void NonogramBoard::applyLine<RowOrientation>(
  typename LinePosition<RowOrientation>, const typename LineTraits<RowOrientation>::Line &, bool);
template void NonogramBoard::applyLine<ColumnOrientation>(
  typename LinePosition<ColumnOrientation>,
  const typename LineTraits<ColumnOrientation>::Line &,
  bool);
template void NonogramBoard::applyPlacement<RowOrientation>(
  typename LinePosition<RowOrientation> linePosition,
  const typename LineTraits<RowOrientation>::Placement &);
template void NonogramBoard::applyPlacement<ColumnOrientation>(
  typename LinePosition<ColumnOrientation> linePosition,
  const typename LineTraits<ColumnOrientation>::Placement &);
template void
  NonogramBoard::applyHint<RowOrientation>(typename HintPosition<RowOrientation>, HintNumber);
template void
  NonogramBoard::applyHint<ColumnOrientation>(typename HintPosition<ColumnOrientation>, HintNumber);

} // namespace VersaNo::Core