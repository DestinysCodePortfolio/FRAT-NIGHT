cmake_minimum_required(VERSION 3.2)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(googletest)

add_executable(runAllTests
	failingTests.cpp
	passingTests.cpp
)

target_link_libraries(runAllTests gmock gtest gtest_main)
target_link_libraries(runAllTests simpleLibrary)
