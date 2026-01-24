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
  if(!solutions.empty()) {
    localBacktrackBoard.applyBoard(solutions[0], true);
    backtrackBoardSender.send(localBacktrackBoard);
  }
}