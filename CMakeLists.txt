cmake_minimum_required(VERSION 3.28)
project(TrigHype C)

set(CMAKE_C_STANDARD 23)

# Library target
add_library(trighype_lib STATIC
        src/lib/include/trighype.h
        src/lib/include/trigonometric.h
        src/lib/include/hyperbolic.h
        src/lib/trigonometric.c
        src/lib/hyperbolic.c
)
target_include_directories(trighype_lib PRIVATE src/lib/include)
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
