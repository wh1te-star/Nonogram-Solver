#include "Solver/Assumption/AssumptionPosition/CellAssumptionPosition/CellAssumptionPosition.h"

CellAssumptionPosition::CellAssumptionPosition(RowIndex row, ColumnIndex column)
    : row(row), column(column) {}

RowIndex CellAssumptionPosition::getRowIndex() const { return row; }

ColumnIndex CellAssumptionPosition::getColumnIndex() const { return column; }