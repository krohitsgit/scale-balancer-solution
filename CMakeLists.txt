cmake_minimum_required(VERSION 3.10)
project(ScaleBalancer VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(scale_balancer 
    src/main.cpp
    src/scale_balancer.cpp
)
