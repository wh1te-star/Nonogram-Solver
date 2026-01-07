#include "Shared/StopSignal/StopSignal/StopSignal.h"

void StopSignal::requestStop() { stopFlag.store(true); }

bool StopSignal::shouldStop() const {
  return stopFlag.load(std::memory_order_relaxed);
}