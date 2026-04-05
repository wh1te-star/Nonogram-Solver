#include "Core/Placement/Placement/ColumnPlacement.h"

#include "Core/Cell/Cell/Cell.h"
#include "Core/Cell/CellLocation/CellLocation.h"

namespace VersaN::Core {

ColumnPlacement::ColumnPlacement(std::vector<Cell> placement)
    : Placement(placement) {}

} // namespace VersaN::Core
