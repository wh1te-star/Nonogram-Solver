#ifndef VERSAN_CORE_DETERMINISTICSOLVERRESULT_H
#define VERSAN_CORE_DETERMINISTICSOLVERRESULT_H

namespace VersaNo::Solver {

enum class DeterministicSolverResult { Solved, NoMoreProgress, HasContradiction, Stopped };

} // namespace VersaNo::Solver

#endif // VERSAN_CORE_DETERMINISTICSOLVERRESULT_H