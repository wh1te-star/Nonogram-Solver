#ifndef IASSUMPTIONENUMERATOR_H
#define IASSUMPTIONENUMERATOR_H

#include "Board/Board/Board.h"
#include "Solver/Assumption/Assumption/IAssumption.h"
#include "Solver/Assumption/AssumptionPosition/CellAssumptionPosition/CellAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/HintAssumptionPosition/HintAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/IAssumptionPosition.h"
#include "Solver/Assumption/AssumptionPosition/LineAssumptionPosition/LineAssumptionPosition.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include <vector>

class AssumptionEnumerator {
  private:
    IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder;

  public:
    AssumptionEnumerator(IExhaustivePlacementPatternFinder &exhaustivePlacementPatternFinder );
    virtual ~AssumptionEnumerator() = default;

    virtual std::vector<std::unique_ptr<IAssumption>>
    enumerate(const NonogramBoard &nonogramBoard, IAssumptionPosition assumptionPosition);

  private:
    std::vector<std::unique_ptr<IAssumption>> enumerateCellAssumption(
      const NonogramBoard &nonogramBoard, const CellAssumptionPosition &cellAssumptionPosition);

    std::vector<std::unique_ptr<IAssumption>> enumerateLineAssumption(
      const NonogramBoard &nonogramBoard, const LineAssumptionPosition &LineAssumptionPosition);

    std::vector<std::unique_ptr<IAssumption>> enumerateHintAssumption(
      const NonogramBoard &nonogramBoard, const HintAssumptionPosition &hintAssumptionPosition);
};

#endif