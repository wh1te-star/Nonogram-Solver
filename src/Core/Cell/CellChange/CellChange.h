#ifndef CELLCHANGE_H
#define CELLCHANGE_H

#include "Core/Cell/Cell/Cell.h"
#include "Core/Cell/CellLocation/CellLocation.h"
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
