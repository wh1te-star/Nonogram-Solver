#ifndef VERSAN_CORE_ALGORITHMPROFILER_H
#define VERSAN_CORE_ALGORITHMPROFILER_H

#include <chrono>
#include <cstdint>

namespace VersaNo::Core {

class AlgorithmProfiler {
  private:
    const double timeLimitMilliseconds;
    const size_t stackUsageLimitBytes;

    uintptr_t stackBaseAddress;
    std::chrono::high_resolution_clock::time_point startTime;

  public:
    // Default time limit: 1000 ms, stack usage limit: 1 MB
    AlgorithmProfiler(double timeLimitMs = 1000.0, size_t stackLimitBytes = 1024 * 1024);

    void startMeasurement();
    bool isTimeLimitExceeded() const;
    bool isStackUsageLimitExceeded() const;
};

} // namespace VersaNo::Core

#endif // VERSAN_CORE_ALGORITHMPROFILER_H