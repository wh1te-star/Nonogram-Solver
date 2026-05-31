#ifndef VERSANO_CORE_LINEASSUMPTIONPOSITION_H
#define VERSANO_CORE_LINEASSUMPTIONPOSITION_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Position/LinePosition/LinePosition.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"

namespace VersaNo::Solver {

template <typename TOrientation>
class LineAssumptionPosition : public IAssumptionPosition {
  private:
    Core::LinePosition<TOrientation> linePosition;

  public:
    explicit LineAssumptionPosition(Core::LinePosition<TOrientation> linePosition);
    virtual ~LineAssumptionPosition() = default;

    Core::LinePosition<TOrientation> getLinePosition() const;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_LINEASSUMPTIONPOSITION_H
