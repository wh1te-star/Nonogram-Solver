#ifndef VERSANO_CORE_LINEASSUMPTION_H
#define VERSANO_CORE_LINEASSUMPTION_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"

namespace VersaNo::Core {
class NonogramBoard;
}

namespace VersaNo::Solver {

template <typename TOrientation> class LineAssumption : public IAssumption {
  private:
    Core::LinePosition<TOrientation> linePosition;
    Core::Line<TOrientation> line;

  public:
    explicit LineAssumption(
      const Core::LinePosition<TOrientation> &linePosition, const Core::Line<TOrientation> &line);
    virtual ~LineAssumption() = default;

    void applyTo(Core::NonogramBoard &board) const override;
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_LINEASSUMPTION_H