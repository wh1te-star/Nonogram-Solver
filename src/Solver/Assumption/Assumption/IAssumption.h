#ifndef VERSANO_CORE_IASSUMPTION_H
#define VERSANO_CORE_IASSUMPTION_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"

namespace VersaNo::Solver {

class IAssumption {
  public:
    virtual ~IAssumption() = default;
    virtual void applyTo(Core::NonogramBoard &board) const = 0;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_IASSUMPTION_H