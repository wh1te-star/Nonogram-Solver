#include "Core/Index/Position/HintPosition/HintPosition.h"

#include "Core/Board/BoardLength/ColumnLength.h"
#include "Core/Board/BoardLength/RowLength.h"
#include "Core/Index/CellIndex/ColumnIndex.h"
#include "Core/Index/CellIndex/RowIndex.h"

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
