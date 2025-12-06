#include "Placement/Placement/ColumnPlacement.h"

#include "Cell/Cell/Cell.h"
#include "Cell/CellLocation/CellLocation.h"
#include "Index/Coordinate/Coordinate.h"

ColumnPlacement::ColumnPlacement(std::vector<Cell> placement)
    : Placement(placement) {}
