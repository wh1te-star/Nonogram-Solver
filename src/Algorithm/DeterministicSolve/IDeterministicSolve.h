#ifndef IDETERMINISTICSOLVE_H
#define IDETERMINISTICSOLVE_H


class IDeterministicSolve {
public:
    virtual bool deterministicSolve(int waitMillis) = 0;
    virtual ~IDeterministicSolve() = default;
};


#endif