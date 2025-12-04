#ifndef DETERMINISTICSOLVE_H
#define DETERMINISTICSOLVE_H


#include <atomic>
#include <thread>
#include "SharedBacktrackBoard.h"
#include "SharedBacktrackStack.h"
#include "SharedHighlightIndexes.h"
#include "Line.h"
#include "HintSet.h"

class BacktrackAlgorithm {
private:
	SharedBacktrackBoard& sharedBacktrackBoard;
	SharedBacktrackStack& sharedBacktrackStack;
	SharedHighlightIndexes& sharedHighlightIndexes;
    std::atomic<bool> terminate{ false };
	std::vector<Board> solutions;

public:
    explicit BacktrackAlgorithm(
		SharedBacktrackBoard& sharedBacktrackBoard,
		SharedBacktrackStack& sharedBacktrackStack,
		SharedHighlightIndexes& sharedHighlightIndexes
    );

	void run();

	void backtrackSolve();
	void backtrackSolveRecursive(int depth);

	bool deterministicSolve(int waitMillis);

    bool waitAndCheckTermination(const int waitMillis) const;
    void request_stop();
};


#endif
