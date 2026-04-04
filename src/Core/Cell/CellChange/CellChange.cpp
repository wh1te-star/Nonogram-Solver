#include "Core/Cell/CellChange/CellChange.h"

#include "Core/Cell/Cell/Cell.h"
#include <algorithm>

CellChange::CellChange(){}

const std::vector<CellLocation> &CellChange::getChangeLocations() const {
  return changeLocations;
}
