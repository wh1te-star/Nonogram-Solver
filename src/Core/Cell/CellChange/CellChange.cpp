#include "Core/Cell/CellChange/CellChange.h"

#include "Core/Cell/Cell/Cell.h"

#include <algorithm>

namespace VersaNo::Core {

CellChange::CellChange() {}

const std::vector<CellLocation> &CellChange::getChangeLocations() const { return changeLocations; }

} // namespace VersaNo::Core