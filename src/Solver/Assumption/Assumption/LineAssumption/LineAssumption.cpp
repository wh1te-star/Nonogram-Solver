#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"

#include "Index/CellIndex/CellIndex.h"
#include "Index/CellIndex/RowIndex.h"
#include "Index/CellIndex/ColumnIndex.h"

LineAssumption::LineAssumption(const RowIndex& index, const Line& line)
    : orientation(Orientation::Row), index(index), line(line) {}

LineAssumption::LineAssumption(const ColumnIndex& index, const Line& line)
    : orientation(Orientation::Column), index(index), line(line) {}

void LineAssumption::applyTo(BacktrackBoard &backtrackBoard) const {
    if (orientation == Orientation::Row) {
        backtrackBoard.applyRow(RowIndex(index.getIndex()), static_cast<const Row&>(line), true);
    } else {
        backtrackBoard.applyColumn(ColumnIndex(index.getIndex()), static_cast<const Column&>(line), true);
    }
}