if (TARGET tinyusb_device)
    add_executable(controller)

    pico_generate_pio_header(controller ${CMAKE_CURRENT_LIST_DIR}/controller.pio)

    target_sources(controller PRIVATE
            controller.cpp
            io/IO.h
            io/AnalogOutput.h
            io/TimedOutput.cpp
            controllers/LightController.cpp
            controllers/ValveController.cpp
            internal/CycleCalculator.cpp
            internal/Plant.cpp
            internal/ValveManager.cpp
            )

    # pull in common dependencies
    target_link_libraries(controller
            pico_stdlib
            hardware_pio
            )

    # enable usb output, disable uart output
    pico_enable_stdio_usb(controller 1)
    pico_enable_stdio_uart(controller 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(controller)

    # add url via pico_set_program_url
    hydroponic_suite_auto_set_url(controller)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()



