#include "Solver/Assumption/AssumptionPosition/HintAssumptionPosition/HintAssumptionPosition.h"

using namespace VersaN::Core;
namespace VersaN::Solver {

HintAssumptionPosition::HintAssumptionPosition(HintPosition hintPosition)
    : hintPosition(hintPosition) {}

HintPosition HintAssumptionPosition::getHintPosition() const {
    return hintPosition;
}

} // namespace VersaN::Solver