#ifndef BACKTRACKALGORITHM_H
#define BACKTRACKALGORITHM_H

#include "Algorithm/Backtrack/BacktrackStack/BacktrackStack.h"
#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Rendering/HighlightIndexes/HighlightIndexes.h" // Need the concrete class definition
#include "Shared/SharedBacktrackBoard/SharedBacktrackBoard.h"
#include "Shared/SharedBacktrackStack/SharedBacktrackStack.h" // Ensure this is included
#include "Shared/SharedHighlightIndexes/SharedHighlightIndexes.h"
#include <atomic>
#include <thread>
#include <vector>

class BacktrackAlgorithm {
private:
  SharedBacktrackBoard &sharedBacktrackBoard;
  SharedBacktrackStack &sharedBacktrackStack;
  SharedHighlightIndexes &sharedHighlightIndexes;
  std::atomic<bool> terminate{false};

  // Local instances for calculation
  BacktrackBoard localBacktrackBoard;
  BacktrackStack localBacktrackStack;
  HighlightIndexes localHighlightIndexes;

  int throttleMillis = 30;
  std::chrono::steady_clock::time_point lastUpdateTime;

  std::vector<Board> solutions;

  // Helper to sync all local states to shared states
  void syncToSharedIfNeeded(bool force = false);

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