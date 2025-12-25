#ifndef SOLVERCONTEXT_H
#define SOLVERCONTEXT_H

#include "Algorithm/ISolverContext/ISolverContext.h"

class SolverContext : public ISolverContext {
private:
    bool stopRequested;

public:
    SolverContext() : stopRequested(false) {}

    bool shouldStop() const override { return stopRequested; }

    void notifyProgress() override {}

    void requestStop() { stopRequested = true; }
};

#endif

