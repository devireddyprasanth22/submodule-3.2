cmake_minimum_required(VERSION 3.10)
project(master-software)

enable_testing() 

# Add Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Compile main program
add_executable(masterSoftware masterSoftware.c)

# Compile test executable
add_executable(test-masterSoftware test-masterSoftware.cpp)
target_link_libraries(test-masterSoftware GTest::GTest GTest::Main pthread)

# Register test with CTest
add_test(NAME master-software-test COMMAND test-masterSoftware)

