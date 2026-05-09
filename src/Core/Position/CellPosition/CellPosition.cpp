#include "Core/Position/CellPosition/CellPosition.h"

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Index/CellIndex/ColumnIndex.h"
#include "Core/Index/CellIndex/RowIndex.h"

namespace VersaNo::Core {

CellPosition::CellPosition(RowIndex rowIndex, ColumnIndex columnIndex)
    : rowIndex(rowIndex), columnIndex(columnIndex) {}

const RowIndex &CellPosition::getRowIndex() const { return rowIndex; }

const ColumnIndex &CellPosition::getColumnIndex() const { return columnIndex; }

bool CellPosition::operator==(const CellPosition &other) const {
    return rowIndex == other.rowIndex && columnIndex == other.columnIndex;
}

bool CellPosition::operator!=(const CellPosition &other) const { return !(*this == other); }

CellPosition CellPosition::move(int rowShift, int columnShift) const {
    return CellPosition(rowIndex + RowLength(rowShift), columnIndex + ColumnLength(columnShift));
}

CellPosition CellPosition::move(RowLength rowShift, ColumnLength columnShift) const {
    return CellPosition(rowIndex + rowShift, columnIndex + columnShift);
}

} // namespace VersaNo::Core