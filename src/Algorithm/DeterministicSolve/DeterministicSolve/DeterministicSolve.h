#ifndef DETERMINISTICSOLVE_H
#define DETERMINISTICSOLVE_H


#include "Algorithm/DeterministicSolve/IDeterministicSolve.h"

class DeterministicSolve : public IDeterministicSolve {
public:
	bool deterministicSolve(int waitMillis) override;
};


#endif
