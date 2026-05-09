#include "Core/Board/Line/Column.h"

#include "Core/Cell/Cell/Cell.h"

#include <cassert>


namespace VersaNo::Core {


Column::Column(std::vector<Cell> line) : line(line) {}

Column::Column(std::string colorString) {
    for (char colorChar : colorString) {
        switch (colorChar) {
        case BLACK_CHAR:
            line.emplace_back(CellColor::Black);
            break;
        case WHITE_CHAR:
            line.emplace_back(CellColor::White);
            break;
        case NONE_CHAR:
            line.emplace_back(CellColor::None);
            break;
        default:
            assert(false);
            break;
        }
    }
}

const std::vector<Cell> &Column::getLine() const { return line; }

bool Column::operator==(const Column &other) const { return line == other.line; }

bool Column::operator!=(const Column &other) const { return !(*this == other); }

const Cell &Column::operator[](RowIndex index) const { return line[index.value]; }

Cell &Column::operator[](RowIndex index) { return line[index.value]; }

const size_t Column::size() const { return line.size(); }

bool Column::canPlaceBlock(RowIndex startIndex, HintNumber hintNumber) const {
    int start = startIndex.value;
    int end = start + hintNumber.value - 1;
    if (start < 0 || static_cast<int>(line.size()) <= end) {
        return false;
    }
    for (int i = start; i <= end; i++) {
        if (!line[i].canColor(CellColor::Black)) {
            return false;
        }
    }
    if (start > 0) {
        if (line[start - 1].getColor() == CellColor::Black) {
            return false;
        }
    }
    if (end + 1 < static_cast<int>(line.size())) {
        if (line[end + 1].getColor() == CellColor::Black) {
            return false;
        }
    }
    return true;
}

void Column::apply(const Column &determined) {
    for (size_t i = 0; i < line.size(); ++i) {
        RowIndex cellIndex = RowIndex(static_cast<int>(i));
        Cell determinedCell = determined[cellIndex];
        if (determinedCell.getColor() != CellColor::None) {
            line[i] = determinedCell;
        }
    }
}


} // namespace VersaNo::Core
