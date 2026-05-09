#ifndef VERSANO_CORE_CELLASSUMPTIONPOSITION_H
#define VERSANO_CORE_CELLASSUMPTIONPOSITION_H

#include "Core/Position/CellPosition/CellPosition.h"
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

#endif // VERSANO_CORE_CELLASSUMPTIONPOSITION_H
