# CMake version requirement
cmake_minimum_required(VERSION 3.10)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# =========================================================
# 1. Add Subdirectories
# =========================================================
add_subdirectory(Core)
add_subdirectory(Solver)
add_subdirectory(Rendering)

# =========================================================
# 2. Application Executable
# =========================================================
add_executable(NonogramApp "main.cpp")

target_link_libraries(NonogramApp PRIVATE 
    Solver
    Rendering
)

set_target_properties(NonogramApp PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)