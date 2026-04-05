#ifndef VERSAN_CORE_CELLCHANGE_H
#define VERSAN_CORE_CELLCHANGE_H

#include "Core/Cell/Cell/Cell.h"
#include "Core/Cell/CellLocation/CellLocation.h"

#include <vector>

namespace VersaN::Core {

class CellChange {
  private:
    std::vector<CellLocation> changeLocations;

  public:
    explicit CellChange();

  public:
    const std::vector<CellLocation> &getChangeLocations() const;
};

} // namespace VersaN::Core

#endif // VERSAN_CORE_CELLCHANGE_H
