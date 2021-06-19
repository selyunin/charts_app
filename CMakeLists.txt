cmake_minimum_required(VERSION 3.17)

set(EXECUTABLE app)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})

project(${EXECUTABLE})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(WIN32)
    set(QT_PATH C:/Qt/5.15.2/mingw81_64/)
elseif(UNIX)
    set(QT_PATH /opt/Qt/5.15.2/gcc_64/)
endif()

set(CMAKE_PREFIX_PATH ${QT_PATH})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5.15.2)

if(WIN32)
    set(QT_WIN_COMPONENTS Core Gui DBus Widgets Charts)
    find_package(Qt5 ${QT_VERSION} EXACT REQUIRED COMPONENTS ${QT_WIN_COMPONENTS})
elseif(UNIX)
    find_package(Qt5 ${QT_VERSION} EXACT REQUIRED COMPONENTS Core Gui DBus Widgets Charts XcbQpa Test)
endif()

include_directories(src
        src/sdb_widgets
        src/sdb_settings
        )

add_executable(${EXECUTABLE} WIN32
        src/main.cpp
        src/sdb_settings/SdbJsonConfig.cpp
        src/sdb_settings/SdbSettingsChart.cpp
        src/sdb_settings/SdbSettingsChartWindow.cpp
        src/sdb_settings/SdbSettingsSeries.cpp
        src/sdb_widgets/SdbAppControlWidget.cpp
        src/sdb_widgets/SdbButton.cpp
        src/sdb_widgets/SdbChart.cpp
        src/sdb_widgets/SdbChartControlPanel.cpp
        src/sdb_widgets/SdbChartController.cpp
        src/sdb_widgets/SdbChartWidget.cpp
        src/sdb_widgets/SdbChartView.cpp
        src/sdb_widgets/SdbMainWindow.cpp
        src/sdb_widgets/SdbRadioButton.cpp
        )

add_executable(test WIN32
        test/test_gui.cpp
        src/chartview.cpp
        src/sdb_widgets/SdbMainWindow.cpp)

find_library(LIBRARY_NAME PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)

if(WIN32)
    target_link_libraries(${EXECUTABLE} Qt5::Core Qt5::Gui Qt5::Widgets Qt5::DBus Qt5::Charts)
    target_link_libraries(test Qt5::Core Qt5::Gui Qt5::Widgets Qt5::DBus Qt5::Charts Qt5::Test)
elseif(UNIX)
    target_link_libraries(${EXECUTABLE} Qt5::Core Qt5::Gui Qt5::Widgets Qt5::DBus Qt5::Charts Qt5::XcbQpa)
    target_link_libraries(test Qt5::Core Qt5::Gui Qt5::Widgets Qt5::DBus Qt5::Charts Qt5::XcbQpa Qt5::Test)
endif()

if(WIN32)
    set(PACKAGE_DIR "${CMAKE_SOURCE_DIR}/../charts_app_win")
elseif(UNIX)
    set(PACKAGE_DIR "${CMAKE_SOURCE_DIR}/../charts_app_linux")
endif()

if(WIN32)
    include(${CMAKE_SOURCE_DIR}/cmake/post_build_win32.cmake)
    post_build_win32(${PACKAGE_DIR} ${EXECUTABLE})
elseif(UNIX)
    include(${CMAKE_SOURCE_DIR}/cmake/post_build_linux.cmake)
    post_build_linux()
endif()

if(WIN32)
    include(${CMAKE_SOURCE_DIR}/cmake/install_win32.cmake)
    install_win32()
elseif(UNIX)
    include(${CMAKE_SOURCE_DIR}/cmake/install_linux.cmake)
    install_linux()
endif()