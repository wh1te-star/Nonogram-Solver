#include "Solver/Assumption/AssumptionPosition/CellAssumptionPosition/CellAssumptionPosition.h"

CellAssumptionPosition::CellAssumptionPosition(RowIndex row, ColumnIndex column)
    : row(row), column(column) {}

RowIndex CellAssumptionPosition::getRow() const {
    return row;
}

ColumnIndex CellAssumptionPosition::getColumn() const {
    return column;
}