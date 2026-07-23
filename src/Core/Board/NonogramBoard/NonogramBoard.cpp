#include "Core/Board/NonogramBoard/NonogramBoard.h"

namespace VersaNo::Core {

NonogramBoard::NonogramBoard(
  std::shared_ptr<IBoard> board, RowHintGroup rowHintGroup, ColumnHintGroup columnHintGroup)
    : board(board)
    , rowHintGroup(std::move(rowHintGroup))
    , columnHintGroup(std::move(columnHintGroup)) {}

// =========================================================================
// | Getters                                                               |
// =========================================================================

const IBoard &NonogramBoard::getBoard() const {
    return *board;
}

IBoard &NonogramBoard::getBoard() {
    return *board;
}

RowHintGroup NonogramBoard::getRowHintGroup() const {
    return rowHintGroup;
}

ColumnHintGroup NonogramBoard::getColumnHintGroup() const {
    return columnHintGroup;
}

template <typename TOrientation>
typename LineTraits<TOrientation>::HintGroup NonogramBoard::getHintGroup() const {
    if constexpr (std::is_same_v<TOrientation, RowOrientation>) {
        return rowHintGroup;
    } else {
        return columnHintGroup;
    }
}

RowLength NonogramBoard::getRowLength() const {
    return board->getRowLength();
}

ColumnLength NonogramBoard::getColumnLength() const {
    return board->getColumnLength();
}

template <typename TOrientation>
typename LineTraits<TOrientation>::Length NonogramBoard::getLength() const {
    return board->getLength<TOrientation>();
}

Cell NonogramBoard::getCell(CellPosition cellPosition) const {
    return board->getCell(cellPosition);
}

Row NonogramBoard::getRow(RowIndex index) const {
    return board->getRow(index);
}

Column NonogramBoard::getColumn(ColumnIndex index) const {
    return board->getColumn(index);
}

template <typename TOrientation>
typename LineTraits<TOrientation>::Line NonogramBoard::getLine(typename LineTraits<TOrientation>::Index index) const {
    return board->getLine<TOrientation>(index);
}

// =========================================================================
// | Applyers                                                              |
// =========================================================================

void NonogramBoard::applyCell(CellPosition coordinate, const Cell &cell, bool overrideNone) {
    board->applyCell(coordinate, cell, overrideNone);
}

void NonogramBoard::applyRow(LinePosition<RowOrientation> linePosition, const Row &row, bool overwriteNone) {
    board->applyRow(linePosition, row, overwriteNone);
}

void NonogramBoard::applyColumn(
  LinePosition<ColumnOrientation> linePosition, const Column &column, bool overwriteNone) {
    board->applyColumn(linePosition, column, overwriteNone);
}

template <typename TOrientation>
void NonogramBoard::applyLine(
  typename LinePosition<TOrientation> linePosition,
  const typename LineTraits<TOrientation>::Line &line,
  bool overwriteNone) {
    board->applyLine<TOrientation>(linePosition, line, overwriteNone);
}

void NonogramBoard::applyRowPlacement(LinePosition<RowOrientation> linePosition, const RowPlacement &placement) {
    board->applyRowPlacement(linePosition, placement);
}

void NonogramBoard::applyColumnPlacement(
  LinePosition<ColumnOrientation> linePosition, const ColumnPlacement &placement) {
    board->applyColumnPlacement(linePosition, placement);
}

template <typename TOrientation>
void NonogramBoard::applyPlacement(
  typename LinePosition<TOrientation> linePosition,
  const typename LineTraits<TOrientation>::Placement &placement) {
    board->applyPlacement<TOrientation>(linePosition, placement);
}

void NonogramBoard::applyRowHint(HintPosition<RowOrientation> hintPosition, HintNumber hintNumber) {
    board->applyRowHint(hintPosition, hintNumber);
}

void NonogramBoard::applyColumnHint(HintPosition<ColumnOrientation> hintPosition, HintNumber hintNumber) {
    board->applyColumnHint(hintPosition, hintNumber);
}

template <typename TOrientation>
void NonogramBoard::applyHint(typename HintPosition<TOrientation> hintPosition, HintNumber hintNumber) {
    board->applyHint<TOrientation>(hintPosition, hintNumber);
}

void NonogramBoard::applyBoard(const IBoard &board, bool overwriteNone) {
    this->board->applyBoard(board, overwriteNone);
}

// =========================================================================
// | Utilities                                                             |
// =========================================================================

bool NonogramBoard::isSolved() const {
    return board->isSolved();
}

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