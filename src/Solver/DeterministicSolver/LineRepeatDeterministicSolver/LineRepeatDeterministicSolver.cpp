#include "Solver/DeterministicSolver/LineRepeatDeterministicSolver/LineRepeatDeterministicSolver.h"

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/ExhaustivePlacementPatternFinder/DFSExhaustivePlacementPatternFinder/DFSExhaustivePlacementPatternFinder.h"
#include "Solver/ResultEnum/LineSolverResult.h"

#include <cassert>

using namespace VersaNo::Core;
namespace VersaNo::Solver {

LineRepeatDeterministicSolver::LineRepeatDeterministicSolver(
  Rendering::StopSignal &stopSignal,
  ILineSolver<RowOrientation> &rowLineSolver,
  ILineSolver<ColumnOrientation> &columnLineSolver)
    : stopSignal(stopSignal), rowLineSolver(rowLineSolver), columnLineSolver(columnLineSolver) {}

DeterministicSolverResult LineRepeatDeterministicSolver::solve(
  NonogramBoard &nonogramBoard, IBoardUpdateHandler &boardUpdateHandler) {
    return lineRepeatDeterministicSolve(nonogramBoard, boardUpdateHandler);
}

DeterministicSolverResult LineRepeatDeterministicSolver::lineRepeatDeterministicSolve(
  NonogramBoard &nonogramBoard, IBoardUpdateHandler &boardUpdateHandler) {
    RowLength rowLength = nonogramBoard.getLength<RowOrientation>();
    ColumnLength columnLength = nonogramBoard.getLength<ColumnOrientation>();

    while (true) {
        bool proceeded = false;
        for (RowIndex rowIndex : RowIndex::closedRangeUp(0, rowLength.value - 1)) {
            // localHighlightIndexes.addRowIndex(rowIndex);

            RowPosition rowPosition(rowIndex);
            Row rowLine = nonogramBoard.getLine<RowOrientation>(rowIndex);
            Row previousRowLine = rowLine;
            RowHintGroup rowHintGroup = nonogramBoard.getHintGroup<RowOrientation>();
            HintList rowHintList = rowHintGroup[rowIndex];

            LineSolverResult lineSolverResult = rowLineSolver.solve(
              rowHintList, rowLine, boardUpdateHandler);
            switch (lineSolverResult) {
            case LineSolverResult::Success:
                break;

            case LineSolverResult::HasContradiction:
                return DeterministicSolverResult::HasContradiction;

            default:
                assert(false);
                break;
            }

            nonogramBoard.applyLine<RowOrientation>(rowPosition, rowLine, false);

            if (rowLine != previousRowLine) {
                proceeded = true;
                boardUpdateHandler.onRowUpdate(
                  rowIndex, rowLine, previousRowLine,
                  nonogramBoard.getLine<RowOrientation>(rowIndex));
            }

            /*
            PlacementCount count = PlacementPatternCountAlgorithm::run(rowLine,
            rowHintList); nonogramBoard.setRowPlacementCount(rowIndex, count);

            if (count == PlacementCount(0)) {
              return false;
            }
            if (count == PlacementCount(1)) {
              DFSExhaustivePlacementPatternFinder finder =
                  DFSExhaustivePlacementPatternFinder();
              RowPlacement finalPlacement =
                  finder.find(rowHintList, rowLine)[0].toRowPlacement();
              nonogramBoard.applyRow(rowIndex, finalPlacement);
            }
              */

            if (stopSignal.shouldStop()) {
                return DeterministicSolverResult::Stopped;
            }

            // localHighlightIndexes.deleteRowIndex(rowIndex);
        }

        for (ColumnIndex columnIndex : ColumnIndex::closedRangeUp(0, columnLength.value - 1)) {
            // localHighlightIndexes.addColumnIndex(columnIndex);

            ColumnPosition columnPosition(columnIndex);
            Column columnLine = nonogramBoard.getLine<ColumnOrientation>(columnIndex);
            Column previousColumnLine = columnLine;
            ColumnHintGroup columnHintGroup = nonogramBoard.getHintGroup<ColumnOrientation>();
            HintList columnHintList = columnHintGroup[columnIndex];

            LineSolverResult lineSolverResult = columnLineSolver.solve(
              columnHintList, columnLine, boardUpdateHandler);
            switch (lineSolverResult) {
            case LineSolverResult::Success:
                break;

            case LineSolverResult::HasContradiction:
                return DeterministicSolverResult::HasContradiction;

            default:
                assert(false);
                break;
            }

            Column currentColumnLine = nonogramBoard.getLine<ColumnOrientation>(columnIndex);
            nonogramBoard.applyLine<ColumnOrientation>(columnPosition, columnLine, false);

            if (columnLine != previousColumnLine) {
                proceeded = true;
                boardUpdateHandler.onColumnUpdate(
                  columnIndex, columnLine, previousColumnLine, currentColumnLine);
            }

            /*
            PlacementCount count =
                PlacementPatternCountAlgorithm::run(columnLine, columnHintList);

            nonogramBoard.setColumnPlacementCount(columnIndex, count);

            if (count == PlacementCount(0))
              return false;
            if (count == PlacementCount(1)) {
              ColumnPlacement finalPlacement =
                  ExhaustivePlacementPatternFinder::run(columnLine,
                                                               columnHintList)[0]
                      .toColumnPlacement();
              nonogramBoard.applyColumn(columnIndex, finalPlacement);
            }
              */

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

} // namespace VersaNo::Solver