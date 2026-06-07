#include "Solver/BothLineSolver/BothLineSolver.h"

BothLineSolver::BothLineSolver(
  const LineSolver<Core::RowOrientation> &row, const LineSolver<Core::ColumnOrientation> &col)
    : rowLineSolver(row), columnLineSolver(col) {}
