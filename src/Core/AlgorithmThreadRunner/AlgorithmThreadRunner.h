#ifndef VERSANO_CORE_ALGORITHMTHREADRUNNER_H
#define VERSANO_CORE_ALGORITHMTHREADRUNNER_H

#include "Core/Board/Line/Line.h"
#include "Core/Hint/HintList/HintList.h"
#include "Rendering/Shared/ISender.h"
#include "Rendering/Shared/StopSignal/StopSignal.h"
#include "Solver/Solver/ISolver.h"

#include <atomic>
#include <thread>
#include <vector>

namespace VersaNo::Core {

class AlgorithmThreadRunner {
  private:
    Rendering::StopSignal &stopSignal;

    Rendering::ISender<NonogramBoard> &nonogramBoardSender;
    NonogramBoard &nonogramBoard;
    Solver::IBoardUpdateHandler &boardUpdateHandler;

  public:
    AlgorithmThreadRunner(
      Rendering::StopSignal &stopSignal,
      Rendering::ISender<NonogramBoard> &nonogramBoardSender,
      NonogramBoard &initialNonogramBoard,
      Solver::IBoardUpdateHandler &boardUpdateHandler);

    void run(Solver::ISolver &solver);
};

} // namespace VersaNo::Core

#endif // VERSANO_CORE_ALGORITHMTHREADRUNNER_H