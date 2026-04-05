#ifndef VERSAN_CORE_BACKTRACKSTACK_H
#define VERSAN_CORE_BACKTRACKSTACK_H

#include "Solver/Assumption/Snapshot/ISnapshot.h"

#include <memory>
#include <vector>

namespace VersaNo::Core {
class NonogramBoard;
}
namespace VersaNo::Solver {
class IAssumptionSelector;
}

namespace VersaNo::Solver {

class BacktrackStack {
    std::vector<std::unique_ptr<ISnapshot>> history;
    const IAssumptionSelector &assumptionSelector;

  public:
    explicit BacktrackStack(const IAssumptionSelector &assumptionSelector);

    BacktrackStack(BacktrackStack &&) noexcept = default;
    BacktrackStack &operator=(BacktrackStack &&) noexcept = default;

    BacktrackStack(const BacktrackStack &) = delete;
    BacktrackStack &operator=(const BacktrackStack &) = delete;

    void push(std::unique_ptr<ISnapshot> snapshot);
    void pop(Core::NonogramBoard &nonogramBoard);
};

} // namespace VersaNo::Solver

#endif // VERSAN_CORE_BACKTRACKSTACK_H