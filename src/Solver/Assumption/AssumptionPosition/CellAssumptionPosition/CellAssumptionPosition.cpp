#include "Solver/Assumption/AssumptionPosition/CellAssumptionPosition/CellAssumptionPosition.h"

#include "Core/Index/Position/CellPosition/CellPosition.h"

CellAssumptionPosition::CellAssumptionPosition(CellPosition cellPosition)
    : cellPosition(cellPosition){}

CellPosition CellAssumptionPosition::getCellPosition() const { return cellPosition; }