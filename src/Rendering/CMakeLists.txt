file(GLOB_RECURSE RENDERING_SOURCES "*.cpp")

add_library(Rendering STATIC ${RENDERING_SOURCES})
target_include_directories(Rendering PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

# =========================================================
# 1. Glad (OpenGL Loader Generator)
# =========================================================
target_compile_definitions(Rendering PUBLIC 
    GLFW_INCLUDE_NONE
)

set(GLAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/gl")
set(GLAD_C   "${GLAD_DIR}/src/glad.c")
set(GLAD_H   "${GLAD_DIR}/include/glad/glad.h")
set(GLAD_KHR "${GLAD_DIR}/include/KHR/khrplatform.h")

add_custom_command(
    OUTPUT ${GLAD_C} ${GLAD_H} ${GLAD_KHR}
    COMMAND Python3::Interpreter -m glad --generator=c --out-path=${GLAD_DIR} --api="gl=3.3" --profile=core
    COMMENT "Generating Glad OpenGL loader..."
)
add_library(glad STATIC ${GLAD_C})
target_include_directories(glad PUBLIC ${GLAD_DIR}/include)

# =========================================================
# 2. ImGui (Graphical User Interface)
# =========================================================

# Target Definition: Core Library ---
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

# Target Definition: Backend Integration ---
add_library(imgui_backends STATIC
    ${imgui__SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${imgui__SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui_backends PUBLIC
    ${imgui__SOURCE_DIR}
    ${imgui__SOURCE_DIR}/backends
    ${glfw__SOURCE_DIR}/include
)

# =========================================================
# 3. Rendering Module Definition
# =========================================================
target_link_libraries(Rendering PUBLIC 
    Core
    glad
    imgui_library
    imgui_backends
    glfw
    ${OPENGL_LIBRARIES}
)