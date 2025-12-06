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

# Define source files for the core logic (Everything EXCEPT main.cpp)
set(NONOGRAM_CORE_SOURCES
    "Algorithm/Backtrack/BacktrackAlgorithm/BacktrackAlgorithm.cpp"
    "Algorithm/Backtrack/BacktrackStack/BacktrackStack.cpp"
    "Algorithm/ExhaustivePlacementPatternFindAlgorithm/ExhaustivePlacementPatternFindAlgorithm.cpp"
    "Algorithm/FindLeftMostPlacementAlgorithm/FindLeftMostPlacementAlgorithm.cpp"
    "Algorithm/FindRightMostPlacementAlgorithm/FindRightMostPlacementAlgorithm.cpp"
    "Algorithm/OverlapDeterminationAlgorithm/OverlapDeterminationAlgorithm.cpp"
    "Algorithm/PlacementPatternCountAlgorithm/PlacementPatternCountAlgorithm.cpp"
    "Board/BacktrackBoard/BacktrackBoard.cpp"
    "Board/Board/Board.cpp"
    "Board/BoardLength/BoardLength.cpp"
    "Board/BoardLength/ColumnLength.cpp"
    "Board/BoardLength/RowLength.cpp"
    "Board/Line/Column.cpp"
    "Board/Line/Line.cpp"
    "Board/Line/Row.cpp"
    "Board/NonogramBoard/NonogramBoard.cpp"
    "Cell/Cell/Cell.cpp"
    "Cell/CellLocation/CellLocation.cpp"
    "Hint/HintNumber/HintNumber.cpp"
    "Hint/HintSet/HintSet.cpp"
    "Hint/HintSetList/ColumnHintSetList.cpp"
    "Hint/HintSetList/HintSetList.cpp"
    "Hint/HintSetList/RowHintSetList.cpp"
    "Index/CellIndex/CellIndex.cpp"
    "Index/CellIndex/ColumnIndex.cpp"
    "Index/CellIndex/RowIndex.cpp"
    "Index/Coordinate/Coordinate.cpp"
    "Placement/Placement/ColumnPlacement.cpp"
    "Placement/Placement/Placement.cpp"
    "Placement/Placement/RowPlacement.cpp"
    "Placement/PlacementCount/PlacementCount.cpp"
    "Placement/PlacementCountList/ColumnPlacementCountList.cpp"
    "Placement/PlacementCountList/PlacementCountList.cpp"
    "Placement/PlacementCountList/RowPlacementCountList.cpp"
    "Rendering/FontData/FontData.cpp"
    "Rendering/HighlightIndexes/HighlightIndexes.cpp"
    "Rendering/RenderingSystem/RenderingSystem.cpp"
    "Rendering/TableRenderer/TableRenderer.cpp"
    "Shared/SharedBacktrackBoard/SharedBacktrackBoard.cpp"
    "Shared/SharedBacktrackStack/SharedBacktrackStack.cpp"
    "Shared/SharedHighlightIndexes/SharedHighlightIndexes.cpp"
    "SampleData/Repository/SampleDataRepository.cpp"
    "SampleData/SampleData/SampleDataDifficult.cpp"
    "SampleData/SampleData/SampleDataEasy.cpp"
    "SampleData/SampleData/SampleDataLambda.cpp"
    "SampleData/SampleData/SampleDataLarge.cpp"
)

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