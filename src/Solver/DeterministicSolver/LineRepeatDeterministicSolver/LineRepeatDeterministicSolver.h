#ifndef VERSANO_CORE_LINEREPEATDETERMINISTICSOLVER_H
#define VERSANO_CORE_LINEREPEATDETERMINISTICSOLVER_H

#include "Core/Types/AppliedType/AppliedType.h"
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
    ILineSolver<Core::RowOrientation> &rowLineSolver;
    ILineSolver<Core::ColumnOrientation> &columnLineSolver;

    LineRepeatDeterministicSolver(
      Rendering::StopSignal &stopSignal, ILineSolver<Core::RowOrientation> &rowLineSolver, ILineSolver<Core::ColumnOrientation> &columnLineSolver);
    DeterministicSolverResult
    solve(Core::NonogramBoard &nonogramBoard, Core::IBoardUpdateHandler &boardUpdateHandler) override;

  private:
    DeterministicSolverResult lineRepeatDeterministicSolve(
      Core::NonogramBoard &nonogramBoard, Core::IBoardUpdateHandler &boardUpdateHandler);
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_LINEREPEATDETERMINISTICSOLVER_H