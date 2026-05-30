#ifndef VERSANO_CORE_HINTASSUMPTION_H
#define VERSANO_CORE_HINTASSUMPTION_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Core/Position/HintPosition/HintPosition.h"
#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/Assumption/Assumption/IAssumption.h"

namespace VersaNo::Solver {

template <typename TOrientation> class HintAssumption : public IAssumption {
  private:
    Core::HintPosition<TOrientation> hintPosition;
    Core::HintNumber hintNumber;

  public:
    explicit HintAssumption(
      const Core::HintPosition<TOrientation> &hintPosition, const Core::HintNumber &hintNumber);
    virtual ~HintAssumption() = default;

    void applyTo(Core::NonogramBoard &board) const override;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_HINTASSUMPTION_H