#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

template <typename TOrientation>
LineAssumptionPosition<TOrientation>::LineAssumptionPosition(Core::LinePosition<TOrientation> linePosition)
    : linePosition(linePosition) {}

template <typename TOrientation>
Core::LinePosition<TOrientation> LineAssumptionPosition<TOrientation>::getLinePosition() const {
    return linePosition;
}

} // namespace VersaNo::Solver