#ifndef VERSAN_CORE_LINESOLVERRESULT_H
#define VERSAN_CORE_LINESOLVERRESULT_H

namespace VersaN::Solver {

enum class LineSolverResult {
    Success,
    HasContradiction,
    Stopped,
};

} // namespace VersaN::Solver

#endif // VERSAN_CORE_LINESOLVERRESULT_H