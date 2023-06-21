cmake_minimum_required(VERSION 3.12)
project(inventory_management)

# Set the output directory for the build artifacts
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Add the include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add the source files
set(SOURCES
    src/inventory.cpp
    src/commands.cpp
    src/main.cpp
)

# Create the executable
add_executable(inventory_management ${SOURCES})
