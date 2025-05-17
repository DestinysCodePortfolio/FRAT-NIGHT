cmake_minimum_required(VERSION 3.2)

add_library(simpleLibrary
  main.cpp
	interfaceTerminal.cpp
  scene.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})

