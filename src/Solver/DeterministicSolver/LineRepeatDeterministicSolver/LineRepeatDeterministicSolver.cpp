#include "Solver/DeterministicSolver/LineRepeatDeterministicSolver/LineRepeatDeterministicSolver.h"

#include <cassert>
#include "Placement/PlacementCount/PlacementCount.h"
#include "Solver/ExhaustivePlacementPatternFinder/DFSExhaustivePlacementPatternFinder/DFSExhaustivePlacementPatternFinder.h"
#include "Solver/ResultEnum/LineSolverResult.h"

LineRepeatDeterministicSolver::LineRepeatDeterministicSolver(
  StopSignal &stopSignal, ILineSolver &lineSolver)
    : stopSignal(stopSignal), lineSolver(lineSolver) {}

DeterministicSolverResult LineRepeatDeterministicSolver::solve(
  ISender<NonogramBoard> &NonogramBoardSender, NonogramBoard &nonogramBoard) {
    return lineRepeatDeterministicSolve(NonogramBoardSender, nonogramBoard);
}

DeterministicSolverResult LineRepeatDeterministicSolver::lineRepeatDeterministicSolve(
  ISender<NonogramBoard> &sharedNonogramBoard, NonogramBoard &nonogramBoard) {
    RowLength rowLength = nonogramBoard.getRowLength();
    ColumnLength columnLength = nonogramBoard.getColumnLength();

    while (true) {
        bool proceeded = false;
        for (RowIndex rowIndex : RowIndex::range(0, rowLength.getLength() - 1)) {
            // localHighlightIndexes.addRowIndex(rowIndex);

            Row rowLine = nonogramBoard.getRowLine(rowIndex);
            Row previousRowLine = rowLine;
            RowHintSetList rowHintSetList = nonogramBoard.getRowHintSetList();
            HintSet rowHintSet = rowHintSetList[rowIndex];

            LineSolverResult lineSolverResult = lineSolver.solve(rowHintSet, rowLine);
            switch (lineSolverResult) {
            case LineSolverResult::Success:
                break;

            case LineSolverResult::HasContradiction:
                return DeterministicSolverResult::HasContradiction;

            default:
                assert(false);
                break;
            }

            nonogramBoard.applyRow(rowIndex, rowLine, false);

            if (rowLine != previousRowLine) {
                proceeded = true;
            }

            /*
            PlacementCount count = PlacementPatternCountAlgorithm::run(rowLine,
            rowHintSet); nonogramBoard.setRowPlacementCount(rowIndex, count);

            if (count == PlacementCount(0)) {
              return false;
            }
            if (count == PlacementCount(1)) {
              DFSExhaustivePlacementPatternFinder finder =
                  DFSExhaustivePlacementPatternFinder();
              RowPlacement finalPlacement =
                  finder.find(rowHintSet, rowLine)[0].toRowPlacement();
              nonogramBoard.applyRow(rowIndex, finalPlacement);
            }
              */

            if (sharedNonogramBoard.isRequested()) {
                sharedNonogramBoard.send(nonogramBoard);
            }

            if (stopSignal.shouldStop()) {
                return DeterministicSolverResult::Stopped;
            }

            // localHighlightIndexes.deleteRowIndex(rowIndex);
        }

        for (ColumnIndex columnIndex : ColumnIndex::range(0, columnLength.getLength() - 1)) {
            // localHighlightIndexes.addColumnIndex(columnIndex);

            Column columnLine = nonogramBoard.getColumnLine(columnIndex);
            Column previousColumnLine = columnLine;
            ColumnHintSetList columnHintSetList = nonogramBoard.getColumnHintSetList();
            HintSet columnHintSet = columnHintSetList[columnIndex];
            LineSolverResult lineSolverResult = lineSolver.solve(columnHintSet, columnLine);
            switch (lineSolverResult) {
            case LineSolverResult::Success:
                break;

            case LineSolverResult::HasContradiction:
                return DeterministicSolverResult::HasContradiction;

            default:
                assert(false);
                break;
            }

            Column currentColumnLine = nonogramBoard.getColumnLine(columnIndex);
            nonogramBoard.applyColumn(columnIndex, columnLine, false);

            if (columnLine != previousColumnLine) {
                proceeded = true;
            }

            /*
            PlacementCount count =
                PlacementPatternCountAlgorithm::run(columnLine, columnHintSet);

            nonogramBoard.setColumnPlacementCount(columnIndex, count);

            if (count == PlacementCount(0))
              return false;
            if (count == PlacementCount(1)) {
              ColumnPlacement finalPlacement =
                  ExhaustivePlacementPatternFinder::run(columnLine,
                                                               columnHintSet)[0]
                      .toColumnPlacement();
              nonogramBoard.applyColumn(columnIndex, finalPlacement);
            }
              */

            if (sharedNonogramBoard.isRequested()) {
                sharedNonogramBoard.send(nonogramBoard);
            }
            if (stopSignal.shouldStop()) {
                return DeterministicSolverResult::Stopped;
            }

            // localHighlightIndexes.deleteColumnIndex(columnIndex);
        }

        if (nonogramBoard.isSolved()) {
            return DeterministicSolverResult::Solved;
        }
        if (proceeded == false) {
            return DeterministicSolverResult::NoMoreProgress;
        }
    }
    return DeterministicSolverResult::NoMoreProgress;
}