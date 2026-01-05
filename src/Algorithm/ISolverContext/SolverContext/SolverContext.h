#ifndef SOLVERCONTEXT_H
#define SOLVERCONTEXT_H

#include "Algorithm/ISolverContext/ISolverContext.h"

class SolverContext : public ISolverContext {
private:
    bool stopRequested;

public:
    SolverContext();
    bool shouldStop() const override;
    void notifyProgress() override;
    void requestStop();
};

#endif

