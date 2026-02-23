#ifndef BACKTRACKALGORITHM_H
#define BACKTRACKALGORITHM_H

#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Shared/ISender.h"
#include "Shared/StopSignal/StopSignal.h"
#include "Solver/Solver/ISolver.h"
#include <atomic>
#include <thread>
#include <vector>

class BacktrackAlgorithm {
private:
  StopSignal &stopSignal;

  ISender<NonogramBoard> &nonogramBoardSender;
  NonogramBoard localNonogramBoard;

public:
  BacktrackAlgorithm::BacktrackAlgorithm(
      StopSignal &stopSignal, ISender<NonogramBoard> &nonogramBoardSender,
      NonogramBoard initialNonogramBoard);

  void BacktrackAlgorithm::run(ISolver &solver);
};

#endif