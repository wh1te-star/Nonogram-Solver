#include "Solver/Assumption/AssumptionEnumerator/HintAssumptionEnumerator/HintAssumptionEnumerator.h"

#include "Board/Board/Board.h"
#include "Placement/Placement/Placement.h"
#include "Solver/Assumption/Assumption/CellAssumption/CellAssumption.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"
#include <cassert>

HintAssumptionEnumerator::HintAssumptionEnumerator()
    : IAssumptionEnumerator() {}

std::vector<std::unique_ptr<IAssumption>> HintAssumptionEnumerator::enumerate(
  const NonogramBoard &nonogramBoard, IAssumptionPosition &assumptionPosition) {
    const auto *hintAssumptionPosition = dynamic_cast<const HintAssumptionPosition *>(
      &assumptionPosition);

    if (!hintAssumptionPosition) {
        assert(false && "Invalid assumption position type for HintAssumptionEnumerator");
        return {};
    }

    Orientation orientation = hintAssumptionPosition->getOrientation();
    CellIndex cellIndex = hintAssumptionPosition->getIndex();
    int hintIndex = hintAssumptionPosition->getHintIndex();

    // Implement later
    return {};
}