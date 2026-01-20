#include "Algorithm/Backtrack/BacktrackAlgorithm/BacktrackAlgorithm.h"

#include "Board/Line/Line.h"
#include "Cell/CellChange/CellChange.h"
#include "Hint/HintSet/HintSet.h"
#include "Rendering/HighlightIndexes/HighlightIndexes.h"
#include "SampleData/Repository/SampleDataRepository.h"
#include "Shared/SharedDataAliases.h"
#include "Solver/Solver/ISolver.h"
#include <algorithm>
#include <chrono>

BacktrackAlgorithm::BacktrackAlgorithm(
    StopSignal &stopSignal, ISender<BacktrackBoard> &backtrackBoardSender,
    BacktrackBoard initialBacktrackBoard)
    : stopSignal(stopSignal), backtrackBoardSender(backtrackBoardSender),
      localBacktrackBoard(initialBacktrackBoard) {}

void BacktrackAlgorithm::run(ISolver &solver) {
  std::vector<Board> solutions;
  solver.solve(backtrackBoardSender, localBacktrackBoard, solutions);

  /*
  int counter = 0;
  while (true) {
    if (stopSignal.shouldStop())
      break;

    RowIndex rowIndex =
        RowIndex(counter % localBacktrackBoard.getRowLength().getLength());
    ColumnIndex columnIndex = ColumnIndex(
        counter % localBacktrackBoard.getColumnLength().getLength());
    localBacktrackBoard.applyCell(
        Coordinate(rowIndex, columnIndex),
        Cell((counter % 2 == 0) ? CellColor::Black : CellColor::White));

    if (backtrackBoardSender.isRequested()) {
      backtrackBoardSender.send(localBacktrackBoard);
    }

    counter++;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
    */
}