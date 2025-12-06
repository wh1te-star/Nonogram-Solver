#ifndef BACKTRACKALGORITHM_H
#define BACKTRACKALGORITHM_H

#include "Algorithm/Backtrack/BacktrackStack/BacktrackStack.h"
#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Shared/SharedBacktrackBoard/SharedBacktrackBoard.h"
#include "Shared/SharedHighlightIndexes/SharedHighlightIndexes.h"
#include <atomic>
#include <thread>

class BacktrackAlgorithm {
private:
  SharedBacktrackBoard &sharedBacktrackBoard;
  SharedBacktrackStack &sharedBacktrackStack;
  SharedHighlightIndexes &sharedHighlightIndexes;
  std::atomic<bool> terminate{false};
  std::vector<Board> solutions;

public:
  explicit BacktrackAlgorithm(SharedBacktrackBoard &sharedBacktrackBoard,
                              SharedBacktrackStack &sharedBacktrackStack,
                              SharedHighlightIndexes &sharedHighlightIndexes);

  void run();

  void backtrackSolve();
  void backtrackSolveRecursive(int depth);

  bool deterministicSolve(int waitMillis);

  bool waitAndCheckTermination(const int waitMillis) const;
  void request_stop();
};

#endif
