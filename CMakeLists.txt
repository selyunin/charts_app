cmake_minimum_required(VERSION 3.17)

set(EXECUTABLE app)

project(${EXECUTABLE})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH /opt/Qt/5.15.2/gcc_64/)

find_package(Qt5 5.15.2 EXACT REQUIRED COMPONENTS Widgets Core Charts)

add_executable(${EXECUTABLE}
               main.cpp
               chartview.cpp
               SdbMainWindow.cpp)

find_library(LIBRARY_NAME PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)

target_link_libraries(${EXECUTABLE} Qt5::Widgets Qt5::Charts)


install(TARGETS ${EXECUTABLE}
    DESTINATION "${CMAKE_SOURCE_DIR}/../qt_cmake_install"
)

add_custom_command(
        TARGET ${EXECUTABLE} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/qt_cmake.sh
        ${CMAKE_CURRENT_BINARY_DIR}/${EXECUTABLE}.sh)