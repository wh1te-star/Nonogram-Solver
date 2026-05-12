#ifndef VERSANO_CORE_LINETYPE_H
#define VERSANO_CORE_LINETYPE_H

#include "Core/Types/PrimitiveType/ListType/ListType.h"
#include "Core/Cell/Cell/Cell.h"

namespace VersaNo::Core {

template <typename TIndex> class Line : public ListType<Cell, TIndex> {
  public:
    using Base = ListType<Cell, TIndex>;
    using Base::Base;

    template <typename THintNumber>
    bool canPlaceBlock(TIndex startIndex, THintNumber hintNumber) const {
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

    void apply(const Line<Cell> &determined) {
        for (size_t i = 0; i < line.size(); ++i) {
            ColumnIndex cellIndex = ColumnIndex(static_cast<int>(i));
            Cell determinedCell = determined[cellIndex];
            if (determinedCell.getColor() != CellColor::None) {
                line[i] = determinedCell;
            }
        }
    }
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_LINETYPE_H