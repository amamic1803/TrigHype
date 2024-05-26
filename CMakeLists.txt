cmake_minimum_required(VERSION 3.28)
project(TrigHype C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_CLANG_TIDY clang-tidy -warnings-as-errors=*)

include(CTest)

# Library target
add_library(trighype_lib STATIC
        src/lib/include/trighype.h
        src/lib/include/trigonometric.h
        src/lib/include/hyperbolic.h
        src/lib/include/trig_math.h
        src/lib/trigonometric.c
        src/lib/hyperbolic.c
        src/lib/trig_math.c
)
target_include_directories(trighype_lib PRIVATE src/lib/include)
target_link_libraries(trighype_lib m)
set_target_properties(trighype_lib PROPERTIES
        OUTPUT_NAME trighype
        PUBLIC_HEADER src/lib/include/trighype.h
        PRIVATE_HEADER src/lib/include/trigonometric.h
        PRIVATE_HEADER src/lib/include/hyperbolic.h
)

# Executable target
add_executable(trighype_cli src/bin/main.c)
target_include_directories(trighype_cli PRIVATE src/lib/include)
target_link_libraries(trighype_cli trighype_lib)
set_target_properties(trighype_cli PROPERTIES
        OUTPUT_NAME trighype
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Tests target
add_executable(trighype_tests src/tests/tests.c src/tests/tests.h)
target_include_directories(trighype_tests PRIVATE src/lib/include)
target_link_libraries(trighype_tests trighype_lib)
target_link_libraries(trighype_tests m)
set_target_properties(trighype_tests PROPERTIES
        OUTPUT_NAME trighype_tests
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)
add_test(NAME test_sin COMMAND trighype_tests sin)
add_test(NAME test_cos COMMAND trighype_tests cos)
add_test(NAME test_sinh COMMAND trighype_tests sinh)
add_test(NAME test_cosh COMMAND trighype_tests cosh)
