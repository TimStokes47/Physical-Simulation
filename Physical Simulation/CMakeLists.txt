﻿# CMakeList.txt : CMake project for Physical Simulation, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (CMakeTarget "src/Physical Simulation.cpp" "src/Physical Simulation.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()
