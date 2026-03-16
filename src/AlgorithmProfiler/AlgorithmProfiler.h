#ifndef ALGORITHMPROFILER_H
#define ALGORITHMPROFILER_H

#include <chrono>
#include <cstdint>

class AlgorithmProfiler {
  private:
    const double timeLimitMilliseconds = 8000;
    const size_t stackUsageLimitBytes = 1024 * 1024; // 1 MB

    uintptr_t stackBaseAddress;
    std::chrono::high_resolution_clock::time_point startTime;

  public:
    AlgorithmProfiler(double timeLimitMs, size_t stackLimitBytes);

    void startMeasurement();
    bool isTimeLimitExceeded() const;
    bool isStackUsageLimitExceeded() const;
};

#endif // ALGORITHMPROFILER_H