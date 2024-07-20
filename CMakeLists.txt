cmake_minimum_required(VERSION 3.10)

# Project name
project(CubeAnalysis)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cc
    src/cube.cc
    src/turns.cc
)

# Add executable
add_executable(analysis ${SOURCES})
