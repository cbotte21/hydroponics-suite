if (TARGET tinyusb_device)
    add_executable(valve_controller)

    pico_generate_pio_header(valve_controller ${CMAKE_CURRENT_LIST_DIR}/valve_controller.pio)

    target_sources(valve_controller PRIVATE
            valve_controller.cpp
            io/AnalogIO.cpp
            )

    # pull in common dependencies
    target_link_libraries(valve_controller pico_stdlib hardware_pio)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(valve_controller 1)
    pico_enable_stdio_uart(valve_controller 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(valve_controller)

    # add url via pico_set_program_url
    hydroponic_suite_auto_set_url(valve_controller)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()



