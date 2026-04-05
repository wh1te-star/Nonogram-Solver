#ifndef VERSAN_CORE_LINEREPEATDETERMINISTICSOLVER_H
#define VERSAN_CORE_LINEREPEATDETERMINISTICSOLVER_H

#include "Rendering/Shared/StopSignal/StopSignal.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include "Solver/LineSolver/ILineSolver.h"
#include "Solver/ResultEnum/DeterministicSolverResult.h"

namespace VersaN::Core {
class NonogramBoard;
}

namespace VersaN::Solver {

class LineRepeatDeterministicSolver : public IDeterministicSolver {
  public:
    Rendering::StopSignal &stopSignal;
    ILineSolver &lineSolver;

    LineRepeatDeterministicSolver(Rendering::StopSignal &stopSignal, ILineSolver &lineSolver);
    DeterministicSolverResult
    solve(Core::NonogramBoard &nonogramBoard, IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    DeterministicSolverResult lineRepeatDeterministicSolve(
      Core::NonogramBoard &nonogramBoard, IBoardUpdateHandler &boardUpdateHandler);
};

} // namespace VersaN::Solver

#endif // VERSAN_CORE_LINEREPEATDETERMINISTICSOLVER_H