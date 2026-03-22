#ifndef IASSUMPTIONENUMERATOR_H
#define IASSUMPTIONENUMERATOR_H

#include "Board/Board/Board.h"
#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include <vector>

class AssumptionEnumerator {
  private:
    IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder;

  public:
    AssumptionEnumerator(IExhaustivePlacementPatternFinder &finder);
    virtual ~AssumptionEnumerator() = default;

    virtual std::vector<std::unique_ptr<IAssumption>>
    enumerate(const Board &board, IAssumption assumption);
};

#endif