#!/bin/bash

# Create build directory
mkdir -p ./build

# Move into build directory
cd ./build/

# Run CMake
cmake ..

# Build the project
make

