#include "Core/AlgorithmProfiler/AlgorithmProfiler.h"

namespace VersaN::Core {

AlgorithmProfiler::AlgorithmProfiler(double timeLimitMs, size_t stackLimitBytes)
    : timeLimitMilliseconds(timeLimitMs)
    , stackUsageLimitBytes(stackLimitBytes)
    , stackBaseAddress(0) {}

void AlgorithmProfiler::startMeasurement() {
    char localVariableForStackReference;
    stackBaseAddress = reinterpret_cast<uintptr_t>(&localVariableForStackReference);
    startTime = std::chrono::high_resolution_clock::now();
}

bool AlgorithmProfiler::isTimeLimitExceeded() const {
    auto currentTime = std::chrono::high_resolution_clock::now();
    double elapsedDuration =
      std::chrono::duration<double, std::milli>(currentTime - startTime).count();
    return elapsedDuration > timeLimitMilliseconds;
}

bool AlgorithmProfiler::isStackUsageLimitExceeded() const {
    char currentLocalVariable;
    uintptr_t currentStackPointer = reinterpret_cast<uintptr_t>(&currentLocalVariable);

    size_t currentUsage = (stackBaseAddress > currentStackPointer)
                            ? (stackBaseAddress - currentStackPointer)
                            : (currentStackPointer - stackBaseAddress);

    return currentUsage > stackUsageLimitBytes;
}

} // namespace VersaN::Core