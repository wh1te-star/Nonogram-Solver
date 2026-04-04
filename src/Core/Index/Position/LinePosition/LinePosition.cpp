#include "Core/Index/Position/LinePosition/LinePosition.h"

#include "Core/Board/BoardLength/ColumnLength.h"
#include "Core/Board/BoardLength/RowLength.h"
#include "Core/Index/CellIndex/ColumnIndex.h"
#include "Core/Index/CellIndex/RowIndex.h"

LinePosition::LinePosition(Orientation orientation, CellIndex cellIndex)
    : orientation(orientation), cellIndex(cellIndex) {}

const Orientation &LinePosition::getOrientation() const { return orientation; }

const CellIndex &LinePosition::getCellIndex() const { return cellIndex; }

bool LinePosition::operator==(const LinePosition &other) const {
    return orientation== other.orientation && cellIndex == other.cellIndex;
}

bool LinePosition::operator!=(const LinePosition &other) const { return !(*this == other); }