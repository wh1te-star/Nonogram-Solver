#ifndef VERSAN_CORE_CELLASSUMPTION_H
#define VERSAN_CORE_CELLASSUMPTION_H

#include "Core/Board/NonogramBoard/NonogramBoard.h"
#include "Solver/Assumption/Assumption/IAssumption.h"

namespace VersaNo::Solver {

class CellAssumption : public IAssumption {
  private:
    Core::CellPosition cellPosition;
    Core::Cell cell;

  public:
    explicit CellAssumption(const Core::CellPosition &cellPosition, const Core::Cell &cell);
    virtual ~CellAssumption() = default;

    void applyTo(Core::NonogramBoard &board) const override;
};

} // namespace VersaNo::Solver

#endif // VERSAN_CORE_CELLASSUMPTION_H