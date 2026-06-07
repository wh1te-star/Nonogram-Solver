#ifndef VERSANO_SOLVER_BOTHLINESOLVER_BOTHLINESOLVER_H
#define VERSANO_SOLVER_BOTHLINESOLVER_BOTHLINESOLVER_H

#include "Core/Types/AppliedType/AppliedType.h"
#include "Solver/LineSolver/ILineSolver.h"
#include "Solver/ResultEnum/DeterministicSolverResult.h"

namespace VersaNo::Solver {

class BothLineSolver {
  public:
    ILineSolver<Core::RowOrientation> &rowLineSolver;
    ILineSolver<Core::ColumnOrientation> &columnLineSolver;

    BothLineSolver(
      const ILineSolver<Core::RowOrientation> &row,
      const ILineSolver<Core::ColumnOrientation> &col);
};

} // namespace VersaNo::Solver

#endif // VERSANO_SOLVER_BOTHLINESOLVER_BOTHLINESOLVER_H