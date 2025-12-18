#include "Solver/DeterministicSolver/LineRepeatDeterministicSolver/LineRepeatDeterministicSolver.h"

LineRepeatDeterministicSolver::LineRepeatDeterministicSolver() {}

bool LineRepeatDeterministicSolver::solve(NonogramBoard &nonogramBoard) {
  return lineRepeatDeterministicSolve(nonogramBoard);
}

bool LineRepeatDeterministicSolver::lineRepeatDeterministicSolve(
    NonogramBoard &nonogramBoard) {
  RowLength rowLength = nonogramBoard.getRowLength();
  ColumnLength columnLength = nonogramBoard.getColumnLength();

  while (true) {
    bool proceed = false;
    for (RowIndex rowIndex : RowIndex::range(0, rowLength.getLength() - 1)) {
      // localHighlightIndexes.addRowIndex(rowIndex);

      Row rowLine = nonogramBoard.getRowLine(rowIndex);
      RowHintSetList rowHintSetList = nonogramBoard.getRowHintSetList();
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

      syncToSharedIfNeeded();

      if (waitAndCheckTermination(waitMillis))
        return false;

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

      syncToSharedIfNeeded();

      if (waitAndCheckTermination(waitMillis))
        return false;

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