#ifndef ISOLVERCONTEXT_H
#define ISOLVERCONTEXT_H

class ISolverContext {
public:
    virtual ~ISolverContext() = default;
    virtual bool shouldStop() const = 0;
    virtual void notifyProgress() = 0;
};

#endif