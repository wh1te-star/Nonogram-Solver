#ifndef VERSAN_CORE_LINESOLVERRESULT_H
#define VERSAN_CORE_LINESOLVERRESULT_H

namespace VersaNo::Solver {

enum class LineSolverResult {
    Success,
    HasContradiction,
    Stopped,
};

} // namespace VersaNo::Solver

#endif // VERSAN_CORE_LINESOLVERRESULT_H