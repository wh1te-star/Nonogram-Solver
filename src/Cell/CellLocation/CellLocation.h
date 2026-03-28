#ifndef CELLLOCATION_H
#define CELLLOCATION_H

#include "Cell/Cell/Cell.h"
#include "Index/Position/CellPosition/CellPosition.h"

class CellLocation {
private:
  CellPosition position;
  Cell cell;

public:
  explicit CellLocation(CellPosition position, Cell cell);

public:
  const CellPosition &getPosition() const;
  const Cell &getCell() const;

public:
  bool operator==(const CellLocation &other) const;
  bool operator!=(const CellLocation &other) const;
};

#endif
