# CMakeList.txt : CMake project for Physical Simulation, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (CMakeTarget "src/Physical Simulation.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("vendor/glfw")
add_subdirectory("vendor/glew/build/cmake")
target_link_libraries(CMakeTarget glfw glew_s)
find_package(OpenGL REQUIRED)
target_link_libraries(CMakeTarget OpenGL::GL)
target_include_directories(CMakeTarget PRIVATE "vendor/glfw/include" "vendor/glew/include")