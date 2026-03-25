#ifndef PLACEMENTCOUNTASSUMPTIONSELECTOR_H
#define PLACEMENTCOUNTASSUMPTIONSELECTOR_H

#include "Board/Orientation.h"
#include "Placement/PlacementCountList/ColumnPlacementCountList.h"
#include "Placement/PlacementCountList/RowPlacementCountList.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionSelector/IAssumptionSelector.h"
#include "Solver/PlacementPatternCounter/IPlacementPatternCounter.h"
#include <vector>

class PlacementCountAssumptionSelector : public IAssumptionSelector {
  private:
    IPlacementPatternCounter &placementPatternCounter;
    RowPlacementCountList rowPlacementCounts;
    ColumnPlacementCountList columnPlacementCounts;

  public:
    PlacementCountAssumptionSelector(
      IPlacementPatternCounter &placementPatternCounter, const Board &board);

    IAssumptionPosition
    select(const NonogramBoard &board, const AssumptionSelectionContext &context) override;
};

#endif