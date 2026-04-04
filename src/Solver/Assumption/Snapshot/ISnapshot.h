#ifndef ISNAPSHOT_H
#define ISNAPSHOT_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"

class ISnapshot {
  public:
    virtual ~ISnapshot() = default;

    virtual void restore(NonogramBoard& nonogramBoard) const = 0;
};

#endif