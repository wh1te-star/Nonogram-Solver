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

RowLength Board::getRowLength() const { return rowLength; }

ColumnLength Board::getColumnLength() const { return columnLength; }

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
    using LineType = typename Traits::Line;
    using PeerIndex = typename Traits::PeerIndex;
    using PeerLength = typename Traits::PeerLength;

    PeerLength peerLength;
    if constexpr (std::is_same_v<TOrientation, RowOrientation>) {
        peerLength = getColumnLength();
    } else {
        peerLength = getRowLength();
    }

    std::vector<Cell> cells;

    for (PeerIndex peerIndex : PeerIndex::closedRange(0, peerLength.value - 1)) {
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

for (PeerIndex peerIndex : PeerIndex::closedRange(0, line.size() - 1)) {
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
    using PeerIndex = typename Traits::PeerIndex;

    if constexpr (std::is_same_v<TOrientation, RowOrientation>) {
        assert(placement.size() == columnLength.value);
    } else {
        assert(placement.size() == rowLength.value);
    }

    for (PeerIndex peerIndex : PeerIndex::closedRange(0, placement.size() - 1)) {
        CellPosition cellPosition;
        if constexpr (std::is_same_v<TOrientation, RowOrientation>) {
            cellPosition = CellPosition(linePosition, peerIndex);
        } else {
            cellPosition = CellPosition(peerIndex, linePosition);
        }

        Cell cell = placement[peerIndex];
        applyCell(cellPosition, cell);
    }
}

template <typename TOrientation>
void Board::applyHint(typename HintPosition<TOrientation> hintPosition, HintNumber hintNumber) {
    using Traits = LineTraits<TOrientation>;
    using PeerIndex = typename Traits::PeerIndex;

    typename Traits::Index lineIndex = hintPosition.getLineIndex();

    PeerIndex startIndex = hintPosition.getInlineIndex();
    PeerIndex lastIndex = startIndex + (hintNumber - 1);

    for (PeerIndex peerIndex : PeerIndex::closedRange(startIndex, lastIndex)) {
        CellPosition cellPosition;
        if constexpr (std::is_same_v<TOrientation, RowOrientation>) {
            cellPosition = CellPosition(lineIndex, peerIndex);
        } else {
            cellPosition = CellPosition(peerIndex, lineIndex);
        }

        applyCell(cellPosition, Cell::Black());
    }
}

void Board::applyBoard(const Board &board, bool overwriteNone) {
    for (RowIndex rowIndex : RowIndex::closedRange(0, rowLength.value - 1)) {
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

} // namespace VersaNo::Core