#ifndef BACKTRACKALGORITHM_H
#define BACKTRACKALGORITHM_H

#include "Algorithm/Backtrack/BacktrackStack/BacktrackStack.h"
#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Rendering/HighlightIndexes/HighlightIndexes.h"
#include "Shared/SharedBacktrackBoard/SharedBacktrackBoard.h"
#include "Shared/SharedBacktrackStack/SharedBacktrackStack.h"
#include "Shared/SharedHighlightIndexes/SharedHighlightIndexes.h"
#include "Solver/Solver/ISolver.h"
#include <atomic>
#include <thread>
#include <vector>

class BacktrackAlgorithm {
private:
  ISolver &solver;
  std::atomic<bool> terminate{false};

  int throttleMillis = 30;
  std::chrono::steady_clock::time_point lastUpdateTime;

  std::vector<Board> solutions;

  void syncToSharedIfNeeded(bool force = false);

public:
  explicit BacktrackAlgorithm(ISolver &solver);

  void run();

  bool waitAndCheckTermination(const int waitMillis) const;
  void request_stop();
};

#endif