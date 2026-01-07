#ifndef BACKTRACKALGORITHM_H
#define BACKTRACKALGORITHM_H

#include "Algorithm/Backtrack/BacktrackStack/BacktrackStack.h"
#include "Board/BacktrackBoard/BacktrackBoard.h"
#include "Board/Line/Line.h"
#include "Hint/HintSet/HintSet.h"
#include "Shared/ISender.h"
#include "Shared/StopSignal/StopSignal/StopSignal.h"
#include <atomic>
#include <thread>
#include <vector>

class AlgorithmThread {
private:
  IStopSignal &stopSignal;

  ISender<BacktrackBoard> &backtrackBoardSender;

  BacktrackBoard localBacktrackBoard;

public:
  AlgorithmThread::AlgorithmThread(
      IStopSignal &stopSignal, ISender<BacktrackBoard> &backtrackBoardSender,
      const BacktrackBoard &initialBacktrackBoard);

      void run();
};

#endif