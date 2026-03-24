#include "Solver/Assumption/AssumptionPosition/HintAssumptionPosition/HintAssumptionPosition.h"

HintAssumptionPosition::HintAssumptionPosition(Orientation orientation, CellIndex index, int hintIndex)
    : orientation(orientation), index(index), hintIndex(hintIndex) {}

Orientation HintAssumptionPosition::getOrientation() const {
    return orientation;
}

CellIndex HintAssumptionPosition::getIndex() const {
    return index;
}

int HintAssumptionPosition::getHintIndex() const {
    return hintIndex;
}
