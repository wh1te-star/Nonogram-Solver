#ifndef VERSANO_CORE_LINEASSUMPTIONPOSITION_H
#define VERSANO_CORE_LINEASSUMPTIONPOSITION_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Position/LinePosition/LinePosition.h"
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

#endif // VERSANO_CORE_LINEASSUMPTIONPOSITION_H
