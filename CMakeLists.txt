cmake_minimum_required(VERSION 3.24)
project(HinaPE-py VERSION 1.0.0 DESCRIPTION "HinaPE is not a Physics Engine" LANGUAGES CXX)

add_subdirectory(vendor/glad)
add_subdirectory(vendor/glfw3)
add_subdirectory(vendor/pybind)
add_subdirectory(HinaPE)

pybind11_add_module(HinaPE main.cpp)
target_include_directories(HinaPE PRIVATE vendor)
target_link_libraries(HinaPE PRIVATE glad glfw)
