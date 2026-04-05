#ifndef VERSAN_CORE_CELLASSUMPTIONPOSITION_H
#define VERSAN_CORE_CELLASSUMPTIONPOSITION_H

#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Core/Index/Position/CellPosition/CellPosition.h"

namespace VersaN::Solver {

class CellAssumptionPosition : public IAssumptionPosition {
  private:
    Core::CellPosition cellPosition;

  public:
    CellAssumptionPosition(Core::CellPosition cellPosition);
    virtual ~CellAssumptionPosition() = default;

    Core::CellPosition getCellPosition() const;
};

} // namespace VersaN::Solver

#endif // VERSAN_CORE_CELLASSUMPTIONPOSITION_H
