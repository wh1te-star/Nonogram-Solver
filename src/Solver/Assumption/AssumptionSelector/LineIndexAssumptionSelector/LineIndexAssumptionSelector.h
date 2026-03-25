#ifndef LINEINDEXASSUMPTIONSELECTOR_H
#define LINEINDEXASSUMPTIONSELECTOR_H

#include "Board/Orientation.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionSelector/IAssumptionSelector.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"

class LineIndexAssumptionSelector : public IAssumptionSelector {
  private:
    Orientation orientation;

  public:
    LineIndexAssumptionSelector(Orientation orientation);
    IAssumptionPosition
    select(const NonogramBoard &board, const AssumptionSelectionContext &context) override;
};

#endif