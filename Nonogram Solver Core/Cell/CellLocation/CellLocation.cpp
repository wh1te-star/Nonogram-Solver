#include "CellLocation.h"

#include <algorithm>
#include "Cell.h"
#include "Coordinate.h"

CellLocation::CellLocation(Coordinate coordinate, Cell cell) :
    coordinate(std::move(coordinate)),
    cell(std::move(cell)) {}

const Coordinate& CellLocation::getCoordinate() const {
    return coordinate;
}

const Cell& CellLocation::getCell() const {
    return cell;
}

bool CellLocation::operator==(const CellLocation& other) const {
	return coordinate == other.coordinate && cell == other.cell;
}

bool CellLocation::operator!=(const CellLocation& other) const {
    return !(*this == other);
}

