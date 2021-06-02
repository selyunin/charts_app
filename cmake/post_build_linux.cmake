function(post_build_linux)
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

    add_custom_command(
            TARGET ${EXECUTABLE} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${QT_PATH}/lib/libQt5XcbQpa.so
            ${PACKAGE_DIR}/libQt5XcbQpa.so.5)

    add_custom_command(
            TARGET ${EXECUTABLE} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${QT_PATH}/lib/libQt5DBus.so
            ${PACKAGE_DIR}/libQt5DBus.so.5)

    add_custom_command(
            TARGET ${EXECUTABLE} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            /usr/lib/x86_64-linux-gnu/libxcb-xinerama.so.0
            ${PACKAGE_DIR}/libxcb-xinerama.so.0)

endfunction()