#ifndef VERSAN_CORE_DETERMINISTICSOLVERRESULT_H
#define VERSAN_CORE_DETERMINISTICSOLVERRESULT_H

namespace VersaN::Solver {

enum class DeterministicSolverResult { Solved, NoMoreProgress, HasContradiction, Stopped };

} // namespace VersaN::Solver

#endif // VERSAN_CORE_DETERMINISTICSOLVERRESULT_H