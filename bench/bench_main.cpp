#include <benchmark/benchmark.h>
#include <string>
#include <vector>

// --- Example 1: Simple test to verify Google Benchmark is working ---

// This function measures the speed of creating a std::string.
static void BM_StringCreation(benchmark::State &state) {
  // The loop inside 'state' is the code being measured.
  // Google Benchmark determines how many times to run this loop automatically.
  for (auto _ : state) {
    std::string empty_string;
    // prevent the compiler from optimizing away the variable
    benchmark::DoNotOptimize(empty_string);
  }
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// --- Example 2: How to benchmark your Nonogram logic (Image) ---

// Assuming you have a function or class from your 'src' directory.
// For now, I'll define a dummy function to simulate work.
// inside real code: #include "NonogramSolver.h"
void DummySolverProcess() {
  int sum = 0;
  for (int i = 0; i < 1000; ++i) {
    sum += i;
  }
  // ensure the side effect is not optimized away
  benchmark::DoNotOptimize(sum);
}

static void BM_NonogramSolve(benchmark::State &state) {
  // Setup code (e.g., loading puzzle data) goes here, outside the loop.
  // std::vector<int> puzzle_data = ...;

  for (auto _ : state) {
    // This part is measured. Call your solver function here.
    DummySolverProcess();
  }
}
// Register the benchmark
BENCHMARK(BM_NonogramSolve);

// This macro generates the main() function automatically.
BENCHMARK_MAIN();