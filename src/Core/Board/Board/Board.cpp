#include "Core/Board/Board/Board.h"

#include "Core/Cell/Cell/Cell.h"
#include "Core/Types/AppliedType/AppliedType.h"

#include <cassert>
#include <typeinfo>

namespace VersaNo::Core {

Board::Board(RowLength rowLength, ColumnLength columnLength)
    : rowLength(std::move(rowLength)), columnLength(std::move(columnLength)) {
    board.resize(rowLength.value, std::vector<Cell>(columnLength.value, Cell()));
}

bool Board::operator==(const Board &other) const { return board == other.board; }

bool Board::operator!=(const Board &other) const { return !(*this == other); }

template <typename TOrientation>
typename LineTraits<TOrientation>::Length Board::getLength() const {
    if constexpr (std::is_same_v<TOrientation, RowOrientation>) {
        return rowLength;
    } else {
        return columnLength;
    }
}

Cell Board::getCell(CellPosition cellPosition) const {
    assert(isInRange(cellPosition));
    RowIndex rowIndex = cellPosition.getRowIndex();
    ColumnIndex columnIndex = cellPosition.getColumnIndex();
    return board[rowIndex.value][columnIndex.value];
}

template <typename TOrientation>
typename LineTraits<TOrientation>::Line
Board::getLine(typename LineTraits<TOrientation>::Index index) const {
    using Traits = LineTraits<TOrientation>;
    using PeerOrientation = typename Traits::PeerOrientation;
    using LineType = typename Traits::Line;
    using PeerIndex = typename Traits::PeerIndex;
    using PeerLength = typename Traits::PeerLength;

    PeerLength peerLength = getLength<PeerOrientation>();

    std::vector<Cell> cells;

    for (PeerIndex peerIndex : PeerIndex::closedRangeUp(0, peerLength.value - 1)) {
        Cell cell;
        if constexpr (std::is_same_v<TOrientation, RowOrientation>) {
            cell = getCell(CellPosition(index, peerIndex));
        } else {
            cell = getCell(CellPosition(peerIndex, index));
        }

        cells.push_back(cell);
    }

    return LineType(cells);
}

void Board::applyCell(CellPosition cellPosition, const Cell &cell, bool overwriteNone) {
    if (!isInRange(cellPosition)) {
        return;
    }
    if (!overwriteNone && cell.getColor() == None) {
        return;
    }

    RowIndex rowIndex = cellPosition.getRowIndex();
    ColumnIndex columnIndex = cellPosition.getColumnIndex();
    board[rowIndex.value][columnIndex.value] = cell;
}

template <typename TOrientation>
void Board::applyLine(
  typename LinePosition<TOrientation> linePosition,
  const typename LineTraits<TOrientation>::Line &line,
  bool overwriteNone) {
    using Traits = LineTraits<TOrientation>;
    using Index = typename Traits::Index;
    using PeerIndex = typename Traits::PeerIndex;

    if constexpr (std::is_same_v<TOrientation, RowOrientation>) {
        assert(line.size() == columnLength.value);
    } else {
        assert(line.size() == rowLength.value);
    }

    Index lineIndex = linePosition.getIndex();

    for (PeerIndex peerIndex : PeerIndex::closedRangeUp(0, (int)line.size() - 1)) {
        Cell cell = line[peerIndex];

        if constexpr (std::is_same_v<TOrientation, RowOrientation>) {
            CellPosition cellPosition(lineIndex, peerIndex);
            applyCell(cellPosition, cell, overwriteNone);
        } else {
            CellPosition cellPosition(peerIndex, lineIndex);
            applyCell(cellPosition, cell, overwriteNone);
        }
    }
}

template <typename TOrientation>
void Board::applyPlacement(
  typename LinePosition<TOrientation> linePosition,
  const typename LineTraits<TOrientation>::Placement &placement) {
    using Traits = LineTraits<TOrientation>;
    using Index = typename Traits::Index;
    using PeerIndex = typename Traits::PeerIndex;

    if constexpr (std::is_same_v<TOrientation, RowOrientation>) {
        assert(placement.size() == columnLength.value);
    } else {
        assert(placement.size() == rowLength.value);
    }

    for (PeerIndex peerIndex : PeerIndex::closedRangeUp(0, (int)placement.size() - 1)) {
        Index index = linePosition.getIndex();
        Cell cell = placement[peerIndex];
        if constexpr (std::is_same_v<TOrientation, RowOrientation>) {
            CellPosition cellPosition(index, peerIndex);
            applyCell(cellPosition, cell);
        } else {
            CellPosition cellPosition(peerIndex, index);
            applyCell(cellPosition, cell);
        }
    }
}

template <typename TOrientation>
void Board::applyHint(typename HintPosition<TOrientation> hintPosition, HintNumber hintNumber) {
    using Traits = LineTraits<TOrientation>;
    using Index = typename Traits::Index;
    using PeerIndex = typename Traits::PeerIndex;

    Index inlineIndex = hintPosition.getLineIndex();
    PeerIndex startIndex = hintPosition.getInlineIndex();
    PeerIndex lastIndex = startIndex + (hintNumber.value - 1);
    Cell cell = Cell(CellColor::Black);

    for (PeerIndex peerIndex : PeerIndex::closedRangeUp(startIndex.value, lastIndex.value)) {
        if constexpr (std::is_same_v<TOrientation, RowOrientation>) {
            CellPosition cellPosition = CellPosition(inlineIndex, peerIndex);
            applyCell(cellPosition, cell);
        } else {
            CellPosition cellPosition = CellPosition(peerIndex, inlineIndex);
            applyCell(cellPosition, cell);
        }
    }
}

void Board::applyBoard(const Board &board, bool overwriteNone) {
    for (RowIndex rowIndex : RowIndex::closedRangeUp(0, rowLength.value - 1)) {
        Row rowLine = board.getLine<RowOrientation>(rowIndex);
        LinePosition<RowOrientation> rowLinePosition(rowIndex);
        applyLine<RowOrientation>(rowLinePosition, rowLine, overwriteNone);
    }
}

bool Board::isInRange(CellPosition cellPosition) const {
    RowIndex rowIndex = cellPosition.getRowIndex();
    ColumnIndex columnIndex = cellPosition.getColumnIndex();
    if (columnIndex < ColumnLength(0) || columnLength <= columnIndex) {
        return false;
    }
    if (rowIndex < RowLength(0) || rowLength <= rowIndex) {
        return false;
    }
    return true;
}

bool Board::isSolved() const {
    for (std::vector<Cell> row : board) {
        for (Cell cell : row) {
            if (cell.getColor() == None) {
                return false;
            }
        }
    }
    return true;
}

// Explicit Instantiations
template RowLength Board::getLength<RowOrientation>() const;
template ColumnLength Board::getLength<ColumnOrientation>() const;
template LineTraits<RowOrientation>::Line
  Board::getLine<RowOrientation>(LineTraits<RowOrientation>::Index) const;
template LineTraits<ColumnOrientation>::Line
  Board::getLine<ColumnOrientation>(LineTraits<ColumnOrientation>::Index) const;
template void Board::applyLine<RowOrientation>(
  LinePosition<RowOrientation>, const LineTraits<RowOrientation>::Line &, bool);
template void Board::applyLine<ColumnOrientation>(
  LinePosition<ColumnOrientation>, const LineTraits<ColumnOrientation>::Line &, bool);
template void Board::applyPlacement<RowOrientation>(
  LinePosition<RowOrientation>, const LineTraits<RowOrientation>::Placement &);
template void Board::applyPlacement<ColumnOrientation>(
  LinePosition<ColumnOrientation>, const LineTraits<ColumnOrientation>::Placement &);
template void Board::applyHint<RowOrientation>(HintPosition<RowOrientation>, HintNumber);
template void Board::applyHint<ColumnOrientation>(HintPosition<ColumnOrientation>, HintNumber);

} // namespace VersaNo::Core