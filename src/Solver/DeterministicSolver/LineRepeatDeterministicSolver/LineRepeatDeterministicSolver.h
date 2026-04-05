#ifndef VERSANO_CORE_LINEREPEATDETERMINISTICSOLVER_H
#define VERSANO_CORE_LINEREPEATDETERMINISTICSOLVER_H

#include "Rendering/Shared/StopSignal/StopSignal.h"
#include "Solver/DeterministicSolver/IDeterministicSolver.h"
#include "Solver/ExhaustivePlacementPatternFinder/IExhaustivePlacementPatternFinder.h"
#include "Solver/LineSolver/ILineSolver.h"
#include "Solver/ResultEnum/DeterministicSolverResult.h"

namespace VersaNo::Core {
class NonogramBoard;
}

namespace VersaNo::Solver {

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

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_LINEREPEATDETERMINISTICSOLVER_H