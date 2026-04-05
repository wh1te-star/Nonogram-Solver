#ifndef VERSAN_CORE_COLUMN_H
#define VERSAN_CORE_COLUMN_H

#include "Core/Board/Line/Line.h"

namespace VersaNo::Core {

class Column : public Line {
  public:
    explicit Column(std::vector<Cell> line);
};

} // namespace VersaNo::Core

#endif // VERSAN_CORE_COLUMN_H
