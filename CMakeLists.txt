cmake_minimum_required(VERSION 3.2)
project(sample_cpp_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/scripts/cmake" ${CMAKE_MODULE_PATH})

# Sets ${PROJECT_NAME}_COMPILE_OPTIONS to a list of compile options
include(scripts/cmake/SetProjectCompileOptions.cmake)
set_project_compile_options(${PROJECT_NAME}_COMPILE_OPTIONS)

# Configure main target(s)
set(${PROJECT_NAME}_SOURCE_FILES
        # List source files below
        src/library.cpp
        include/sample_cpp_project/library.hpp)
add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SOURCE_FILES})
target_compile_options(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_COMPILE_OPTIONS})
target_include_directories(${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        PRIVATE ${PROJECT_SOURCE_DIR}/src)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# Determine if this is being used as a subproject
set(${PROJECT_NAME}_IS_ROOT_PROJECT FALSE)
if (${PROJECT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    set(${PROJECT_NAME}_IS_ROOT_PROJECT TRUE)
endif ()

# Unit testing configuration
option(BUILD_TESTS "Build tests for project" OFF)
if (${BUILD_TESTS} AND ${${PROJECT_NAME}_IS_ROOT_PROJECT})
    add_subdirectory(tests)
endif ()

# Benchmarking configuration
option(BUILD_BENCHMARKS "Build benchmarks for project" OFF)
if (${BUILD_BENCHMARKS} AND ${${PROJECT_NAME}_IS_ROOT_PROJECT})
    add_subdirectory(benches)
endif ()

# Documentation configuration
option(BUILD_DOCUMENTATION "Build documentation for project" OFF)
if (${BUILD_DOCUMENTATION} AND ${${PROJECT_NAME}_IS_ROOT_PROJECT})
    add_subdirectory(docs)
endif ()
