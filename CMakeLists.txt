cmake_minimum_required(VERSION 3.16)

project(6502)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

add_executable(
    emulator_tests

    tests/test_main.cpp
    tests/test_lda.cpp
    tests/test_ldx.cpp
    tests/test_transfer.cpp

    src/cpu.c
    src/memory.c
    src/instruction_set.c
)

target_include_directories(
    emulator_tests
    PRIVATE
    include
)

target_link_libraries(
    emulator_tests
    GTest::gtest
    GTest::gtest_main
)

enable_testing()
