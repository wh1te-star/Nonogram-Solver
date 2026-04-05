#ifndef VERSAN_CORE_LINEASSUMPTIONPOSITION_H
#define VERSAN_CORE_LINEASSUMPTIONPOSITION_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Board/Orientation.h"
#include "Core/Index/Position/LinePosition/LinePosition.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"

namespace VersaNo::Solver {

class LineAssumptionPosition : public IAssumptionPosition {
  private:
    Core::LinePosition linePosition;

  public:
    LineAssumptionPosition(Core::LinePosition linePosition);
    virtual ~LineAssumptionPosition() = default;

    Core::LinePosition getLinePosition() const;
};

} // namespace VersaNo::Solver

#endif // VERSAN_CORE_LINEASSUMPTIONPOSITION_H
