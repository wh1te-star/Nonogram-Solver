#include "Core/Cell/CellLocation/CellLocation.h"

#include <algorithm>
#include "Core/Cell/Cell/Cell.h"
#include "Core/Index/Position/CellPosition/CellPosition.h"

CellLocation::CellLocation(CellPosition position, Cell cell) :
    position(std::move(position)),
    cell(std::move(cell)) {}

const CellPosition& CellLocation::getPosition() const {
    return position;
}

const Cell& CellLocation::getCell() const {
    return cell;
}

bool CellLocation::operator==(const CellLocation& other) const {
	return position == other.position && cell == other.cell;
}

bool CellLocation::operator!=(const CellLocation& other) const {
    return !(*this == other);
}

