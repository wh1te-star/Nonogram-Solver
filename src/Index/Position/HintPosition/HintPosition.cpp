#include "Index/Position/HintPosition/HintPosition.h"

#include "Board/BoardLength/ColumnLength.h"
#include "Board/BoardLength/RowLength.h"
#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"

HintPosition::HintPosition(Orientation orientation, CellIndex index, int hintIndex)
    : orientation(orientation), index(index), hintIndex(hintIndex) {}

const Orientation &HintPosition::getOrientation() const { return orientation; }

const CellIndex &HintPosition::getCellIndex() const { return index; }

int HintPosition::getHintIndex() const { return hintIndex; }

bool HintPosition::operator==(const HintPosition &other) const {
    return orientation == other.orientation && index == other.index && hintIndex == other.hintIndex;
}

bool HintPosition::operator!=(const HintPosition &other) const { return !(*this == other); }
