#include "Core/Board/NonogramBoard/NonogramBoard.h"

namespace VersaNo::Core {

NonogramBoard::NonogramBoard(
  Board board, RowHintGroup rowHintGroup, ColumnHintGroup columnHintGroup)
    : board(std::move(board))
    , rowHintGroup(std::move(rowHintGroup))
    , columnHintGroup(std::move(columnHintGroup)) {}

RowLength NonogramBoard::getRowLength() const { return board.getRowLength(); }

ColumnLength NonogramBoard::getColumnLength() const { return board.getColumnLength(); }

Board NonogramBoard::getBoard() const { return board; }

Board &NonogramBoard::getBoard() { return board; }

Cell NonogramBoard::getCell(CellPosition cellPosition) const { return board.getCell(cellPosition); }

template <typename TOrientation>
typename LineTraits<TOrientation>::Line
NonogramBoard::getLine(typename LineTraits<TOrientation>::Index index) const {
    return board.getLine<TOrientation>(index);
}

RowHintGroup NonogramBoard::getRowHintGroup() const { return rowHintGroup; }

ColumnHintGroup NonogramBoard::getColumnHintGroup() const { return columnHintGroup; }

void NonogramBoard::applyCell(CellPosition cellPosition, const Cell &cell, bool overwriteNone) {
    board.applyCell(cellPosition, cell, overwriteNone);
}

template <typename TOrientation>
void NonogramBoard::applyLine(
  typename LinePosition<TOrientation> linePosition,
  const typename Line<TOrientation> &line,
  bool overwriteNone) {
    return board.applyLine<TOrientation>(linePosition, line, overwriteNone);
}

template <typename TOrientation>
void NonogramBoard::applyPlacement(
  typename LinePosition<TOrientation> linePosition,
  const typename Placement<TOrientation> &placement) {
    return board.applyPlacement<TOrientation>(linePosition, placement);
}

template <typename TOrientation>
void NonogramBoard::applyHint(typename HintPosition<TOrientation> hintPosition, HintNumber hintNumber) {
    return board.applyHint<TOrientation>(hintPosition, hintNumber);
}

void NonogramBoard::applyBoard(const Board &board, bool overwriteNone) {
    return this->board.applyBoard(board, overwriteNone);
}

bool NonogramBoard::isInRange(CellPosition cellPosition) const {
    return board.isInRange(cellPosition);
}

bool NonogramBoard::isSolved() const { return board.isSolved(); }


// Explicit instantiations
template typename LineTraits<RowOrientation>::Line 
NonogramBoard::getLine<RowOrientation>(typename LineTraits<RowOrientation>::Index) const;
template typename LineTraits<ColumnOrientation>::Line 
NonogramBoard::getLine<ColumnOrientation>(typename LineTraits<ColumnOrientation>::Index) const;
template void NonogramBoard::applyLine<RowOrientation>(
    LinePosition<RowOrientation>, const Line<RowOrientation> &, bool);
template void NonogramBoard::applyLine<ColumnOrientation>(
    LinePosition<ColumnOrientation>, const Line<ColumnOrientation> &, bool);
template void NonogramBoard::applyPlacement<RowOrientation>(
    LinePosition<RowOrientation>, const Placement<RowOrientation> &);
template void NonogramBoard::applyPlacement<ColumnOrientation>(
    LinePosition<ColumnOrientation>, const Placement<ColumnOrientation> &);
template void NonogramBoard::applyHint<RowOrientation>(HintPosition<RowOrientation>, HintNumber);
template void NonogramBoard::applyHint<ColumnOrientation>(HintPosition<ColumnOrientation>, HintNumber);

} // namespace VersaNo::Core