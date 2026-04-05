#ifndef VERSANO_CORE_COLUMN_H
#define VERSANO_CORE_COLUMN_H

#include "Core/Board/Line/Line.h"

namespace VersaNo::Core {

class Column : public Line {
  public:
    explicit Column(std::vector<Cell> line);
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_COLUMN_H
