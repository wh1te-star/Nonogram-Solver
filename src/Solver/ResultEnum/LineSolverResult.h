#ifndef VERSANO_CORE_LINESOLVERRESULT_H
#define VERSANO_CORE_LINESOLVERRESULT_H

namespace VersaNo::Solver {

enum class LineSolverResult {
    Success,
    HasContradiction,
    Stopped,
};

} // namespace VersaNo::Solver

#endif // VERSANO_CORE_LINESOLVERRESULT_H