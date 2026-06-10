#include "Solver/BothLineSolver/BothLineSolver.h"

#include "Core/Types/AppliedType/AppliedType.h"

using namespace VersaNo::Core;
namespace VersaNo::Solver {

BothLineSolver::BothLineSolver(
  ILineSolver<Core::RowOrientation> &rowLineSolver,
  ILineSolver<Core::ColumnOrientation> &columnLineSolver)
    : rowLineSolver(rowLineSolver), columnLineSolver(columnLineSolver) {}

} // namespace VersaNo::Solver
