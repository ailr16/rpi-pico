add_library(lib_template template.c)
target_link_libraries(lib_template
    pico_stdlib
)
include_directories(${CMAKE_SOURCE_DIR}/inc)

add_executable(bin_template main.c)

pico_enable_stdio_usb(bin_template 1)
pico_enable_stdio_uart(bin_template 0)

pico_add_extra_outputs(bin_template)

target_link_libraries(bin_template
    lib_template
    pico_stdlib
)
