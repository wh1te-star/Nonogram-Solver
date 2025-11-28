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

# --- 2.5. Fetch glad (OpenGL Loader) ---
FetchContent_Declare(
    glad_
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG        v2.0.8 # Stable version
    
    # ★ 解決策：gladのビルドオプションを設定する
    CMAKE_ARGS 
        -DGLAD_API=gl=4.6      # 使用するOpenGLバージョンを指定
        -DGLAD_PROFILE=core    # コアプロファイルを使う
        -DGLAD_ALL_LANGUAGES=ON # 全ての言語でヘッダーを生成
        -DGLAD_EXPORT=ON       # エクスポートをONにする
)
FetchContent_MakeAvailable(glad_)

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

# インクルードパスの設定
target_include_directories(glad PUBLIC
    ${GLAD_DIR}/include
)


# --- Application Executable ---
# Target name matches the desired executable name and avoids conflict with the parent project name
add_executable(
    NonogramSolverCore
    "main.cpp"
    # Add other core source files (.cpp) here as needed
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
