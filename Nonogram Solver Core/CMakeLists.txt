# CMake version requirement
cmake_minimum_required(VERSION 3.11)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable FetchContent module for downloading dependencies from URL
include(FetchContent)

# --- 1. Fetch GLFW (Windowing and Input) ---
FetchContent_Declare(
    glfw_
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.3.8 # Use a specific, stable version tag
)
FetchContent_MakeAvailable(glfw_)


# --- 2. Fetch ImGui (Immediate Mode GUI) ---
FetchContent_Declare(
    imgui_
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        docking
)
FetchContent_MakeAvailable(imgui_)

# --- 3. Find System OpenGL (Rendering) ---
# Necessary for the OpenGL rendering backend
find_package(OpenGL REQUIRED)


# --- ImGui Core Library ---
# Custom target for ImGui core files, used as a dependency
add_library(imgui_library STATIC
    ${imgui__SOURCE_DIR}/imgui.cpp
    ${imgui__SOURCE_DIR}/imgui_draw.cpp
    ${imgui__SOURCE_DIR}/imgui_widgets.cpp
    ${imgui__SOURCE_DIR}/imgui_tables.cpp
    ${imgui__SOURCE_DIR}/imgui_demo.cpp
)

target_include_directories(imgui_library PUBLIC 
    ${imgui__SOURCE_DIR} 
)

# --- Custom Library for ImGui Backends ---
# Custom target for ImGui backends and the necessary OpenGL loader (gl3w)
add_library(imgui_backends STATIC
    # ImGui Backends
    ${imgui__SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${imgui__SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)

# Set includes for backends
target_include_directories(imgui_backends PUBLIC
    ${imgui__SOURCE_DIR}
    ${imgui__SOURCE_DIR}/backends
    ${glfw__SOURCE_DIR}/include
)

# glad generation
find_package(Python3 REQUIRED COMPONENTS Interpreter)
set(GLAD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/gl")
set(GLAD_C "${GLAD_DIR}/src/glad.c")
set(GLAD_H "${GLAD_DIR}/include/glad/glad.h")
add_custom_command(
    OUTPUT ${GLAD_C} ${GLAD_H}
    COMMAND Python3::Interpreter -m glad --generator=c --out-path=${GLAD_DIR} --api="gl=3.3" --profile=core
    COMMENT "Generating Glad OpenGL loader..."
)
add_library(glad STATIC
    ${GLAD_C}
)

target_include_directories(glad PUBLIC
    ${GLAD_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithm/Backtrack/BacktrackAlgorithm
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithm/Backtrack/BacktrackStack
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithm/ExhaustivePlacementPatternFindAlgorithm
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithm/FindLeftMostPlacementAlgorithm
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithm/FindRightMostPlacementAlgorithm
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithm/OverlapDeterminationAlgorithm
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithm/PlacementPatternCountAlgorithm
	${CMAKE_CURRENT_SOURCE_DIR}/Board/BacktrackBoard
	${CMAKE_CURRENT_SOURCE_DIR}/Board/Board
	${CMAKE_CURRENT_SOURCE_DIR}/Board/BoardLength
	${CMAKE_CURRENT_SOURCE_DIR}/Board/Line
	${CMAKE_CURRENT_SOURCE_DIR}/Board/NonogramBoard
	${CMAKE_CURRENT_SOURCE_DIR}/Cell/Cell
	${CMAKE_CURRENT_SOURCE_DIR}/Cell/CellColor
	${CMAKE_CURRENT_SOURCE_DIR}/Cell/CellLocation
	${CMAKE_CURRENT_SOURCE_DIR}/Cell/CellVector2D
	${CMAKE_CURRENT_SOURCE_DIR}/Hint/HintNumber
	${CMAKE_CURRENT_SOURCE_DIR}/Hint/HintSet
	${CMAKE_CURRENT_SOURCE_DIR}/Hint/HintSetList
	${CMAKE_CURRENT_SOURCE_DIR}/Index/CellIndex
	${CMAKE_CURRENT_SOURCE_DIR}/Index/Coordinate
	${CMAKE_CURRENT_SOURCE_DIR}/Placement/Placement
	${CMAKE_CURRENT_SOURCE_DIR}/Placement/PlacementCount
	${CMAKE_CURRENT_SOURCE_DIR}/Placement/PlacementCountList
	${CMAKE_CURRENT_SOURCE_DIR}/Rendering/FontData
	${CMAKE_CURRENT_SOURCE_DIR}/Rendering/HighlightIndexes
	${CMAKE_CURRENT_SOURCE_DIR}/Rendering/RenderingSystem
	${CMAKE_CURRENT_SOURCE_DIR}/Rendering/TableRenderer
	${CMAKE_CURRENT_SOURCE_DIR}/Shared/SharedBacktrackBoard
	${CMAKE_CURRENT_SOURCE_DIR}/Shared/SharedBacktrackStack
	${CMAKE_CURRENT_SOURCE_DIR}/Shared/SharedHighlightIndexes
	${CMAKE_CURRENT_SOURCE_DIR}/TestData/Repository
	${CMAKE_CURRENT_SOURCE_DIR}/TestData/TestData
)


# --- Application Executable ---
# Target name matches the desired executable name and avoids conflict with the parent project name
add_executable(
    NonogramSolverCore
    "main.cpp"
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
	"TestData/Repository/TestDataRepository.cpp"
	"TestData/TestData/TestDataDifficult.cpp"
	"TestData/TestData/TestDataEasy.cpp"
	"TestData/TestData/TestDataLambda.cpp"
	"TestData/TestData/TestDataLarge.cpp"
)


# --- Link everything together ---
# Link all dependencies to the main executable target
target_link_libraries(NonogramSolverCore PUBLIC
    # ImGui / GLFW / OpenGL
    imgui_library
    imgui_backends
    glfw           # Use global target name for fetched GLFW
    glad
    ${OPENGL_LIBRARIES}
)

# On Windows (MSVC), link system libraries required by GLFW/OpenGL
if(WIN32)
    # These system libraries are often required for proper linking on Windows
    target_link_libraries(NonogramSolverCore PRIVATE kernel32 user32 gdi32 winspool shell32 ole32 oleaut32 uuid comdlg32 advapi32)
endif()

# Set the output directory for the executable
set_target_properties(NonogramSolverCore PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
