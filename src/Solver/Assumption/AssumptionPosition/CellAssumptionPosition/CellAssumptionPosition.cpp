#include "Solver/Assumption/AssumptionPosition/CellAssumptionPosition/CellAssumptionPosition.h"

#include "Core/Index/Position/CellPosition/CellPosition.h"

using namespace VersaN::Core;
namespace VersaN::Solver {

CellAssumptionPosition::CellAssumptionPosition(CellPosition cellPosition)
    : cellPosition(cellPosition){}

CellPosition CellAssumptionPosition::getCellPosition() const { return cellPosition; }

} // namespace VersaN::Solver