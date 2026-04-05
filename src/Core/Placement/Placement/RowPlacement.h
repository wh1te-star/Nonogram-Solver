#ifndef VERSAN_CORE_ROWPLACEMENT_H
#define VERSAN_CORE_ROWPLACEMENT_H

#include "Core/Placement/Placement/Placement.h"

namespace VersaN::Core {

class RowPlacement : public Placement {
  public:
    explicit RowPlacement(std::vector<Cell> placement);
};

} // namespace VersaN::Core

#endif // VERSAN_CORE_ROWPLACEMENT_H
