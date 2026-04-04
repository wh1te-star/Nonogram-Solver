#ifndef BACKTRACKSTACK_H
#define BACKTRACKSTACK_H

#include <vector>
#include <memory>
#include "Solver/Assumption/Snapshot/ISnapshot.h"
class NonogramBoard;

class IAssumptionSelector;

class BacktrackStack {
    std::vector<std::unique_ptr<ISnapshot>> history;
    const IAssumptionSelector &assumptionSelector;

public:
    explicit BacktrackStack(const IAssumptionSelector &assumptionSelector);

    BacktrackStack(BacktrackStack&&) noexcept = default;
    BacktrackStack& operator=(BacktrackStack&&) noexcept = default;
    
    BacktrackStack(const BacktrackStack&) = delete;
    BacktrackStack& operator=(const BacktrackStack&) = delete;

    void push(std::unique_ptr<ISnapshot> snapshot);
    void pop(NonogramBoard &nonogramBoard);
};

#endif