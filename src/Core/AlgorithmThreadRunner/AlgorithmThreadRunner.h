#ifndef BACKTRACKALGORITHM_H
#define BACKTRACKALGORITHM_H

#include "Core/Board/Line/Line.h"
#include "Core/Hint/HintSet/HintSet.h"
#include "Rendering/Shared/ISender.h"
#include "Rendering/Shared/StopSignal/StopSignal.h"
#include "Solver/Solver/ISolver.h"
#include <atomic>
#include <thread>
#include <vector>

class AlgorithmThreadRunner {
  private:
    StopSignal &stopSignal;

    ISender<NonogramBoard> &nonogramBoardSender;
    NonogramBoard &nonogramBoard;
    IBoardUpdateHandler &boardUpdateHandler;

  public:
    AlgorithmThreadRunner::AlgorithmThreadRunner(
      StopSignal &stopSignal,
      ISender<NonogramBoard> &nonogramBoardSender,
      NonogramBoard &initialNonogramBoard, IBoardUpdateHandler &boardUpdateHandler);

    void AlgorithmThreadRunner::run(ISolver &solver);
};

#endif