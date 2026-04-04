#ifndef CELLASSUMPTIONPOSITION_H
#define CELLASSUMPTIONPOSITION_H

#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"

#include "Core/Index/Position/CellPosition/CellPosition.h"

class CellAssumptionPosition : public IAssumptionPosition {
  private:
    CellPosition cellPosition;

  public:
    CellAssumptionPosition(CellPosition cellPosition);
    virtual ~CellAssumptionPosition() = default;

    CellPosition getCellPosition() const;
};

#endif