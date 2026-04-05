#ifndef VERSAN_CORE_CELLLOCATION_H
#define VERSAN_CORE_CELLLOCATION_H

#include "Core/Cell/Cell/Cell.h"
#include "Core/Index/Position/CellPosition/CellPosition.h"

namespace VersaNo::Core {

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

} // namespace VersaNo::Core

#endif // VERSAN_CORE_CELLLOCATION_H
