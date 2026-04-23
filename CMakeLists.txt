cmake_minimum_required(VERSION 3.25)
project(purrticle VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets WebSockets)
find_package(GTest REQUIRED)
find_package(flatbuffers REQUIRED)

option(ENABLE_COVERAGE "Enable coverage reporting" OFF)
include(cmake/CodeCoverage.cmake)
include(CTest)

add_subdirectory(core)
add_subdirectory(app)
add_subdirectory(tests)
