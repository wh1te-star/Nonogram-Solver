#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"

LineAssumptionPosition::LineAssumptionPosition(LinePosition linePosition)
    : linePosition(linePosition) {}

LinePosition LineAssumptionPosition::getLinePosition() const {
    return linePosition;
}
