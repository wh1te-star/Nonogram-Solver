#ifndef BACKTRACKSTACK_H
#define BACKTRACKSTACK_H

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Solver/Assumption/AssumptionSelector/IAssumptionSelector.h"
#include "Solver/Assumption/Snapshot/ISnapshot.h"

class BacktrackStack {
    std::vector<std::unique_ptr<ISnapshot>> history;
    const IAssumptionSelector &assumptionSelector;

  public:
    BacktrackStack(const IAssumptionSelector &assumptionSelector);

    void push(std::unique_ptr<ISnapshot> snapshot);
    void pop(Board &board);
};

#endif