#include "Solver/Assumption/Assumption/CellAssumption/CellAssumption.h"

CellAssumption ::CellAssumption(const Coordinate &coordinate, const Cell &cell)
    : coordinate(coordinate), cell(cell) {}

void CellAssumption ::applyTo(BacktrackBoard &backtrackBoard) const {
  backtrackBoard.applyCell(coordinate, cell, true);
}