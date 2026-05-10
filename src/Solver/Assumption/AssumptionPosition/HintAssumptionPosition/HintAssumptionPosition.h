#ifndef VERSANO_CORE_HINTASSUMPTIONPOSITION_H
#define VERSANO_CORE_HINTASSUMPTIONPOSITION_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Position/HintPosition/HintPosition.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"

namespace VersaNo::Solver {

class HintAssumptionPosition : public IAssumptionPosition {
  private:
    Core::HintPosition hintPosition;

  public:
    HintAssumptionPosition(Core::HintPosition hintPosition);
    virtual ~HintAssumptionPosition() = default;

    Core::HintPosition getHintPosition() const;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_HINTASSUMPTIONPOSITION_H
