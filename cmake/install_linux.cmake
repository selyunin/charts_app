function(install_linux)

    install(CODE [[
        include(BundleUtilities)
        fixup_bundle("${CMAKE_CURRENT_BINARY_DIR}/app" "" "")
        ]] COMPONENT Runtime
            )

    install(CODE [[
        include(BundleUtilities)
        copy_and_fixup_bundle("${CMAKE_CURRENT_BINARY_DIR}/app" "${CMAKE_CURRENT_BINARY_DIR}/../../charts_app_linux/app" "" "")
        ]] COMPONENT Runtime
            )

endfunction()