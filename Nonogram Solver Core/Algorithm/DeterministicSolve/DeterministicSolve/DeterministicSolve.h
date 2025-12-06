#ifndef DETERMINISTICSOLVE_H
#define DETERMINISTICSOLVE_H


#include "IDeterministicSolve.h"

class DeterministicSolve : public IDeterministicSolve {
public:
	bool deterministicSolve(int waitMillis) override;
};


#endif
