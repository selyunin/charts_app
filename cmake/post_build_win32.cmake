function(post_build_win32)
    foreach(QT_LIB IN LISTS QT_WIN_COMPONENTS)
        add_custom_command(
                TARGET ${EXECUTABLE} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${QT_PATH}/bin/Qt5${QT_LIB}.dll
                ${CMAKE_BINARY_DIR})
    endforeach()

    set(ADDITIONAL_WIN_LIBRARIES libgcc_s_seh-1.dll libstdc++-6.dll libwinpthread-1.dll)
    foreach(WIN_LIB IN LISTS ADDITIONAL_WIN_LIBRARIES)
        add_custom_command(
                TARGET ${EXECUTABLE} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${QT_PATH}/bin/${WIN_LIB}
                ${CMAKE_BINARY_DIR})
    endforeach()

    add_custom_command(
            TARGET ${EXECUTABLE} PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory
            ${CMAKE_BINARY_DIR}/platforms)

    add_custom_command(
            TARGET ${EXECUTABLE} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${QT_PATH}/plugins/platforms/qwindows.dll
            ${CMAKE_BINARY_DIR}/platforms/)

endfunction()