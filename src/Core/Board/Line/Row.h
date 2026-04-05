#ifndef VERSAN_CORE_ROW_H
#define VERSAN_CORE_ROW_H

#include "Core/Board/Line/Line.h"

namespace VersaNo::Core {

class Row : public Line {
  public:
    explicit Row(std::vector<Cell> line);
};

} // namespace VersaNo::Core

#endif // VERSAN_CORE_ROW_H
