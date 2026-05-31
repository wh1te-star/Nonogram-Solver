#ifndef VERSANO_CORE_HINTASSUMPTIONPOSITION_H
#define VERSANO_CORE_HINTASSUMPTIONPOSITION_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Position/HintPosition/HintPosition.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"

namespace VersaNo::Solver {

template <typename TOrientation>
class HintAssumptionPosition : public IAssumptionPosition {
  private:
    Core::HintPosition<TOrientation> hintPosition;

  public:
    explicit HintAssumptionPosition(Core::HintPosition<TOrientation> hintPosition);
    virtual ~HintAssumptionPosition() = default;

    Core::HintPosition<TOrientation> getHintPosition() const;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_HINTASSUMPTIONPOSITION_H
