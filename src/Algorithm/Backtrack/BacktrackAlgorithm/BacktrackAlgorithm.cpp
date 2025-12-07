#include "Algorithm/Backtrack/BacktrackAlgorithm/BacktrackAlgorithm.h"

#include "Algorithm/ExhaustivePlacementPatternFindAlgorithm/ExhaustivePlacementPatternFindAlgorithm.h"
#include "Algorithm/OverlapDeterminationAlgorithm/OverlapDeterminationAlgorithm.h"
#include "Algorithm/PlacementPatternCountAlgorithm/PlacementPatternCountAlgorithm.h"
#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Rendering/HighlightIndexes/HighlightIndexes.h"
#include "Shared/SharedBacktrackBoard/SharedBacktrackBoard.h"
#include <algorithm>
#include <chrono>

BacktrackAlgorithm::BacktrackAlgorithm(
    SharedBacktrackBoard &sharedBacktrackBoard,
    SharedBacktrackStack &sharedBacktrackStack,
    SharedHighlightIndexes &sharedHighlightIndexes)
    : sharedBacktrackBoard(sharedBacktrackBoard),
      sharedBacktrackStack(sharedBacktrackStack),
      sharedHighlightIndexes(sharedHighlightIndexes),
      // Initialize local instances from shared state
      localBacktrackBoard(sharedBacktrackBoard.getBacktrackBoard()),
      localBacktrackStack(sharedBacktrackStack.getBacktrackStack()),
      localHighlightIndexes(sharedHighlightIndexes.getHighlightIndexes()) {
  lastUpdateTime = std::chrono::steady_clock::now();
}

void BacktrackAlgorithm::run() {
  deterministicSolve(10);
  backtrackSolve();
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
    ColumnLength columnLength = localBacktrackBoard.getBoard().getColumnLength();

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
    // Note: Since highlights change very fast in loops, this will show a "snapshot" 
    // of the highlight at the moment of sync.
    sharedHighlightIndexes.setHighlightIndexes(localHighlightIndexes);

    lastUpdateTime = now;
  }
}

void BacktrackAlgorithm::backtrackSolve() {
  deterministicSolve(10);
  backtrackSolveRecursive(0);
}

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
  // If you were using the stack logic here, you would push to localBacktrackStack
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

bool BacktrackAlgorithm::deterministicSolve(int waitMillis) {
  RowLength rowLength = localBacktrackBoard.getRowLength();
  ColumnLength columnLength = localBacktrackBoard.getColumnLength();

  while (true) {
    bool proceed = false;
    for (RowIndex rowIndex : RowIndex::range(0, rowLength.getLength() - 1)) {
      // Update LOCAL highlight
      localHighlightIndexes.addRowIndex(rowIndex);

      Row rowLine = localBacktrackBoard.getRowLine(rowIndex);
      RowHintSetList rowHintSetList = localBacktrackBoard.getRowHintSetList();
      HintSet rowHintSet = rowHintSetList[rowIndex];

      Row newRowLine =
          OverlapDeterminationAlgorithm::run(rowLine, rowHintSet).toRow();

      if (newRowLine.size() == 0) {
        return false;
      }

      Row currentRowLine = localBacktrackBoard.getRowLine(rowIndex);
      localBacktrackBoard.applyRow(rowIndex, newRowLine, false);

      if (currentRowLine != localBacktrackBoard.getRowLine(rowIndex)) {
        proceed = true;
      }

      PlacementCount count =
          PlacementPatternCountAlgorithm::run(rowLine, rowHintSet);

      localBacktrackBoard.setRowPlacementCount(rowIndex, count);

      if (count == PlacementCount(0)) {
        return false;
      }
      if (count == PlacementCount(1)) {
        RowPlacement finalPlacement =
            ExhaustivePlacementPatternFindAlgorithm::run(rowLine, rowHintSet)[0]
                .toRowPlacement();
        localBacktrackBoard.applyRow(rowIndex, finalPlacement);
      }

      // Sync all locals to shared (throttled)
      syncToSharedIfNeeded();

      if (waitAndCheckTermination(waitMillis))
        return false;

      // Update LOCAL highlight
      localHighlightIndexes.deleteRowIndex(rowIndex);
    }

    for (ColumnIndex columnIndex :
         ColumnIndex::range(0, columnLength.getLength() - 1)) {
      // Update LOCAL highlight
      localHighlightIndexes.addColumnIndex(columnIndex);

      Column columnLine = localBacktrackBoard.getColumnLine(columnIndex);
      ColumnHintSetList columnHintSetList =
          localBacktrackBoard.getColumnHintSetList();
      HintSet columnHintSet = columnHintSetList[columnIndex];

      Column newColumnLine =
          OverlapDeterminationAlgorithm::run(columnLine, columnHintSet)
              .toColumn();

      if (newColumnLine.size() == 0) {
        return false;
      }

      Column currentColumnLine = localBacktrackBoard.getColumnLine(columnIndex);
      localBacktrackBoard.applyColumn(columnIndex, newColumnLine, false);

      if (currentColumnLine != localBacktrackBoard.getColumnLine(columnIndex)) {
        proceed = true;
      }

      PlacementCount count =
          PlacementPatternCountAlgorithm::run(columnLine, columnHintSet);

      localBacktrackBoard.setColumnPlacementCount(columnIndex, count);

      if (count == PlacementCount(0))
        return false;
      if (count == PlacementCount(1)) {
        ColumnPlacement finalPlacement =
            ExhaustivePlacementPatternFindAlgorithm::run(columnLine,
                                                         columnHintSet)[0]
                .toColumnPlacement();
        localBacktrackBoard.applyColumn(columnIndex, finalPlacement);
      }

      // Sync all locals to shared (throttled)
      syncToSharedIfNeeded();

      if (waitAndCheckTermination(waitMillis))
        return false;

      // Update LOCAL highlight
      localHighlightIndexes.deleteColumnIndex(columnIndex);
    }

    if (proceed == false) {
      syncToSharedIfNeeded(true);
      return true;
    }
    if (localBacktrackBoard.isSolved()) {
      syncToSharedIfNeeded(true);
      return false;
    }
  }
  return true;
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