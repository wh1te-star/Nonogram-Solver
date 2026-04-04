# CMake version requirement
cmake_minimum_required(VERSION 3.10)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Nonogram Solver")

string(TOUPPER "${CMAKE_BUILD_TYPE}" UPPER_BUILD_TYPE)

# =========================================================
# Setup external dependencies
# =========================================================
include(FetchContent)
find_package(OpenGL REQUIRED)
find_package(Python3 REQUIRED COMPONENTS Interpreter)

# GLFW (Window & Input Management)
FetchContent_Declare(
    glfw_
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.3.8
)
FetchContent_MakeAvailable(glfw_)

# ImGui (Graphical User Interface)
FetchContent_Declare(
    imgui_
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        docking
)
FetchContent_MakeAvailable(imgui_)


# =========================================================
# Submodule setup
# =========================================================
add_subdirectory (src)

enable_testing()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test")
    add_subdirectory(test)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/bench")
    add_subdirectory(bench)
endif()