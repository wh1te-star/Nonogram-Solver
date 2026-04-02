#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"

#include "Index/CellIndex/CellIndex.h"
#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"

LineAssumption::LineAssumption(const LinePosition &linePosition, const Line &line)
    : linePosition(linePosition), line(line) {}

void LineAssumption::applyTo(NonogramBoard &nonogramBoard) const {
    if (linePosition.getOrientation() == Orientation::Row) {
        RowIndex rowIndex = RowIndex(linePosition.getCellIndex().getIndex());
        nonogramBoard.applyRow(rowIndex, static_cast<const Row &>(line), true);
    } else {
        ColumnIndex columnIndex = ColumnIndex(linePosition.getCellIndex().getIndex());
        nonogramBoard.applyColumn(columnIndex, static_cast<const Column &>(line), true);
    }
}