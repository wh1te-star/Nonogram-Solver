#ifndef VERSAN_CORE_HINTASSUMPTION_H
#define VERSAN_CORE_HINTASSUMPTION_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Board/Orientation.h"
#include "Core/Hint/HintNumber/HintNumber.h"
#include "Core/Index/Position/HintPosition/HintPosition.h"
#include "Solver/Assumption/Assumption/IAssumption.h"

namespace VersaN::Solver {

class HintAssumption : public IAssumption {
  private:
    Core::HintPosition hintPosition;
    Core::HintNumber hintNumber;

  public:
    explicit HintAssumption(const Core::HintPosition &hintPosition, const Core::HintNumber &hintNumber);
    virtual ~HintAssumption() = default;

    void applyTo(Core::NonogramBoard &board) const override;
};

} // namespace VersaN::Solver

#endif // VERSAN_CORE_HINTASSUMPTION_H

