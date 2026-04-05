#ifndef VERSAN_CORE_ISNAPSHOT_H
#define VERSAN_CORE_ISNAPSHOT_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"

namespace VersaNo::Solver {

class ISnapshot {
  public:
    virtual ~ISnapshot() = default;

    virtual void restore(Core::NonogramBoard &nonogramBoard) const = 0;
};

} // namespace VersaNo::Solver

#endif // VERSAN_CORE_ISNAPSHOT_H