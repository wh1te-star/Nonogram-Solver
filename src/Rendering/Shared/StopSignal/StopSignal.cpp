#include "Rendering/Shared/StopSignal/StopSignal.h"

namespace VersaNo::Rendering {

void StopSignal::requestStop() { stopFlag.store(true); }

bool StopSignal::shouldStop() const { return stopFlag.load(std::memory_order_relaxed); }

} // namespace VersaNo::Rendering