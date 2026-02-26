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
    explicit BacktrackStack(const TAssumptionSelector &assumptionSelector) : assumptionSelector(assumptionSelector) {}

    void push(const TSnapshot &snapshot) {
        history.push_back(snapshot);
    }

    void pop(Board &board) {
        if (history.empty()) return;
        
        history.back().restore(board);
        history.pop_back();
    }
};

#endif