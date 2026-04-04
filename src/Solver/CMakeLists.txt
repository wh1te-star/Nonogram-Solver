file(GLOB_RECURSE SOLVER_SOURCES "*.cpp")

add_library(Solver STATIC ${SOLVER_SOURCES})
target_include_directories(Solver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(Solver PUBLIC Core)