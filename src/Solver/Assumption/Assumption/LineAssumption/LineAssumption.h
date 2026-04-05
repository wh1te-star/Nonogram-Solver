#ifndef VERSAN_CORE_LINEASSUMPTION_H
#define VERSAN_CORE_LINEASSUMPTION_H

#include "Core/Board/Orientation.h"
#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"

namespace VersaNo::Core {
class NonogramBoard;
}

namespace VersaNo::Solver {

class LineAssumption : public IAssumption {
  private:
    Core::LinePosition linePosition;
    Core::Line line;

  public:
    explicit LineAssumption(const Core::LinePosition &linePosition, const Core::Line &line);
    virtual ~LineAssumption() = default;

    void applyTo(Core::NonogramBoard &board) const override;
};

} // namespace VersaNo::Solver

#endif // VERSAN_CORE_LINEASSUMPTION_H