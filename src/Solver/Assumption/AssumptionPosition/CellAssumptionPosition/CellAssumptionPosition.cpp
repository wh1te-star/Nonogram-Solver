#include "Solver/Assumption/AssumptionPosition/CellAssumptionPosition/CellAssumptionPosition.h"

#include "Core/Index/Position/CellPosition/CellPosition.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

CellAssumptionPosition::CellAssumptionPosition(CellPosition cellPosition)
    : cellPosition(cellPosition) {}

CellPosition CellAssumptionPosition::getCellPosition() const { return cellPosition; }

} // namespace VersaNo::Solver