function(install_linux)

    install(CODE [[
        include(BundleUtilities)
        fixup_bundle("${CMAKE_BINARY_DIR}/app" "" "")
        ]] COMPONENT Runtime
            )

    install(CODE [[
        include(BundleUtilities)
        copy_and_fixup_bundle("${CMAKE_BINARY_DIR}/app" "${CMAKE_BINARY_DIR}/../../qt_port/app" "" "")
        ]] COMPONENT Runtime
            )

endfunction()