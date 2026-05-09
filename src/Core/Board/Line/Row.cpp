#include "Core/Board/Line/Row.h"

#include "Core/Cell/Cell/Cell.h"

#include <cassert>


namespace VersaNo::Core {


Row::Row(std::vector<Cell> line) : line(line) {}

Row::Row(std::string colorString) {
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

const std::vector<Cell> &Row::getLine() const { return line; }

bool Row::operator==(const Row &other) const { return line == other.line; }

bool Row::operator!=(const Row &other) const { return !(*this == other); }

const Cell &Row::operator[](ColumnIndex index) const { return line[index.value]; }

Cell &Row::operator[](ColumnIndex index) { return line[index.value]; }

const size_t Row::size() const { return line.size(); }

bool Row::canPlaceBlock(ColumnIndex startIndex, HintNumber hintNumber) const {
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

void Row::apply(const Row &determined) {
    for (size_t i = 0; i < line.size(); ++i) {
        ColumnIndex cellIndex = ColumnIndex(static_cast<int>(i));
        Cell determinedCell = determined[cellIndex];
        if (determinedCell.getColor() != CellColor::None) {
            line[i] = determinedCell;
        }
    }
}


} // namespace VersaNo::Core
