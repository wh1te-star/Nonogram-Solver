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
    StopSignal &stopSignal, ISender<NonogramBoard> &nonogramBoardSender,
    NonogramBoard initialNonogramBoard)
    : stopSignal(stopSignal), nonogramBoardSender(nonogramBoardSender),
      localNonogramBoard(initialNonogramBoard) {}

void BacktrackAlgorithm::run(ISolver &solver) {
  std::vector<Board> solutions;
  solver.solve(nonogramBoardSender, localNonogramBoard, solutions);
  if(!solutions.empty()) {
    localNonogramBoard.applyBoard(solutions[0], true);
    nonogramBoardSender.send(localNonogramBoard);
  }
}