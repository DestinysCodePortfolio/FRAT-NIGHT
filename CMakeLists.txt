CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
project(Frat-Night)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${LIBRARY_OUTPUT_PATH})

include_directories(
  ${CMAKE_SOURCE_DIR}/test/lib/googletest/include/
  ${CMAKE_SOURCE_DIR}/test/lib/googlemock/include/
)
add_executable(Rush_Week
    lib/main.cpp
		lib/interfaceTerminal.cpp
		lib/npcClass.cpp
		lib/player.cpp
		lib/scene.cpp
		lib/dialogueTree.cpp
)

add_subdirectory(lib)
add_subdirectory(test)

# target_compile_options(debug PRIVATE -g)
# ^^^ turn on debug