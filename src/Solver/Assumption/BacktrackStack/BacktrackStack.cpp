#include "Solver/Assumption/BacktrackStack/BacktrackStack.h"

BacktrackStack::BacktrackStack(const IAssumptionSelector &assumptionSelector)
    : assumptionSelector(assumptionSelector) {}

void BacktrackStack::push(std::unique_ptr<ISnapshot> snapshot) {
    if (snapshot)
        history.push_back(std::move(snapshot));
}

void BacktrackStack::pop(NonogramBoard &nonogramBoard) {
    if (history.empty())
        return;

    history.back()->restore(nonogramBoard);
    history.pop_back();
}