# CMake version requirement
cmake_minimum_required(VERSION 3.11)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable FetchContent module
include(FetchContent)

# --- 1. Fetch GLFW ---
FetchContent_Declare(
    glfw_
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.3.8
)
FetchContent_MakeAvailable(glfw_)

# --- 2. Fetch ImGui ---
FetchContent_Declare(
    imgui_
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        docking
)
FetchContent_MakeAvailable(imgui_)

# --- 3. Find System OpenGL ---
find_package(OpenGL REQUIRED)


# --- ImGui Core Library (Unchanged) ---
add_library(imgui_library STATIC
    ${imgui__SOURCE_DIR}/imgui.cpp
    ${imgui__SOURCE_DIR}/imgui_draw.cpp
    ${imgui__SOURCE_DIR}/imgui_widgets.cpp
    ${imgui__SOURCE_DIR}/imgui_tables.cpp
    ${imgui__SOURCE_DIR}/imgui_demo.cpp
)
target_include_directories(imgui_library PUBLIC ${imgui__SOURCE_DIR})

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/imconfig.h")
    target_compile_definitions(imgui_library PUBLIC
        IMGUI_USER_CONFIG="${CMAKE_CURRENT_SOURCE_DIR}/imconfig.h"
    )
endif()

# --- Custom Library for ImGui Backends (Unchanged) ---
add_library(imgui_backends STATIC
    ${imgui__SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${imgui__SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui_backends PUBLIC
    ${imgui__SOURCE_DIR}
    ${imgui__SOURCE_DIR}/backends
    ${glfw__SOURCE_DIR}/include
)

# --- Glad Generation (Unchanged) ---
find_package(Python3 REQUIRED COMPONENTS Interpreter)
set(GLAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/gl")
set(GLAD_C "${GLAD_DIR}/src/glad.c")
set(GLAD_H "${GLAD_DIR}/include/glad/glad.h")
set(GLAD_KHR "${GLAD_DIR}/include/KHR/khrplatform.h")
add_custom_command(
    OUTPUT ${GLAD_C} ${GLAD_H} ${GLAD_KHR}
    COMMAND Python3::Interpreter -m glad --generator=c --out-path=${GLAD_DIR} --api="gl=3.3" --profile=core
    COMMENT "Generating Glad OpenGL loader..."
)
add_library(glad STATIC ${GLAD_C})
target_include_directories(glad PUBLIC
    ${GLAD_DIR}/include 
)

# =========================================================
#  Refactoring: Create a Static Library for Core Logic
# =========================================================

file(GLOB_RECURSE NONOGRAM_CORE_SOURCES "*.cpp")
list(REMOVE_ITEM NONOGRAM_CORE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

# Create the Core Logic Library Target
add_library(NonogramCoreLib STATIC
    ${NONOGRAM_CORE_SOURCES}
    ${GLAD_H}
    ${GLAD_KHR}
)

target_compile_definitions(NonogramCoreLib PUBLIC
    GLFW_INCLUDE_NONE
)

# Include directories (made PUBLIC so test code can access headers)
target_include_directories(NonogramCoreLib PUBLIC
    ${GLAD_DIR}/include 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link dependencies to the library (made PUBLIC for transitive linking)
target_link_libraries(NonogramCoreLib PUBLIC
    imgui_library
    imgui_backends
    glfw
    glad
    ${OPENGL_LIBRARIES}
)

if(WIN32)
    # System libraries required for linking on Windows (made PRIVATE as they aren't needed by consumers)
    target_link_libraries(NonogramCoreLib PRIVATE kernel32 user32 gdi32 winspool shell32 ole32 oleaut32 uuid comdlg32 advapi32)
endif()


# =========================================================
#  Application Executable (Links to the Library)
# =========================================================
# The executable now only includes main.cpp
add_executable(NonogramCore "main.cpp")

# Link to the core library we just created
target_link_libraries(NonogramCore PRIVATE NonogramCoreLib)

# Set the output directory
set_target_properties(NonogramCore PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)