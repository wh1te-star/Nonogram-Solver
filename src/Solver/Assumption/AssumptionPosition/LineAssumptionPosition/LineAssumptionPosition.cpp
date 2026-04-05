#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

LineAssumptionPosition::LineAssumptionPosition(LinePosition linePosition)
    : linePosition(linePosition) {}

LinePosition LineAssumptionPosition::getLinePosition() const { return linePosition; }

} // namespace VersaNo::Solver