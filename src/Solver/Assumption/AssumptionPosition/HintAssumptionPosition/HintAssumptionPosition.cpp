#include "Solver/Assumption/AssumptionPosition/HintAssumptionPosition/HintAssumptionPosition.h"

HintAssumptionPosition::HintAssumptionPosition(HintPosition hintPosition)
    : hintPosition(hintPosition) {}

HintPosition HintAssumptionPosition::getHintPosition() const {
    return hintPosition;
}