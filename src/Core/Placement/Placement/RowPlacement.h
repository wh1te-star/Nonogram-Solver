#ifndef VERSANO_CORE_ROWPLACEMENT_H
#define VERSANO_CORE_ROWPLACEMENT_H

#include "Core/Placement/Placement/Placement.h"

namespace VersaNo::Core {

class RowPlacement : public Placement {
  public:
    explicit RowPlacement(std::vector<Cell> placement);
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_ROWPLACEMENT_H
