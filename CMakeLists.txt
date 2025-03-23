cmake_minimum_required(VERSION 3.10)
project(submodule-3.2)

enable_testing()

# Create a library that can be linked against
add_library(submodule32_lib submodule32.c)

# Create the executable with a different name
add_executable(submodule32 submodule32.c)

# Add Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Compile test executable
add_executable(test-submodule32 test-submodule32.cpp)
target_link_libraries(test-submodule32 GTest::GTest GTest::Main pthread submodule32_lib)

# Register test with CTest
add_test(NAME submodule3_2_test COMMAND test-submodule32)

# Make the library target available to parent projects
set_target_properties(submodule32_lib PROPERTIES EXPORT_NAME submodule32_lib)
