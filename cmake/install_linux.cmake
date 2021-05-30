function(install_linux)

    install(CODE [[
        include(BundleUtilities)
        fixup_bundle("${CMAKE_BINARY_DIR}/app.exe" "" "")
        ]] COMPONENT Runtime
            )

    install(CODE [[
        include(BundleUtilities)
        copy_and_fixup_bundle("${CMAKE_BINARY_DIR}/app.exe" "${CMAKE_BINARY_DIR}/../../qt_port/app.exe" "" "")
        ]] COMPONENT Runtime
            )

endfunction()