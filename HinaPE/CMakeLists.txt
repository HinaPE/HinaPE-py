cmake_minimum_required(VERSION 3.24)
project(HinaPEModules VERSION 1.0.0 DESCRIPTION "HinaPE Modules" LANGUAGES CXX)

add_executable(HinaPEModules)
set_target_properties(HinaPEModules PROPERTIES CXX_STANDARD 20 CXX_EXTENSIONS ON)
target_sources(HinaPEModules
        PRIVATE
        backends/platform.cpp
        main.cpp

        PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../
        FILES
        common.h
        backends/platform.h
        )
target_include_directories(HinaPEModules
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )
target_link_libraries(HinaPEModules
        PUBLIC
        glad glfw
        )