#include "Solver/Assumption/Assumption/CellAssumption/CellAssumption.h"

CellAssumption ::CellAssumption(const CellPosition &cellPosition, const Cell &cell)
    : cellPosition(cellPosition), cell(cell) {}

void CellAssumption ::applyTo(NonogramBoard &nonogramBoard) const {
    nonogramBoard.applyCell(cellPosition, cell, true);
}