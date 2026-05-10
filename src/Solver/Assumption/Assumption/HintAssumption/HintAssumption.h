#ifndef VERSANO_CORE_HINTASSUMPTION_H
#define VERSANO_CORE_HINTASSUMPTION_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Position/HintPosition/HintPosition.h"
#include "Solver/Assumption/Assumption/IAssumption.h"

namespace VersaNo::Solver {

class HintAssumption : public IAssumption {
  private:
    Core::HintPosition hintPosition;
    Core::HintNumber hintNumber;

  public:
    explicit HintAssumption(
      const Core::HintPosition &hintPosition, const Core::HintNumber &hintNumber);
    virtual ~HintAssumption() = default;

    void applyTo(Core::NonogramBoard &board) const override;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_HINTASSUMPTION_H