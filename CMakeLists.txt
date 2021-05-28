cmake_minimum_required(VERSION 3.17)

set(EXECUTABLE app)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})

project(${EXECUTABLE})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_PATH /opt/Qt/5.15.2/gcc_64/)
set(CMAKE_PREFIX_PATH ${QT_PATH})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5.15.2)


find_package(Qt5 ${QT_VERSION} EXACT REQUIRED COMPONENTS Widgets Core Charts DBus XcbQpa)

add_executable(${EXECUTABLE}
               main.cpp
               chartview.cpp
               SdbMainWindow.cpp)

find_library(LIBRARY_NAME PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)

target_link_libraries(${EXECUTABLE} Qt5::Widgets Qt5::Charts Qt5::DBus Qt5::XcbQpa)

set(PACKAGE_DIR "${CMAKE_SOURCE_DIR}/../qt_port")

add_custom_command(
        TARGET ${EXECUTABLE} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
        ${PACKAGE_DIR}/plugins/platforms)

add_custom_command(
        TARGET ${EXECUTABLE} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/qt_cmake.sh
        ${PACKAGE_DIR}/${EXECUTABLE}.sh)

add_custom_command(
        TARGET ${EXECUTABLE} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_BINARY_DIR}/${EXECUTABLE}
        ${PACKAGE_DIR}/${EXECUTABLE})

add_custom_command(
        TARGET ${EXECUTABLE} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${QT_PATH}/plugins/platforms
        ${PACKAGE_DIR}/plugins/platforms)


install(CODE [[
    include(BundleUtilities)
    fixup_bundle("${CMAKE_BINARY_DIR}/app" "" "")
    ]] COMPONENT Runtime
        )


install(CODE [[
    include(BundleUtilities)
    copy_and_fixup_bundle("${CMAKE_BINARY_DIR}/app" "/home/selyunin/workspace/github/qt_port/app" "" "")
    ]] COMPONENT Runtime
        )
