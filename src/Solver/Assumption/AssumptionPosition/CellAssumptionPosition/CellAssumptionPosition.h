#ifndef VERSAN_CORE_CELLASSUMPTIONPOSITION_H
#define VERSAN_CORE_CELLASSUMPTIONPOSITION_H

#include "Core/Index/Position/CellPosition/CellPosition.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"

namespace VersaNo::Solver {

class CellAssumptionPosition : public IAssumptionPosition {
  private:
    Core::CellPosition cellPosition;

  public:
    CellAssumptionPosition(Core::CellPosition cellPosition);
    virtual ~CellAssumptionPosition() = default;

    Core::CellPosition getCellPosition() const;
};

} // namespace VersaNo::Solver

#endif // VERSAN_CORE_CELLASSUMPTIONPOSITION_H
