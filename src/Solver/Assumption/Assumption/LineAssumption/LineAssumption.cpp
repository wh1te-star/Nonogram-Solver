#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"

LineAssumption::LineAssumption(const CellIndex &index, const Line &line)
    : index(index), line(line) {}

void LineAssumption::applyTo(BacktrackBoard &backtrackBoard) const {
    if(is index row) {
        RowIndex rowIndex = index.toRowIndex();
        backtrackBoard.applyRow(rowIndex, line, true);
        return;
    }else{
        ColumnIndex columnIndex = index.toColumnIndex();
        backtrackBoard.applyColumn(columnIndex, line, true);
    }
}
