#ifndef VERSANO_CORE_DETERMINISTICSOLVERRESULT_H
#define VERSANO_CORE_DETERMINISTICSOLVERRESULT_H

namespace VersaNo::Solver {

enum class DeterministicSolverResult { Solved, NoMoreProgress, HasContradiction, Stopped };

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_DETERMINISTICSOLVERRESULT_H