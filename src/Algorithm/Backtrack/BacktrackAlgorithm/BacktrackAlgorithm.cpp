#include "Algorithm/Backtrack/BacktrackAlgorithm/BacktrackAlgorithm.h"

#include "Board/Line/Line.h"
#include "Cell/CellChange/CellChange.h"
#include "Hint/HintSet/HintSet.h"
#include "Rendering/HighlightIndexes/HighlightIndexes.h"
#include "Shared/SharedBacktrackBoard/SharedBacktrackBoard.h"
#include <algorithm>
#include <chrono>

BacktrackAlgorithm::BacktrackAlgorithm(
    ISolver &solver)
    : solver(solver)
    {
  lastUpdateTime = std::chrono::steady_clock::now();
}

void BacktrackAlgorithm::run() {
  
}

void BacktrackAlgorithm::syncToSharedIfNeeded(bool force) {
  auto now = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
                     now - lastUpdateTime)
                     .count();

  if (force || elapsed >= throttleMillis) {
    // 1. Sync Board
    sharedBacktrackBoard.applyBoard(localBacktrackBoard.getBoard(), true);

    RowLength rowLength = localBacktrackBoard.getBoard().getRowLength();
    ColumnLength columnLength =
        localBacktrackBoard.getBoard().getColumnLength();

    for (RowIndex rowIndex : RowIndex::range(0, rowLength.getLength() - 1)) {
      sharedBacktrackBoard.setRowPlacementCount(
          rowIndex, localBacktrackBoard.getRowPlacementCountList()[rowIndex]);
    }
    for (ColumnIndex columnIndex :
         ColumnIndex::range(0, columnLength.getLength() - 1)) {
      sharedBacktrackBoard.setColumnPlacementCount(
          columnIndex,
          localBacktrackBoard.getColumnPlacementCountList()[columnIndex]);
    }

    // 2. Sync Stack (Assuming applyBacktrackStack exists or similar setter)
    sharedBacktrackStack.setBacktrackStack(localBacktrackStack);

    // 3. Sync HighlightIndexes (Assuming setHighlightIndexes exists)
    // Note: Since highlights change very fast in loops, this will show a
    // "snapshot" of the highlight at the moment of sync.
    sharedHighlightIndexes.setHighlightIndexes(localHighlightIndexes);

    lastUpdateTime = now;
  }
}

/*
void BacktrackAlgorithm::backtrackSolveRecursive(int depth) {
  if (terminate.load())
    return;

  CellIndex targetIndex = CellIndex(0);
  if (depth == 0) {
    targetIndex = CellIndex(34, CellIndexType::Row);
  } else if (depth == 1) {
    targetIndex = CellIndex(49, CellIndexType::Row);
  } else if (depth == 2) {
    return;
  } else {
    return;
  }

  Line row = localBacktrackBoard.getRowLine(targetIndex.toRowIndex());
  HintSet rowHintSet =
      localBacktrackBoard.getRowHintSetList()[targetIndex.toRowIndex()];

  std::vector<Placement> exhaustivePlacements =
      ExhaustivePlacementPatternFindAlgorithm::run(row, rowHintSet);

  BacktrackBoard previousBacktrackBoard = localBacktrackBoard;
  // If you were using the stack logic here, you would push to
localBacktrackStack
  // e.g., localBacktrackStack.push(previousBacktrackBoard);

  for (Placement placement : exhaustivePlacements) {
    localBacktrackBoard.applyRow(targetIndex.toRowIndex(),
                                 placement.toRowPlacement());

    // Sync all changes (Board, Stack, Highlights) throttled
    syncToSharedIfNeeded();

    if (waitAndCheckTermination(1))
      return;

    bool more = deterministicSolve(1);

    if (localBacktrackBoard.isSolved()) {
      solutions.push_back(localBacktrackBoard.getBoard());
      syncToSharedIfNeeded(true);
    }

    if (more) {
      backtrackSolveRecursive(depth + 1);
    }

    localBacktrackBoard.applyBoard(previousBacktrackBoard.getBoard(), true);

    for (RowIndex rowIndex : RowIndex::range(
             0, previousBacktrackBoard.getBoard().getRowLength().getLength() -
                    1)) {
      PlacementCount placementCount =
          previousBacktrackBoard.getRowPlacementCountList()[rowIndex];
      localBacktrackBoard.setRowPlacementCount(rowIndex, placementCount);
    }
    for (ColumnIndex columnIndex : ColumnIndex::range(
             0,
             previousBacktrackBoard.getBoard().getColumnLength().getLength() -
                 1)) {
      PlacementCount placementCount =
          previousBacktrackBoard.getColumnPlacementCountList()[columnIndex];
      localBacktrackBoard.setColumnPlacementCount(columnIndex, placementCount);
    }

    // Sync reverted state
    syncToSharedIfNeeded();

    if (waitAndCheckTermination(1))
      return;
  }

  if (solutions.size() > 0) {
    sharedBacktrackBoard.applyBoard(solutions[0], true);
  }
}
  */

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