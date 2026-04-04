file(GLOB_RECURSE CORE_SOURCES "*.cpp")

add_library(Core STATIC ${CORE_SOURCES})
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)