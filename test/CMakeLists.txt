cmake_minimum_required(VERSION 3.20)
project(NonogramTests)

find_package(Python3 COMPONENTS Interpreter REQUIRED)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(GENERATED_DATA_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated_data")
set(GENERATED_HINTS_FILE "${GENERATED_DATA_DIR}/test_combinations.txt")

file(MAKE_DIRECTORY ${GENERATED_DATA_DIR})

add_custom_command(
  OUTPUT ${GENERATED_HINTS_FILE}
  COMMAND "${Python3_EXECUTABLE}" 
    "${CMAKE_SOURCE_DIR}/scripts/TestDataGenerator/generate_test_data.py"
    "${GENERATED_HINTS_FILE}"
  COMMENT "Generating combinations test data for Nonogram Solver..."
  VERBATIM
)

add_custom_target(generate_test_data ALL DEPENDS ${GENERATED_HINTS_FILE})

add_executable(
    NonogramTests
    "PlacementPatternCount.cpp" 
)

add_dependencies(NonogramTests generate_test_data)

target_link_libraries(NonogramTests PRIVATE
    NonogramCoreLib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(NonogramTests)