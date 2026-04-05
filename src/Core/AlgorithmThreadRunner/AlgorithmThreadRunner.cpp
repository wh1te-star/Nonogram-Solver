#include "Core/AlgorithmThreadRunner/AlgorithmThreadRunner.h"

#include "Core/Board/Line/Line.h"
#include "Core/Hint/HintSet/HintSet.h"
#include "Core/PuzzleLoader/PuzzleLoader/PuzzleLoader.h"
#include "Rendering/HighlightIndexes/HighlightIndexes.h"
#include "Rendering/Shared/SharedDataAliases.h"
#include "Solver/Solver/ISolver.h"

#include <algorithm>
#include <chrono>

using namespace VersaNo::Rendering;
using namespace VersaNo::Solver;
namespace VersaNo::Core {

AlgorithmThreadRunner::AlgorithmThreadRunner(
  StopSignal &stopSignal,
  ISender<NonogramBoard> &nonogramBoardSender,
  NonogramBoard &initialNonogramBoard,
  IBoardUpdateHandler &boardUpdateHandler)
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

} // namespace VersaNo::Core