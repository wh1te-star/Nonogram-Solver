#include "Solver/Assumption/AssumptionPosition/CellAssumptionPosition/CellAssumptionPosition.h"

CellAssumptionPosition::CellAssumptionPosition(CellPosition cellPosition)
    : cellPosition(cellPosition){}

CellPosition CellAssumptionPosition::getCellPosition() const { return cellPosition; }