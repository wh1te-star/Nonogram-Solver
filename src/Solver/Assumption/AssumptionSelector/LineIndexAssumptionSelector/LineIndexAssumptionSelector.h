#ifndef LINEINDEXASSUMPTIONSELECTOR_H
#define LINEINDEXASSUMPTIONSELECTOR_H

#include "Solver/Assumption/AssumptionSelector/IAssumptionSelector.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include "Board/Orientation.h"

class LineIndexAssumptionSelector : public IAssumptionSelector {
private:
    IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder;
  Orientation orientation;
  int currentIndex = 0;

public:
  LineIndexAssumptionSelector(IExhaustivePlacementPatternFinder
                                  &exhaustivePlacementPatternFinder,
                              Orientation orientation, int currentIndex);
  std::vector<std::unique_ptr<IAssumption>>
  select(const BacktrackBoard &board) override;
};

#endif