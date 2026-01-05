#include "Algorithm/ISolverContext/SolverContext/SolverContext.h"

SolverContext::SolverContext() : stopRequested(false) {}

bool SolverContext::shouldStop() const { return stopRequested; }

void SolverContext::notifyProgress() {}

void SolverContext::requestStop() { stopRequested = true; }
