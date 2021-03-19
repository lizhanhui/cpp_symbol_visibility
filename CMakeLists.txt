cmake_minimum_required(VERSION 3.17)
project(sample)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(GenerateExportHeader)

add_library(calc SHARED)
target_sources(calc PRIVATE Calc.cpp)
target_include_directories(calc
        PUBLIC
        ${CMAKE_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include)
GENERATE_EXPORT_HEADER(calc
        BASE_NAME CALC
        EXPORT_MACRO_NAME CALC_EXPORT_API
        EXPORT_FILE_NAME calc_export.h
        STATIC_DEFINE CALC_STATIC)
target_compile_definitions(calc PRIVATE CALC_EXPORTS)

add_library(calc_static STATIC)
target_sources(calc_static PRIVATE Calc.cpp)
target_compile_definitions(calc_static PRIVATE CALC_STATIC)
target_include_directories(calc_static
        PUBLIC
        ${CMAKE_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(sample main.cpp)
target_link_libraries(sample
        PRIVATE
            calc)