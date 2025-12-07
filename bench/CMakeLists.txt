cmake_minimum_required(VERSION 3.10)

project(nonogram_benchmark)

# --- Google Benchmark Setup ---
include(FetchContent)

# Download Google Benchmark from GitHub
FetchContent_Declare(
  googlebenchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.8.3  # Specify a stable version tag
)

# Disable Google Benchmark's tests and install step to speed up build
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)

# Make the library available
FetchContent_MakeAvailable(googlebenchmark)

# --- Benchmark Target Setup ---

# Create an executable for the benchmark
# Assuming you have a source file named 'bench_main.cpp' in this directory
add_executable(run_benchmarks bench_main.cpp)

# Link against Google Benchmark
# benchmark::benchmark_main handles the main() function automatically
target_link_libraries(run_benchmarks PRIVATE benchmark::benchmark benchmark::benchmark_main)

# IMPORTANT: Link against your project's main library from 'src'
# Replace 'your_core_library_name' with the actual library target name defined in src/CMakeLists.txt
# target_link_libraries(run_benchmarks PRIVATE your_core_library_name)