#ifndef DETERMINISTICSOLVE_H
#define DETERMINISTICSOLVE_H


#include "SharedBacktrackBoard.h"
#include "SharedBacktrackStack.h"
#include "SharedHighlightIndexes.h"
#include "IDeterministicSolve.h"
#include "Line.h"
#include "HintSet.h"

class BacktrackAlgorithm : public IDeterministicSolve {
private:
	SharedBacktrackBoard& sharedBacktrackBoard;
	SharedBacktrackStack& sharedBacktrackStack;
	SharedHighlightIndexes& sharedHighlightIndexes;

public:
    explicit BacktrackAlgorithm(
		SharedBacktrackBoard& sharedBacktrackBoard,
		SharedBacktrackStack& sharedBacktrackStack,
		SharedHighlightIndexes& sharedHighlightIndexes
    );

	bool deterministicSolve(int waitMillis) override
};


#endif
