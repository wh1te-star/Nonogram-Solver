#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"

LineAssumptionPosition::LineAssumptionPosition(Orientation orientation, CellIndex index)
    : orientation(orientation), index(index) {}

Orientation LineAssumptionPosition::getOrientation() const {
    return orientation;
}

CellIndex LineAssumptionPosition::getIndex() const {
    return index;
}