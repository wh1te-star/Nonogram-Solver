#include "Solver/Assumption/AssumptionEnumerator/CellAssumptionEnumerator/CellAssumptionEnumerator.h"

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Board/Board/Board.h"
#include "Solver/Assumption/Assumption/CellAssumption/CellAssumption.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"

#include <cassert>

using namespace VersaNo::Core;
namespace VersaNo::Solver {

std::vector<std::unique_ptr<IAssumption>> CellAssumptionEnumerator::enumerate(
  const NonogramBoard &nonogramBoard, IAssumptionPosition &assumptionPosition) {
    const auto *cellAssumptionPosition = dynamic_cast<const CellAssumptionPosition *>(
      &assumptionPosition);
    if (!cellAssumptionPosition) {
        assert(false && "Invalid assumption position type for CellAssumptionEnumerator");
        return {};
    }
    CellPosition cellPosition = cellAssumptionPosition->getCellPosition();

    std::vector<std::unique_ptr<IAssumption>> assumptions(2);

    assumptions[0] = std::make_unique<CellAssumption>(cellPosition, Cell(White));
    assumptions[1] = std::make_unique<CellAssumption>(cellPosition, Cell(Black));

    return assumptions;
}

} // namespace VersaNo::Solver