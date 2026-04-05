#ifndef VERSANO_CORE_ISNAPSHOT_H
#define VERSANO_CORE_ISNAPSHOT_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"

namespace VersaNo::Solver {

class ISnapshot {
  public:
    virtual ~ISnapshot() = default;

    virtual void restore(Core::NonogramBoard &nonogramBoard) const = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_ISNAPSHOT_H