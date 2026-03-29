#include "Solver/Assumption/Assumption/CellAssumption/CellAssumption.h"

CellAssumption ::CellAssumption(const Coordinate &coordinate, const Cell &cell)
    : coordinate(coordinate), cell(cell) {}

void CellAssumption ::applyTo(NonogramBoard &nonogramBoard) const {
    nonogramBoard.applyCell(coordinate, cell, true);
}