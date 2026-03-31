#include "AlgorithmThreadRunner/AlgorithmThreadRunner.h"

#include "Board/Line/Line.h"
#include "Cell/CellChange/CellChange.h"
#include "Hint/HintSet/HintSet.h"
#include "Rendering/HighlightIndexes/HighlightIndexes.h"
#include "SampleData/Repository/SampleDataRepository.h"
#include "Shared/SharedDataAliases.h"
#include "Solver/Solver/ISolver.h"
#include <algorithm>
#include <chrono>

AlgorithmThreadRunner::AlgorithmThreadRunner(
  StopSignal &stopSignal,
  ISender<NonogramBoard> &nonogramBoardSender,
  NonogramBoard &initialNonogramBoard, IBoardUpdateHandler &boardUpdateHandler)
    : stopSignal(stopSignal)
    , nonogramBoardSender(nonogramBoardSender)
    , nonogramBoard(initialNonogramBoard)
    , boardUpdateHandler(boardUpdateHandler) {}

void AlgorithmThreadRunner::run(ISolver &solver) {
    std::vector<Board> solutions;
    solver.solve(nonogramBoard, solutions, boardUpdateHandler);
    if (!solutions.empty()) {
        nonogramBoard.applyBoard(solutions[0], true);
        nonogramBoardSender.send(nonogramBoard);
    }
}