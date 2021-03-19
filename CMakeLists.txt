cmake_minimum_required(VERSION 3.17)
project(qt_cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH /opt/Qt/5.15.2/gcc_64/)

find_package(Qt5 5.15.2 EXACT REQUIRED COMPONENTS Widgets Core Charts)

add_executable(qt_cmake
               main.cpp
               chartview.cpp)

find_library(LIBRARY_NAME PATHS CMAKE_PREFIX_PATH NO_DEFAULT_PATH)

target_link_libraries(qt_cmake Qt5::Widgets Qt5::Charts)