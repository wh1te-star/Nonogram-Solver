#include "Solver/Assumption/BacktrackStack/BacktrackStack.h"

BacktrackStack::BacktrackStack(const IAssumptionSelector &assumptionSelector)
    : assumptionSelector(assumptionSelector) {}

void BacktrackStack::push(std::unique_ptr<ISnapshot> snapshot) { history.push_back(snapshot); }

void BacktrackStack::pop(Board &board) {
    if (history.empty())
        return;

    history.back()->restore(board);
    history.pop_back();
}