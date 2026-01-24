#include "Solver/DeterministicSolver/LineRepeatDeterministicSolver/LineRepeatDeterministicSolver.h"
#include "Placement/PlacementCount/PlacementCount.h"
#include "Solver/ExhaustivePlacementPatternFinder/DFSExhaustivePlacementPatternFinder/DFSExhaustivePlacementPatternFinder.h"

LineRepeatDeterministicSolver::LineRepeatDeterministicSolver(
    StopSignal &stopSignal, ILineSolver &lineSolver)
    : stopSignal(stopSignal), lineSolver(lineSolver) {}

DeterministicSolverResult LineRepeatDeterministicSolver::solve(
    ISender<BacktrackBoard> &sharedBacktrackBoard,
    BacktrackBoard &backtrackBoard) {
  return lineRepeatDeterministicSolve(sharedBacktrackBoard, backtrackBoard);
}

DeterministicSolverResult LineRepeatDeterministicSolver::lineRepeatDeterministicSolve(
    ISender<BacktrackBoard> &sharedBacktrackBoard,
    BacktrackBoard &backtrackBoard) {
  RowLength rowLength = backtrackBoard.getRowLength();
  ColumnLength columnLength = backtrackBoard.getColumnLength();

  while (true) {
    bool proceeded = false;
    for (RowIndex rowIndex : RowIndex::range(0, rowLength.getLength() - 1)) {
      // localHighlightIndexes.addRowIndex(rowIndex);

      Row rowLine = backtrackBoard.getRowLine(rowIndex);
      Row previousRowLine = rowLine;
      RowHintSetList rowHintSetList = backtrackBoard.getRowHintSetList();
      HintSet rowHintSet = rowHintSetList[rowIndex];

      bool hasContradiction = lineSolver.solve(rowHintSet, rowLine);
      if (hasContradiction) {
        return DeterministicSolverResult::HasContradiction;
      }

      backtrackBoard.applyRow(rowIndex, rowLine, false);

      if (rowLine != previousRowLine) {
        proceeded = true;
      }

      /*
      PlacementCount count = PlacementPatternCountAlgorithm::run(rowLine,
      rowHintSet); backtrackBoard.setRowPlacementCount(rowIndex, count);

      if (count == PlacementCount(0)) {
        return false;
      }
      if (count == PlacementCount(1)) {
        DFSExhaustivePlacementPatternFinder finder =
            DFSExhaustivePlacementPatternFinder();
        RowPlacement finalPlacement =
            finder.find(rowHintSet, rowLine)[0].toRowPlacement();
        localBacktrackBoard.applyRow(rowIndex, finalPlacement);
      }
        */

      if (sharedBacktrackBoard.isRequested()) {
        sharedBacktrackBoard.send(backtrackBoard);
      }

      if (stopSignal.shouldStop()) {
        return DeterministicSolverResult::Stopped;
      }

      // localHighlightIndexes.deleteRowIndex(rowIndex);
    }

    for (ColumnIndex columnIndex :
         ColumnIndex::range(0, columnLength.getLength() - 1)) {
      // localHighlightIndexes.addColumnIndex(columnIndex);

      Column columnLine = backtrackBoard.getColumnLine(columnIndex);
      Column previousColumnLine = columnLine;
      ColumnHintSetList columnHintSetList =
          backtrackBoard.getColumnHintSetList();
      HintSet columnHintSet = columnHintSetList[columnIndex];
      bool hasContradiction = lineSolver.solve(columnHintSet, columnLine);
      if (hasContradiction) {
        return DeterministicSolverResult::HasContradiction;
      }

      Column currentColumnLine = backtrackBoard.getColumnLine(columnIndex);
      backtrackBoard.applyColumn(columnIndex, columnLine, false);

      if (columnLine != previousColumnLine) {
        proceeded = true;
      }

      /*
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
        */

      if (sharedBacktrackBoard.isRequested()) {
        sharedBacktrackBoard.send(backtrackBoard);
      }
      if (stopSignal.shouldStop()) {
        return DeterministicSolverResult::Stopped;
      }

      // localHighlightIndexes.deleteColumnIndex(columnIndex);
    }

    if (backtrackBoard.isSolved()) {
      return DeterministicSolverResult::Solved;
    }
    if (proceeded == false) {
      return DeterministicSolverResult::NoMoreProgress;
    }
  }
  return DeterministicSolverResult::NoMoreProgress;
}