#include "Core/Placement/Placement/RowPlacement.h"

#include "Core/Cell/Cell/Cell.h"
#include "Core/Cell/CellLocation/CellLocation.h"

namespace VersaN::Core {

RowPlacement::RowPlacement(std::vector<Cell> placement) : Placement(placement) {}

} // namespace VersaN::Core
