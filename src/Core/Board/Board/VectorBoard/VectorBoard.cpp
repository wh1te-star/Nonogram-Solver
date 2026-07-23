#include "Core/Board/Board/VectorBoard/VectorBoard.h"

#include "Core/Cell/Cell/Cell.h"
#include "Core/Types/AppliedType/AppliedType.h"

#include <cassert>
#include <typeinfo>

namespace VersaNo::Core {

VectorBoard::VectorBoard(RowLength rowLength, ColumnLength columnLength)
    : rowLength(std::move(rowLength)), columnLength(std::move(columnLength)) {
    board.resize(rowLength.value, std::vector<Cell>(columnLength.value, Cell()));
}
std::unique_ptr<IBoard> VectorBoard::clone() const {
    return std::make_unique<VectorBoard>(*this);
}

bool VectorBoard::operator==(const VectorBoard &other) const { return board == other.board; }
bool VectorBoard::operator!=(const VectorBoard &other) const { return !(*this == other); }

// =========================================================================
// | Getters                                                               |
// =========================================================================
RowLength VectorBoard::getRowLength() const { return rowLength; }

ColumnLength VectorBoard::getColumnLength() const { return columnLength; }

template <typename TOrientation>
typename LineTraits<TOrientation>::Length VectorBoard::getLength() const {
    if constexpr (std::is_same_v<TOrientation, RowOrientation>) {
        return rowLength;
    } else {
        return columnLength;
    }
}

Cell VectorBoard::getCell(CellPosition cellPosition) const {
    assert(isInRange(cellPosition));
    RowIndex rowIndex = cellPosition.getRowIndex();
    ColumnIndex columnIndex = cellPosition.getColumnIndex();
    return board[rowIndex.value][columnIndex.value];
}

Row VectorBoard::getRow(RowIndex index) const { return getLine<RowOrientation>(index); }

Column VectorBoard::getColumn(ColumnIndex index) const { return getLine<ColumnOrientation>(index); }

template <typename TOrientation>
typename LineTraits<TOrientation>::Line
VectorBoard::getLine(typename LineTraits<TOrientation>::Index index) const {
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

// =========================================================================
// | Applyers                                                              |
// =========================================================================

void VectorBoard::applyCell(CellPosition cellPosition, const Cell &cell, bool overwriteNone) {
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

void VectorBoard::applyRow(
  LinePosition<RowOrientation> linePosition, const Row &row, bool overwriteNone) {
    applyLine<RowOrientation>(linePosition, row, overwriteNone);
}

void VectorBoard::applyColumn(
  LinePosition<ColumnOrientation> linePosition, const Column &column, bool overwriteNone) {
    applyLine<ColumnOrientation>(linePosition, column, overwriteNone);
}

template <typename TOrientation>
void VectorBoard::applyLine(
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

void VectorBoard::applyRowPlacement(
  LinePosition<RowOrientation> linePosition, const RowPlacement &placement) {
    applyPlacement<RowOrientation>(linePosition, placement);
}

void VectorBoard::applyColumnPlacement(
  LinePosition<ColumnOrientation> linePosition, const ColumnPlacement &placement) {
    applyPlacement<ColumnOrientation>(linePosition, placement);
}

template <typename TOrientation>
void VectorBoard::applyPlacement(
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

void VectorBoard::applyRowHint(HintPosition<RowOrientation> hintPosition, HintNumber hintNumber) {
    applyHint<RowOrientation>(hintPosition, hintNumber);
}

void VectorBoard::applyColumnHint(
  HintPosition<ColumnOrientation> hintPosition, HintNumber hintNumber) {
    applyHint<ColumnOrientation>(hintPosition, hintNumber);
}

template <typename TOrientation>
void VectorBoard::applyHint(
  typename HintPosition<TOrientation> hintPosition, HintNumber hintNumber) {
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

void VectorBoard::applyBoard(const IBoard &board, bool overwriteNone) {
    for (RowIndex rowIndex : RowIndex::closedRangeUp(0, rowLength.value - 1)) {
        Row rowLine = board.getRow(rowIndex);
        LinePosition<RowOrientation> rowLinePosition(rowIndex);
        applyLine<RowOrientation>(rowLinePosition, rowLine, overwriteNone);
    }
}

// =========================================================================
// | Utilities                                                             |
// =========================================================================

bool VectorBoard::isSolved() const {
    for (std::vector<Cell> row : board) {
        for (Cell cell : row) {
            if (cell.getColor() == None) {
                return false;
            }
        }
    }
    return true;
}

bool VectorBoard::isInRange(CellPosition cellPosition) const {
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

// =========================================================================
// | Explicit instantiations                                               |
// =========================================================================
template RowLength VectorBoard::getLength<RowOrientation>() const;
template ColumnLength VectorBoard::getLength<ColumnOrientation>() const;
template LineTraits<RowOrientation>::Line
  VectorBoard::getLine<RowOrientation>(LineTraits<RowOrientation>::Index) const;
template LineTraits<ColumnOrientation>::Line
  VectorBoard::getLine<ColumnOrientation>(LineTraits<ColumnOrientation>::Index) const;
template void VectorBoard::applyLine<RowOrientation>(
  LinePosition<RowOrientation>, const LineTraits<RowOrientation>::Line &, bool);
template void VectorBoard::applyLine<ColumnOrientation>(
  LinePosition<ColumnOrientation>, const LineTraits<ColumnOrientation>::Line &, bool);
template void VectorBoard::applyPlacement<RowOrientation>(
  LinePosition<RowOrientation>, const LineTraits<RowOrientation>::Placement &);
template void VectorBoard::applyPlacement<ColumnOrientation>(
  LinePosition<ColumnOrientation>, const LineTraits<ColumnOrientation>::Placement &);
template void VectorBoard::applyHint<RowOrientation>(HintPosition<RowOrientation>, HintNumber);
template void
  VectorBoard::applyHint<ColumnOrientation>(HintPosition<ColumnOrientation>, HintNumber);

} // namespace VersaNo::Core