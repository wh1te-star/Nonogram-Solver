#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"

using namespace VersaN::Core;
namespace VersaN::Solver {

LineAssumptionPosition::LineAssumptionPosition(LinePosition linePosition)
    : linePosition(linePosition) {}

LinePosition LineAssumptionPosition::getLinePosition() const {
    return linePosition;
}

} // namespace VersaN::Solver