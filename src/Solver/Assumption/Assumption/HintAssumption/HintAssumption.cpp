#include "Solver/Assumption/Assumption/HintAssumption/HintAssumption.h"

#include "Index/CellIndex/CellIndex.h"
#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"

HintAssumption::HintAssumption(const HintPosition &hintPosition, const Line &line)
    : hintPosition(hintPosition), line(line) {}

void HintAssumption::applyTo(NonogramBoard &nonogramBoard) const {
    // Implement later
    /*
    if (hintPosition.getOrientation() == Orientation::Row) {
        RowIndex rowIndex = RowIndex(hintPosition.getCellIndex().getIndex());
        nonogramBoard.applyRow(rowIndex, static_cast<const Row &>(line), true);
    } else {
        ColumnIndex columnIndex = ColumnIndex(hintPosition.getCellIndex().getIndex());
        nonogramBoard.applyColumn(columnIndex, static_cast<const Column &>(line), true);
    }
        */
}
