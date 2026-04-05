#ifndef VERSANO_CORE_COLUMNPLACEMENT_H
#define VERSANO_CORE_COLUMNPLACEMENT_H

#include "Core/Placement/Placement/Placement.h"

namespace VersaNo::Core {

class ColumnPlacement : public Placement {
  public:
    explicit ColumnPlacement(std::vector<Cell> placement);
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_COLUMNPLACEMENT_H
