cmake_minimum_required(VERSION 3.22 VERSION 0.1.0)

project(Raylib)

set(HEADER_FILES src/pch/myzdin-pch.h)

set(SOURCE_FILES 
    src/main.c 
    ${HEADER_FILES}
    )

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(STANDARD_C_VERSION_FLAG "-std=c11")
set(OPTIMIZE_FLAG "-O3")
set(WARNING_FLAGS "-Werror -Wpedantic -Wall -Wextra -Wno-unknown-pragmas")

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${STANDARD_C_VERSION_FLAG} ${OPTIMIZE_FLAG} ${WARNING_FLAGS}")

add_executable(Raylib ${SOURCE_FILES})

target_link_libraries(Raylib -lraylib)

target_precompile_headers(Raylib PRIVATE ${HEADER_FILES})
