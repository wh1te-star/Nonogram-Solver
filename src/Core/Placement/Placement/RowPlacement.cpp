#include "Core/Placement/Placement/RowPlacement.h"

#include "Core/Cell/Cell/Cell.h"

#include <cassert>

namespace VersaNo::Core {

RowPlacement::RowPlacement(std::vector<Cell> placement) : placement(placement) {
    assert(!hasNone());
}

RowPlacement::RowPlacement(std::string colorString) {
    for (char colorChar : colorString) {
        switch (colorChar) {
        case BLACK_CHAR:
            placement.emplace_back(CellColor::Black);
            break;
        case WHITE_CHAR:
            placement.emplace_back(CellColor::White);
            break;
        default:
            assert(false);
            break;
        }
    }
}

RowPlacement::RowPlacement(HintNumber hintNumber) {
    for (int i = 0; i < hintNumber.value; i++) {
        placement.emplace_back(Cell(CellColor::Black));
    }
}

const std::vector<Cell> &RowPlacement::getPlacement() const { return placement; }

bool RowPlacement::operator==(const RowPlacement &other) const {
    return placement == other.placement;
}

bool RowPlacement::operator!=(const RowPlacement &other) const {
    return !(placement == other.placement);
}

Cell RowPlacement::operator[](const ColumnIndex &index) const { return placement[index.value]; }

RowPlacement RowPlacement::operator+(const RowPlacement &other) const {
    std::vector<Cell> newPlacement;
    newPlacement.reserve(placement.size() + other.placement.size());
    newPlacement.insert(newPlacement.end(), placement.begin(), placement.end());
    newPlacement.insert(newPlacement.end(), other.placement.begin(), other.placement.end());
    return RowPlacement(newPlacement);
}

RowPlacement &RowPlacement::operator+=(const RowPlacement &other) {
    placement.insert(placement.end(), other.placement.begin(), other.placement.end());
    assert(!hasNone());
    return *this;
}

bool RowPlacement::hasNone() const {
    bool hasNoneColor = false;
    for (Cell cell : placement) {
        if (cell.getColor() == CellColor::None) {
            hasNoneColor = true;
            break;
        }
    }
    return hasNoneColor;
}

const size_t RowPlacement::size() const { return placement.size(); }

const std::vector<ColumnIndex> RowPlacement::getHintIndex() const {
    std::vector<ColumnIndex> hintIndexList;
    for (size_t i = 0; i < placement.size(); ++i) {
        if (i <= 0 || placement[i - 1].getColor() != CellColor::Black) {
            if (placement[i].getColor() == CellColor::Black) {
                hintIndexList.emplace_back(static_cast<int>(i));
            }
        }
    }
    return hintIndexList;
}

} // namespace VersaNo::Core
