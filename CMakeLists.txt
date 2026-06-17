cmake_minimum_required(VERSION 3.16)

project(6502 C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ============================================================
# Emulator core library
# ============================================================

add_library(
    emulator_core

    src/cpu.c
    src/memory.c
    src/instruction_set.c
)

target_include_directories(
    emulator_core
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# ============================================================
# Emulator executable
# ============================================================

add_executable(
    emulator

    main.c
)

target_link_libraries(
    emulator
    PRIVATE
    emulator_core
)

# ============================================================
# Tests
# ============================================================

find_package(GTest REQUIRED)

add_executable(
    emulator_tests
    tests/test_main.cpp
    #tests/test_cpu.cpp
    #tests/test_memory.cpp
    tests/test_lda.cpp
    #tests/test_ldx.cpp
    #tests/test_transfer.cpp
)

target_link_libraries(
    emulator_tests
    PRIVATE
    emulator_core
    GTest::gtest
    GTest::gtest_main
)

enable_testing()

add_test(
    NAME emulator_tests
    COMMAND emulator_tests
)
