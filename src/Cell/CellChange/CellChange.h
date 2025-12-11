#ifndef CELLCHANGE_H
#define CELLCHANGE_H

#include "Cell/Cell/Cell.h"
#include "Cell/CellLocation/CellLocation.h"
#include "Index/Coordinate/Coordinate.h"
#include <vector>

class CellChange {
private:
std::vector<CellLocation> changeLocations;

public:
  explicit CellChange();

public:
  const std::vector<CellLocation> &getChangeLocations() const;
};

#endif
