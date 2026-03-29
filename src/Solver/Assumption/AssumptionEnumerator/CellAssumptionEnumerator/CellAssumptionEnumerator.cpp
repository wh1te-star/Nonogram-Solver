#include "Solver/Assumption/AssumptionEnumerator/CellAssumptionEnumerator/CellAssumptionEnumerator.h"

#include "Board/Board/Board.h"
#include "Placement/Placement/Placement.h"
#include "Solver/Assumption/Assumption/CellAssumption/CellAssumption.h"
#include "Solver/Assumption/Assumption/LineAssumption/LineAssumption.h"
#include <cassert>

std::vector<std::unique_ptr<IAssumption>> CellAssumptionEnumerator::enumerate(
  const NonogramBoard &nonogramBoard, IAssumptionPosition &assumptionPosition) {
    const auto *cellAssumptionPosition = dynamic_cast<const CellAssumptionPosition *>(
      &assumptionPosition);
    if (!cellAssumptionPosition) {
        assert(false && "Invalid assumption position type for CellAssumptionEnumerator");
        return {};
    }
    RowIndex rowIndex = cellAssumptionPosition->getRowIndex();
    ColumnIndex columnIndex = cellAssumptionPosition->getColumnIndex();

    CellPosition cellPosition{rowIndex, columnIndex};

    std::vector<std::unique_ptr<IAssumption>> assumptions(2);

    assumptions[0] = std::make_unique<CellAssumption>(cellPosition, Cell(White));
    assumptions[1] = std::make_unique<CellAssumption>(cellPosition, Cell(Black));

    return assumptions;
}