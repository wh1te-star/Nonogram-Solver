#ifndef BACKTRACKALGORITHM_H
#define BACKTRACKALGORITHM_H

#include "Algorithm/Backtrack/BacktrackStack/BacktrackStack.h"
#include "Board/BacktrackBoard/BacktrackBoard.h"
#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Shared/ISender.h"
#include "Shared/StopSignal/StopSignal.h"
#include <atomic>
#include <thread>
#include <vector>

class BacktrackAlgorithm {
private:
  StopSignal &stopSignal;

  ISender<BacktrackBoard> &backtrackBoardSender;
  BacktrackBoard localBacktrackBoard;

public:
  BacktrackAlgorithm::BacktrackAlgorithm(
      StopSignal &stopSignal, ISender<BacktrackBoard> &backtrackBoardSender,
      BacktrackBoard initialBacktrackBoard);

  void run();
};

#endif