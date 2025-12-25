#include "Algorithm/Backtrack/BacktrackAlgorithm/BacktrackAlgorithm.h"

#include "Board/Line/Line.h"
#include "Cell/CellChange/CellChange.h"
#include "Hint/HintSet/HintSet.h"
#include "Rendering/HighlightIndexes/HighlightIndexes.h"
#include "Shared/SharedBacktrackBoard/SharedBacktrackBoard.h"
#include <algorithm>
#include <chrono>

BacktrackAlgorithm::BacktrackAlgorithm(
    SharedBacktrackBoard &sharedBacktrackBoard,
    SharedBacktrackStack &sharedBacktrackStack,
    SharedHighlightIndexes &sharedHighlightIndexes, ISolver &solver)
    : sharedBacktrackBoard(sharedBacktrackBoard),
      sharedBacktrackStack(sharedBacktrackStack),
      sharedHighlightIndexes(sharedHighlightIndexes), solver(solver),
      localBacktrackBoard(sharedBacktrackBoard.getBacktrackBoard()),
      localBacktrackStack(sharedBacktrackStack.getBacktrackStack()),
      localHighlightIndexes(sharedHighlightIndexes.getHighlightIndexes()),
      lastUpdateTime(std::chrono::steady_clock::now()) {}

void BacktrackAlgorithm::run() {
  solver.solve(localBacktrackBoard.getNonogramBoard());
}

void BacktrackAlgorithm::syncToSharedIfNeeded(bool force) {
  auto now = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
                     now - lastUpdateTime)
                     .count();

  if (force || elapsed >= throttleMillis) {
    sharedBacktrackBoard.applyBoard(localBacktrackBoard.getBoard(), true);
    sharedBacktrackStack.setBacktrackStack(localBacktrackStack);
    sharedHighlightIndexes.setHighlightIndexes(localHighlightIndexes);

    lastUpdateTime = now;
  }
}

bool BacktrackAlgorithm::waitAndCheckTermination(const int waitMillis) const {
  if (waitMillis <= 0) {
    return terminate.load();
  }

  const int checkIntervalMillis = 100;
  int checks = waitMillis / checkIntervalMillis;
  int remainingMillis = waitMillis % checkIntervalMillis;
  for (int i = 0; i < checks; ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(checkIntervalMillis));
    if (terminate.load()) {
      return true;
    }
  }
  if (remainingMillis > 0) {
    std::this_thread::sleep_for(std::chrono::milliseconds(remainingMillis));
  }
  return terminate.load();
}

void BacktrackAlgorithm::request_stop() { terminate = true; }