#include "Core/Position/HintPosition/HintPosition.h"

#include "Core/Types/AppliedType/AppliedType.h"

namespace VersaNo::Core {

HintPosition::HintPosition(Orientation orientation, CellIndex cellIndex, int hintIndex)
    : orientation(orientation), cellIndex(cellIndex), hintIndex(hintIndex) {}

const Orientation &HintPosition::getOrientation() const { return orientation; }

const CellIndex &HintPosition::getCellIndex() const { return cellIndex; }

int HintPosition::getHintIndex() const { return hintIndex; }

bool HintPosition::operator==(const HintPosition &other) const {
    return orientation == other.orientation && cellIndex == other.cellIndex &&
           hintIndex == other.hintIndex;
}

bool HintPosition::operator!=(const HintPosition &other) const { return !(*this == other); }

} // namespace VersaNo::Core