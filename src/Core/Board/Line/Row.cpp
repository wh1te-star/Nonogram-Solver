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
}

void Row::apply(const Row &determined) {
}


} // namespace VersaNo::Core
