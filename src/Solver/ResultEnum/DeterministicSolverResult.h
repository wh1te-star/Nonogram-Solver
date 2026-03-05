#ifndef DETERMINISTICSOLVERRESULT_H
#define DETERMINISTICSOLVERRESULT_H

enum class DeterministicSolverResult {
    Solved,
    NoMoreProgress,
    HasContradiction,
    Stopped
};

#endif