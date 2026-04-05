#ifndef VERSAN_CORE_COLUMNPLACEMENT_H
#define VERSAN_CORE_COLUMNPLACEMENT_H

#include "Core/Placement/Placement/Placement.h"

namespace VersaNo::Core {

class ColumnPlacement : public Placement {
  public:
    explicit ColumnPlacement(std::vector<Cell> placement);
};

} // namespace VersaNo::Core

#endif // VERSAN_CORE_COLUMNPLACEMENT_H
