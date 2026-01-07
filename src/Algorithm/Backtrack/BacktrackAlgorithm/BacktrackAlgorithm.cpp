#include "Algorithm/Backtrack/BacktrackAlgorithm/BacktrackAlgorithm.h"

#include "Board/Line/Line.h"
#include "Cell/CellChange/CellChange.h"
#include "Hint/HintSet/HintSet.h"
#include "Rendering/HighlightIndexes/HighlightIndexes.h"
#include "SampleData/Repository/SampleDataRepository.h"
#include "Shared/SharedDataAliases.h"
#include <algorithm>
#include <chrono>

AlgorithmThread::AlgorithmThread(IStopSignal &stopSignal,
                                 ISender<BacktrackBoard> &backtrackBoardSender,
                                 const BacktrackBoard &initialBacktrackBoard)
    : stopSignal(stopSignal), backtrackBoardSender(backtrackBoardSender),
      localBacktrackBoard(initialBacktrackBoard) {}

void AlgorithmThread::run() {
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
}