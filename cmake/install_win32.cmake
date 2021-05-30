function(install_win32)
    set(CMAKE_GET_RUNTIME_DEPENDENCIES_TOOL objdump)
    install(CODE [[
        include(BundleUtilities)
        fixup_bundle("${CMAKE_BINARY_DIR}/app.exe" "" "")
        ]] COMPONENT Runtime
            )
endfunction()