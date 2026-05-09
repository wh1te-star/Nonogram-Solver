#include "Solver/Assumption/AssumptionPosition/HintAssumptionPosition/HintAssumptionPosition.h"

#include "Core/Types/AppliedType/AppliedType.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

HintAssumptionPosition::HintAssumptionPosition(HintPosition hintPosition)
    : hintPosition(hintPosition) {}

HintPosition HintAssumptionPosition::getHintPosition() const { return hintPosition; }

} // namespace VersaNo::Solver