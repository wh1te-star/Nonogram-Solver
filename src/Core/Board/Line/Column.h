#ifndef VERSAN_CORE_COLUMN_H
#define VERSAN_CORE_COLUMN_H

#include "Core/Board/Line/Line.h"

namespace VersaN::Core {

class Column : public Line {
  public:
    explicit Column(std::vector<Cell> line);
};

} // namespace VersaN::Core

#endif // VERSAN_CORE_COLUMN_H
