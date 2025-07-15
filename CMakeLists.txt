cmake_minimum_required(VERSION 3.30)

project(turing-machines)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(turing-machines ${sources})

target_include_directories(turing-machines PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)