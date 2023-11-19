# CMakeList.txt : CMake project for Physical Simulation, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library (PhysicalSimulation STATIC "src/maths/vec3" "src/graphics/renderer.cpp" "src/graphics/window.cpp" "src/core/input.cpp" "src/graphics/shader.cpp" "src/graphics/mesh.cpp" "src/maths/mat4.cpp" "src/maths/uvec3.cpp" "src/graphics/camera.cpp" "src/physics/particle.cpp")

add_executable (Sandbox "src/Physical Simulation.cpp")
target_link_libraries(Sandbox PhysicalSimulation)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PhysicalSimulation PROPERTY CXX_STANDARD 20)
endif()

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("vendor/glfw")
add_subdirectory("vendor/glew/build/cmake")
target_link_libraries(PhysicalSimulation glfw glew_s)
find_package(OpenGL REQUIRED)
target_link_libraries(PhysicalSimulation OpenGL::GL)
target_include_directories(PhysicalSimulation PRIVATE "vendor/glfw/include" "vendor/glew/include")