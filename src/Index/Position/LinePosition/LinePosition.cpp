#include "Index/Position/LinePosition/LinePosition.h"

#include "Board/BoardLength/ColumnLength.h"
#include "Board/BoardLength/RowLength.h"
#include "Index/CellIndex/ColumnIndex.h"
#include "Index/CellIndex/RowIndex.h"

LinePosition::LinePosition(Orientation orientation, CellIndex index)
    : orientation(orientation), cellIndex(index) {}

const Orientation &LinePosition::getOrientation() const { return orientation; }

const CellIndex &LinePosition::getCellIndex() const { return cellIndex; }

bool LinePosition::operator==(const LinePosition &other) const {
    return orientation== other.orientation && cellIndex == other.cellIndex;
}

bool LinePosition::operator!=(const LinePosition &other) const { return !(*this == other); }