#include "Rendering/Shared/StopSignal/StopSignal.h"

namespace VersaN::Rendering {

void StopSignal::requestStop() { stopFlag.store(true); }

bool StopSignal::shouldStop() const {
  return stopFlag.load(std::memory_order_relaxed);
}

} // namespace VersaN::Rendering