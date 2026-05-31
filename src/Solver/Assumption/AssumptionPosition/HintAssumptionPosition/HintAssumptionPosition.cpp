#include "Solver/Assumption/AssumptionPosition/HintAssumptionPosition/HintAssumptionPosition.h"

#include "Core/Types/AppliedType/AppliedType.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

template <typename TOrientation>
HintAssumptionPosition<TOrientation>::HintAssumptionPosition(
  Core::HintPosition<TOrientation> hintPosition)
    : hintPosition(hintPosition) {}

template <typename TOrientation>
Core::HintPosition<TOrientation> HintAssumptionPosition<TOrientation>::getHintPosition() const {
    return hintPosition;
}

} // namespace VersaNo::Solver