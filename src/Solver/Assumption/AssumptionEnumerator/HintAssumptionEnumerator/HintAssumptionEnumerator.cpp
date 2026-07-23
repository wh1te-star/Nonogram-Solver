#include "Solver/Assumption/AssumptionEnumerator/HintAssumptionEnumerator/HintAssumptionEnumerator.h"

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/Assumption/Assumption/CellAssumption/CellAssumption.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"

#include <cassert>

using namespace VersaNo::Core;
namespace VersaNo::Solver {

HintAssumptionEnumerator::HintAssumptionEnumerator() : IAssumptionEnumerator() {}

std::vector<std::unique_ptr<IAssumption>> HintAssumptionEnumerator::enumerate(
  const NonogramBoard &nonogramBoard, IAssumptionPosition &assumptionPosition) {
    // Implement later
    /*
    const auto *hintAssumptionPosition = dynamic_cast<const HintAssumptionPosition *>(
      &assumptionPosition);

    if (!hintAssumptionPosition) {
        assert(false && "Invalid assumption position type for HintAssumptionEnumerator");
        return {};
    }
    HintPosition hintPosition = hintAssumptionPosition->getHintPosition();
    */

    return {};
}

// explicit template instantiation
// template class HintAssumptionEnumerator<Core::RowOrientation>;
// template class HintAssumptionEnumerator<Core::ColumnOrientation>;

} // namespace VersaNo::Solver