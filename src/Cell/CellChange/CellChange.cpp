#include "Cell/CellChange/CellChange.h"

#include "Cell/Cell/Cell.h"
#include "Index/Coordinate/Coordinate.h"
#include <algorithm>

CellChange::CellChange(){}

const std::vector<CellLocation> &CellChange::getChangeLocations() const {
  return changeLocations;
}
