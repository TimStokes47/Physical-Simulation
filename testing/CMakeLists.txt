include (FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG v1.14.0)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# TODO: Add tests and install targets if needed.
enable_testing()

add_executable(hello_test "hello_test.cpp")
target_link_libraries(hello_test gtest_main PhysicalSimulation)
target_include_directories(hello_test PRIVATE gtest_src "../Physical Simulation/src")

include (GoogleTest)
gtest_discover_tests(hello_test)