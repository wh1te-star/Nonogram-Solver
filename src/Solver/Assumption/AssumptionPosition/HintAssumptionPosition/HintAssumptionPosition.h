#ifndef VERSAN_CORE_HINTASSUMPTIONPOSITION_H
#define VERSAN_CORE_HINTASSUMPTIONPOSITION_H

#include "Core/Index/Position/HintPosition/HintPosition.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"

namespace VersaN::Solver {

class HintAssumptionPosition : public IAssumptionPosition {
  private:
    Core::HintPosition hintPosition;

  public:
    HintAssumptionPosition(Core::HintPosition hintPosition);
    virtual ~HintAssumptionPosition() = default;

    Core::HintPosition getHintPosition() const;
};

} // namespace VersaN::Solver

#endif // VERSAN_CORE_HINTASSUMPTIONPOSITION_H
